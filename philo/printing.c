/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papa <papa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:35:03 by mankestark        #+#    #+#             */
/*   Updated: 2023/06/30 11:36:58 by papa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

//	hace el print
static void	print_status(t_philo *philo, char *str)
{
	printf("%ld %d %s\n", get_time_in_ms() - philo->data->start_time,
		philo->id + 1, str);
}

//	imprime el estado del fisolofo y evita la sobreimpresion
void	write_status(t_philo *philo, bool reaper_report, t_status status)
{
	pthread_mutex_lock(&philo->data->write_lock);
	if (has_simulation_stopped(philo->data) == true && reaper_report == false)
	{
		pthread_mutex_unlock(&philo->data->write_lock);
		return ;
	}
	if (status == DIED)
		print_status(philo, "died");
	else if (status == EATING)
		print_status(philo, "is eating");
	else if (status == SLEEPING)
		print_status(philo, "is sleeping");
	else if (status == THINKING)
		print_status(philo, "is thinking");
	else if (status == GOT_FORK_1 || status == GOT_FORK_2)
		print_status(philo, "has taken a fork");
	pthread_mutex_unlock(&philo->data->write_lock);
}
