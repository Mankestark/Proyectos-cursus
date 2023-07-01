/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariza <mariza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 09:18:59 by mankestarkd       #+#    #+#             */
/*   Updated: 2023/06/29 14:37:22 by mariza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

//inicia los mutex a los tenedores
static pthread_mutex_t	*init_forks(t_lunch *data)
{
	pthread_mutex_t	*forks;
	unsigned int	i;

	forks = malloc(sizeof(pthread_mutex_t) * data->nb_philos);
	if (!forks)
		return (error_init(ERROR_MALLOC, NULL, 0));
	i = 0;
	while (i < data->nb_philos)
	{
		if (pthread_mutex_init(&forks[i], 0) != 0)
			return (error_init(ERROR_MUTEX, NULL, 0));
		i++;
	}
	return (forks);
}

//asignando tenedores se asigna diferente en caso de
//que el numero de filos sean pares o impares
static void	asig_forks(t_philo *philo)
{
	philo->fork[0] = philo->id;
	philo->fork[1] = (philo->id + 1) % philo->data->nb_philos;
	if (philo->id % 2)
	{
		philo->fork[0] = (philo->id + 1) % philo->data->nb_philos;
		philo->fork[1] = philo->id;
	}
}

//reserva memoria para cada filosofo e inicia el mutex con el tiempo
//maximo de comida
//aqui se va asignando los tenedores
static t_philo	**init_philosophers(t_lunch *data)
{
	t_philo			**philos;
	unsigned int	i;

	philos = malloc(sizeof(t_philo) * data->nb_philos);
	if (!philos)
		return (error_init(ERROR_MALLOC, NULL, 0));
	i = 0;
	while (i < data->nb_philos)
	{
		philos[i] = malloc(sizeof(t_philo) * 1);
		if (!philos[i])
			return (error_init(ERROR_MALLOC, NULL, 0));
		if (pthread_mutex_init(&philos[i]->meal_time_lock, 0) != 0)
			return (error_init(ERROR_MUTEX, NULL, 0));
		philos[i]->data = data;
		philos[i]->id = i;
		philos[i]->times_ate = 0;
		asig_forks(philos[i]);
		i++;
	}
	return (philos);
}

static bool	init_mutexes(t_lunch *data)
{
	data->fork_locks = init_forks(data);
	if (!data->fork_locks)
		return (false);
	if (pthread_mutex_init(&data->sim_stop_lock, 0) != 0)
		return (error_mem(ERROR_MUTEX, NULL, data));
	if (pthread_mutex_init(&data->write_lock, 0) != 0)
		return (error_mem(ERROR_MUTEX, NULL, data));
	return (true);
}

//incia la estructura data
t_lunch	*init_lunch(int ac, char **av, int i)
{
	t_lunch	*data;

	data = malloc(sizeof(t_lunch) * 1);
	if (!data)
		return (error_init(ERROR_MALLOC, NULL, 0));
	data->nb_philos = int_atoi(av[i++]);
	data->time_to_die = int_atoi(av[i++]);
	data->time_to_eat = int_atoi(av[i++]);
	data->time_to_sleep = int_atoi(av[i++]);
	data->must_eat_count = -1;
	if (ac - 1 == 5)
		data->must_eat_count = int_atoi(av[i]);
	data->philos = init_philosophers(data);
	if (!data->philos)
		return (NULL);
	if (!init_mutexes(data))
		return (NULL);
	data->sim_stop = false;
	return (data);
}
