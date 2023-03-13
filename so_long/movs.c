/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mankestarkdev <mankestarkdev@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 07:48:07 by mankestarkd       #+#    #+#             */
/*   Updated: 2023/01/13 07:30:51 by mankestarkd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	move_left(t_data *data)
{
	data->map.mtx[data->img.pos.y][data->img.pos.x] = '0';
	data->img.pos.x -= 1;
	data->map.mtx[data->img.pos.y][data->img.pos.x] = 'P';
	data->game.count_steps++;
	return (0);
}

int	move_right(t_data *data)
{
	data->map.mtx[data->img.pos.y][data->img.pos.x] = '0';
	data->img.pos.x += 1;
	data->map.mtx[data->img.pos.y][data->img.pos.x] = 'P';
	data->game.count_steps++;
	return (0);
}

int	move_down(t_data *data)
{
	data->map.mtx[data->img.pos.y][data->img.pos.x] = '0';
	data->img.pos.y += 1;
	data->map.mtx[data->img.pos.y][data->img.pos.x] = 'P';
	data->game.count_steps++;
	return (0);
}

int	move_up(t_data *data)
{
	data->map.mtx[data->img.pos.y][data->img.pos.x] = '0';
	data->img.pos.y -= 1;
	data->map.mtx[data->img.pos.y][data->img.pos.x] = 'P';
	data->game.count_steps++;
	return (0);
}

int	movements(int key, t_data *data)
{
	if ((key == A_KEY)
		&& (data->map.mtx[data->img.pos.y][data->img.pos.x - 1] == 'E'))
		check_collect(data);
	else if ((key == A_KEY)
		&& (data->map.mtx[data->img.pos.y][data->img.pos.x - 1] != '1'))
		move_left(data);
	if ((key == D_KEY)
		&& (data->map.mtx[data->img.pos.y][data->img.pos.x + 1] == 'E'))
		check_collect(data);
	else if ((key == D_KEY)
		&& (data->map.mtx[data->img.pos.y][data->img.pos.x + 1] != '1'))
		move_right(data);
	if ((key == S_KEY)
		&& (data->map.mtx[data->img.pos.y + 1][data->img.pos.x] == 'E'))
		check_collect(data);
	else if ((key == S_KEY)
		&& (data->map.mtx[data->img.pos.y + 1][data->img.pos.x] != '1'))
		move_down(data);
	if ((key == W_KEY)
		&& (data->map.mtx[data->img.pos.y - 1][data->img.pos.x] == 'E'))
		check_collect(data);
	else if ((key == W_KEY)
		&& (data->map.mtx[data->img.pos.y - 1][data->img.pos.x] != '1'))
		move_up(data);
	return (0);
}
