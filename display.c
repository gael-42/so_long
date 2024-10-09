/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarian <lemarian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:53:30 by lemarian          #+#    #+#             */
/*   Updated: 2024/10/07 14:24:54 by lemarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_sprites(t_data *data)
{
	int	i_w;
	int	i_h;

	data->i_floor = mlx_xpm_file_to_image(data->mlx,
			"./assets/floor.xpm", &i_w, &i_h);
	data->i_wall = mlx_xpm_file_to_image(data->mlx,
			"./assets/wall.xpm", &i_w, &i_h);
	data->i_obj = mlx_xpm_file_to_image(data->mlx,
			"./assets/collectible.xpm", &i_w, &i_h);
	data->i_player = mlx_xpm_file_to_image(data->mlx,
			"./assets/player.xpm", &i_w, &i_h);
	data->i_exit = mlx_xpm_file_to_image(data->mlx,
			"./assets/exit.xpm", &i_w, &i_h);
	data->i_front = mlx_xpm_file_to_image(data->mlx,
			"./assets/front.xpm", &i_w, &i_h);
	if (!data->i_front || !data->i_floor || ! data->i_wall
		|| !data->i_obj || !data->i_player || !data->i_exit)
		print_error("Failed to load assets", data);
}

void	draw_image(t_data *data, void *image, size_t x, size_t y)
{
	mlx_put_image_to_window(data->mlx, data->win, image, x, y);
}

void	redraw_map(t_data *data)
{
	size_t	y;
	size_t	x;

	y = -1;
	while (++y < data->height)
	{
		x = 0;
		while (x++ < data->width)
		{
			if (data->map[y][x] == 'Z')
			{
				draw_image(data, data->i_floor, x * 64, y * 64);
				data->map[y][x] = '0';
			}
			else if (data->map[y][x] == 'Q')
			{
				draw_image(data, data->i_front, x * 64, y * 64);
				data->map[y][x] = 'E';
			}
			else if (x == data->p_pos.x && y == data->p_pos.y)
				draw_image(data, data->i_player, x * 64, y * 64);
			else if (data->map[y][x] == 'E')
				draw_image(data, data->i_exit, x * 64, y * 64);
		}
	}
}

void	display_map(t_data *data)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (data->map[y][x] == FLOOR)
				draw_image(data, data->i_floor, x * 64, y * 64);
			else if (data->map[y][x] == WALL)
				draw_image(data, data->i_wall, x * 64, y * 64);
			else if (data->map[y][x] == OBJECT)
				draw_image(data, data->i_obj, x * 64, y * 64);
			else if (data->map[y][x] == PLAYER)
				draw_image(data, data->i_player, x * 64, y * 64);
			else if (data->map[y][x] == EXIT)
				draw_image(data, data->i_exit, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

void	load_map(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		print_error("Failed to initialize Minilibx", data);
	load_sprites(data);
	data->win = mlx_new_window(data->mlx, data->width * 64,
			data->height * 64, "Mushroom Hunt");
	if (!data->win)
		print_error("Failed to create window", data);
	ft_printf("You found a cave. ");
	ft_printf("Collect all the mushrooms to unlock the exit\n");
	display_map(data);
	mlx_hook(data->win, 17, 0, &close_game, data);
	mlx_hook(data->win, 02, (1L << 0), &action, data);
	mlx_loop(data->mlx);
}
