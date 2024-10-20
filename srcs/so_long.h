/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarian <lemarian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 14:51:07 by lemarian          #+#    #+#             */
/*   Updated: 2024/10/14 12:23:36 by lemarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../new_libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define WALL '1'
# define FLOOR '0'
# define PLAYER 'P'
# define EXIT 'E'
# define OBJECT 'C'

# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363

# define W 119
# define A 97
# define S 115
# define D 100

typedef struct s_pos
{
	size_t	x;
	size_t	y;
}	t_pos;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*i_floor;
	void	*i_player;
	void	*i_obj;
	void	*i_exit;
	void	*i_wall;
	void	*i_front;

	char	**map;
	size_t	width;
	size_t	height;

	int		collectibles;
	int		exit;
	int		player;

	char	**grid;
	bool	found_exit;
	int		c_found;

	t_pos	p_pos;
	int		collected;
	int		moves;
}	t_data;

void	init_data(t_data *data);
void	print_error(char *error, t_data *data);
void	free_everything(t_data *data);
void	free_map(char **map);
void	parse(int ac, char **av, t_data *data);
void	check_map(t_data *data);
void	check_path(t_data *data);
void	copy_map(t_data *data);
void	load_map(t_data *data);
int		close_game(t_data *data);
int		action(int keycode, t_data *data);
void	redraw_map(t_data *data);
void	victory_message(t_data *data);
void	print_moves(t_data *data);
#endif
