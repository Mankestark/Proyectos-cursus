/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lunch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariza <mariza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 09:28:04 by mariza            #+#    #+#             */
/*   Updated: 2023/06/29 10:23:07 by mariza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

//el filosofo espera a que el tenedor este desbloqueado
// come por el tiempo indicado

static void	eat_sleep_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->fork_locks[philo->fork[0]]);
	write_status(philo, false, GOT_FORK_1);
	pthread_mutex_lock(&philo->data->fork_locks[philo->fork[1]]);
	write_status(philo, false, GOT_FORK_2);
	write_status(philo, false, EATING);
	pthread_mutex_lock(&philo->meal_time_lock);
	philo->last_meal = get_time_in_ms();
	pthread_mutex_unlock(&philo->meal_time_lock);
	philo_sleep(philo->data, philo->data->time_to_eat);
	if (has_simulation_stopped(philo->data) == false)
	{
		pthread_mutex_lock(&philo->meal_time_lock);
		philo->times_ate += 1;
		pthread_mutex_unlock(&philo->meal_time_lock);
	}
	write_status(philo, false, SLEEPING);
	pthread_mutex_unlock(&philo->data->fork_locks[philo->fork[1]]);
	pthread_mutex_unlock(&philo->data->fork_locks[philo->fork[0]]);
	philo_sleep(philo->data, philo->data->time_to_sleep);
}

//se calcula el tiempo para pensar en funcion del tiempo para morir
//el tiempo de la ultima comida y el tiempo para comer
//bloquea el mutex para coger la informacion

static void	think_routine(t_philo *philo, bool silent)
{
	time_t	time_to_think;

	pthread_mutex_lock(&philo->meal_time_lock);
	time_to_think = (philo->data->time_to_die
			- (get_time_in_ms() - philo->last_meal)
			- philo->data->time_to_eat) / 2;
	pthread_mutex_unlock(&philo->meal_time_lock);
	if (time_to_think < 0)
		time_to_think = 0;
	if (time_to_think == 0 && silent == true)
		time_to_think = 1;
	if (time_to_think > 600)
		time_to_think = 200;
	if (silent == false)
		write_status(philo, false, THINKING);
	philo_sleep(philo->data, time_to_think);
}

//esta rutina sirve para cuando hay un solo filo, espera y se muere
//bloquea el mutex para iniciar la rutina
//comprueba que cuando duerme no muere
static void	*lone_philo_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->fork_locks[philo->fork[0]]);
	write_status(philo, false, GOT_FORK_1);
	philo_sleep(philo->data, philo->data->time_to_die);
	write_status(philo, false, DIED);
	pthread_mutex_unlock(&philo->data->fork_locks[philo->fork[0]]);
	return (NULL);
}

//comprobacion de que el tiempo maximo de comidas es correcto
//bloquea el mutex para empezar a comer
//inicia el tiempo de cuando come el filosofo
//sincroniza el tiempo de comer con el de la simulacion
//comprueba que no muere mientras duerme
//los filosofos que son pares empiezan por pensar
//y los impares cogen el tenedor primero asi no se solapan
void	*philosopher(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->data->must_eat_count == 0)
		return (NULL);
	pthread_mutex_lock(&philo->meal_time_lock);
	philo->last_meal = philo->data->start_time;
	pthread_mutex_unlock(&philo->meal_time_lock);
	sim_start_delay(philo->data->start_time);
	if (philo->data->time_to_die == 0)
		return (NULL);
	if (philo->data->nb_philos == 1)
		return (lone_philo_routine(philo));
	else if (philo->id % 2)
		think_routine(philo, true);
	while (has_simulation_stopped(philo->data) == false)
	{
		eat_sleep_routine(philo);
		think_routine(philo, false);
	}
	return (NULL);
}
