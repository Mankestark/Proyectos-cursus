/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macpapa <macpapa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 00:17:02 by mankestarkd       #+#    #+#             */
/*   Updated: 2023/02/25 11:59:02 by macpapa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 1024
# define OPEN_MAX 255

# include "../libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <unistd.h>

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_EXIT 17

# if defined(__APPLE__) && defined(__MACH__)
#  define LEFT_KEY 123
#  define RIGHT_KEY 124
#  define UP_KEY 126
#  define DOWN_KEY 125
#  define A_KEY 0
#  define S_KEY 1
#  define D_KEY 2
#  define W_KEY 13
#  define ESC 53

# else
#  define LEFT_KEY 65361
#  define RIGHT_KEY 65363
#  define UP_KEY 65362
#  define DOWN_KEY 65364
#  define A_KEY 97
#  define W_KEY 119
#  define S_KEY 115
#  define D_KEY 100
#  define ESC 65307
# endif

# define SPRITE_H 64
# define SPRITE_W 64

typedef struct s_pos
{
	int		x;
	int		y;
}			t_pos;

typedef struct s_img
{
	void	*img_ptr;
	t_pos	size;
	t_pos	pos;
	int		*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_map
{
	char	**mtx;
	t_pos	size;
}			t_map;

typedef struct s_game
{
	int		count_collec;
	int		count_steps;
}			t_game;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_game	game;
	t_map	map;
}			t_data;

int			init(t_data *data);
void		*ft_strcpy_gnl(char *dst, char *src, size_t n);
int			check_map(t_data data);
int			error(char *msg);
int			load_map(t_data data, int row, int col);
int			get_x_y(t_data *data, char **argv);
int			get_map(t_data *data, char **argv);
int			print_map(t_data data);
int			key_press(int key, t_data *data);
int			mlx_close(t_data *data);
int			get_map_x(t_data data);
int			get_map_y(t_data data);
int			check_map(t_data data);
int			get_init_position(t_data *data);
int			count_collec(t_data *data);
int			check_collect(t_data *data);
int			movements(int key, t_data *data);
int			free_map(t_data *data);
int			free_exit(t_data *data, char *msg);
int			check_args(int argc, char **argv);
char		*ft_strstr(char *haystack, char *needle);
int			ft_gnl(int fd, char **line);
int			check_floodfill(t_data *data);
#endif
