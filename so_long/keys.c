/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mankestarkdev <mankestarkdev@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 07:34:47 by mankestarkd       #+#    #+#             */
/*   Updated: 2023/01/13 07:58:57 by mankestarkd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	mlx_close(t_data *data)
{
	free_exit(data, "Juego cerrado\n");
	return (0);
}

int	key_press(int key, t_data *data)
{
	int	init_steps;

	init_steps = data->game.count_steps;
	if (key == ESC)
	{
		free_exit(data, "Juego cerrado\n");
	}
	else
	{
		movements(key, data);
	}
	if (init_steps != data->game.count_steps)
		ft_printf("Pasos: %d\n", data->game.count_steps);
	print_map(*data);
	return (0);
}
