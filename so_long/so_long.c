/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macpapa <macpapa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 02:48:58 by mankestarkd       #+#    #+#             */
/*   Updated: 2023/02/25 12:16:38 by macpapa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	init(t_data *data)
{
	data->map.mtx = malloc((data->map.size.y + 1) * sizeof(char *));
	data->map.mtx[data->map.size.y] = NULL;
	data->game.count_steps = 0;
	return (0);
}

int	check_args(int argc, char **argv)
{
	if (argc < 2)
		error("Falta mapa como argumento, usa: map.ber\n");
	if (argc > 2)
		error("Sobran argumentos, usa solo: map.ber\n");
	if (ft_strstr(argv[1], ".ber") == NULL)
		error("Extension invalida, usa: .ber\n");
	return (0);
}

int	ft_expose(t_data *data)
{
	print_map(*data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	check_args(argc, argv);
	get_x_y(&data, argv);
	init(&data);
	get_map(&data, argv);
	if (check_floodfill(&data))
		error("No hay camino posible\n");
	else
	{
		get_x_y(&data, argv);
		init(&data);
		get_map(&data, argv);
	}
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.map.size.x * SPRITE_W,
			data.map.size.y * SPRITE_H, "So long");
	get_init_position(&data);
	count_collec(&data);
	print_map(data);
	mlx_hook(data.win, X_EVENT_KEY_PRESS, 1L << 0, key_press, &data);
	mlx_hook(data.win, X_EVENT_KEY_EXIT, 1L << 0, mlx_close, &data);
	mlx_expose_hook(data.win, ft_expose, &data);
	mlx_loop(data.mlx);
}
