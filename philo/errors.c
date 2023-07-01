/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariza <mariza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 12:29:40 by mariza            #+#    #+#             */
/*   Updated: 2023/06/28 13:29:33 by mariza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

int	errormsg(char *str, char *det, int exitnumb)
{
	if (!det)
		printf(str, "philo");
	else
		printf(str, det);
	return (exitnumb);
}

void	*error_init(char *str, char *det, t_lunch *data)
{
	if (data != NULL)
		free_data(data);
	errormsg(str, det, EXIT_FAILURE);
	return (NULL);
}

int	error_mem(char *str, char *det, t_lunch *data)
{
	if (data != NULL)
		free_data(data);
	return (errormsg(str, det, 0));
}

void	*free_data(t_lunch *data)
{
	unsigned int	i;

	if (!data)
		return (NULL);
	if (data->fork_locks != NULL)
		free(data->fork_locks);
	if (data->philos != NULL)
	{
		i = 0;
		while (i < data->nb_philos)
		{
			if (data->philos[i] != NULL)
				free(data->philos[i]);
			i++;
		}
		free(data->philos);
	}
	free(data);
	return (NULL);
}

void	destroy_mutexes(t_lunch *data)
{
	unsigned int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		pthread_mutex_destroy(&data->fork_locks[i]);
		pthread_mutex_destroy(&data->philos[i]->meal_time_lock);
		i++;
	}
	pthread_mutex_destroy(&data->write_lock);
	pthread_mutex_destroy(&data->sim_stop_lock);
}
