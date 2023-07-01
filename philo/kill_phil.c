/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_phil.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papa <papa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 07:25:51 by mankestarkd       #+#    #+#             */
/*   Updated: 2023/06/30 10:59:20 by papa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

//establece la condicion para que se pare la simulacion
static void	set_sim_stop_flag(t_lunch *data, bool state)
{
	pthread_mutex_lock(&data->sim_stop_lock);
	data->sim_stop = state;
	pthread_mutex_unlock(&data->sim_stop_lock);
}

//comprueba que la simulacion ha llegado a su fin
bool	has_simulation_stopped(t_lunch *data)
{
	bool	r;

	r = false;
	pthread_mutex_lock(&data->sim_stop_lock);
	if (data->sim_stop == true)
		r = true;
	pthread_mutex_unlock(&data->sim_stop_lock);
	return (r);
}

//	se comprueba si el filosofo debe morir segun el tiempo de comida dado
//	y detiene la simulacion,
static bool	dead_philo(t_philo *philo)
{
	time_t	time;

	time = get_time_in_ms();
	if ((time - philo->last_meal) >= philo->data->time_to_die)
	{
		set_sim_stop_flag(philo->data, true);
		write_status(philo, true, DIED);
		pthread_mutex_unlock(&philo->meal_time_lock);
		return (true);
	}
	return (false);
}

//	comprueba cada filosofo para ver si cumple las condiciones para
//	detener la simulacion
static bool	end_condition_reached(t_lunch *data)
{
	unsigned int	i;
	int				all_ate_enough;

	all_ate_enough = true;
	i = 0;
	while (i < data->nb_philos)
	{
		pthread_mutex_lock(&data->philos[i]->meal_time_lock);
		if (dead_philo(data->philos[i]))
			return (true);
		if (data->must_eat_count != -1)
			if (data->philos[i]->times_ate < (unsigned int)data->must_eat_count)
				all_ate_enough = false;
		pthread_mutex_unlock(&data->philos[i]->meal_time_lock);
		i++;
	}
	if (data->must_eat_count != -1 && all_ate_enough == true)
	{
		set_sim_stop_flag(data, true);
		return (true);
	}
	return (false);
}

//	comprueba si un filosofo debe morir y si todos
//	comieron lo suficiente, si todo es correcto se detiene
//	la simulacion
void	*kill_phil(void *dat)
{
	t_lunch	*data;

	data = (t_lunch *)dat;
	if (data->must_eat_count == 0)
		return (NULL);
	set_sim_stop_flag(data, false);
	sim_start_delay(data->start_time);
	while (true)
	{
		if (end_condition_reached(data) == true)
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}
