/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macpapa <macpapa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:31:06 by macpapa           #+#    #+#             */
/*   Updated: 2023/02/25 12:17:02 by macpapa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	floodfill(t_data *data, int x, int y)
{
	if (x < 0 || y < 0 || x >= data->map.size.x || y >= data->map.size.y
		|| data->map.mtx[y][x] == '1' || data->map.mtx[y][x] == 'W')
		return ;
	data->map.mtx[y][x] = 'W';
	floodfill(data, x, y - 1);
	floodfill(data, x + 1, y);
	floodfill(data, x - 1, y);
	floodfill(data, x, y + 1);
	return ;
}

int	browse_p(t_data *data)
{
	int		row;
	int		col;

	row = 0;
	while (row < data->map.size.y)
	{
		col = 0;
		while (col <= data->map.size.x)
		{
			if (data->map.mtx[row][col] == 'P')
			{
				data->img.pos.x = col;
				data->img.pos.y = row;
			}
			col++;
		}
		row++;
	}
	return (0);
}

int	checks(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map.size.y)
	{
		x = 0;
		while (x < data->map.size.x)
		{
			if (data->map.mtx[y][x] == 'C'
				|| data->map.mtx[y][x] == 'P'
				|| data->map.mtx[y][x] == 'E')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int    check_floodfill(t_data *data)
{
	browse_p(data);
	floodfill(data, data->img.pos.x, data->img.pos.y);
	if (checks(data) == 1)
		return (1);
	return (0);
}
