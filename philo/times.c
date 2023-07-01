/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   times.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariza <mariza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 09:30:04 by mariza            #+#    #+#             */
/*   Updated: 2023/06/29 11:18:09 by mariza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

time_t	get_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

//sincroniza el inicio de los hilos 
void	sim_start_delay(time_t start_time)
{
	while (get_time_in_ms() < start_time)
		continue ;
}

//	hace una pausa para hacer las diferentes tareas
//	comprueba si la simulacion ha terminado mientras duerme
void	philo_sleep(t_lunch *data, time_t sleep_time)
{
	time_t	up;

	up = get_time_in_ms() + sleep_time;
	while (get_time_in_ms() < up)
	{
		if (has_simulation_stopped(data))
			break ;
		usleep(100);
	}
}
