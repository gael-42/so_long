/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarian <lemarian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 14:57:08 by lemarian          #+#    #+#             */
/*   Updated: 2024/10/12 15:28:29 by lemarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(char *error, t_data *data)
{
	ft_printf("Error\n%s\n", error);
	free_everything(data);
	exit (EXIT_FAILURE);
}

void	free_images(t_data *data)
{
	if (data->i_exit)
		mlx_destroy_image(data->mlx, data->i_exit);
	if (data->i_floor)
		mlx_destroy_image(data->mlx, data->i_floor);
	if (data->i_obj)
		mlx_destroy_image(data->mlx, data->i_obj);
	if (data->i_player)
		mlx_destroy_image(data->mlx, data->i_player);
	if (data->i_wall)
		mlx_destroy_image(data->mlx, data->i_wall);
	if (data->i_front)
		mlx_destroy_image(data->mlx, data->i_front);
}

void	free_map(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	free_everything(t_data *data)
{
	if (data)
	{
		if (data->map)
			free_map(data->map);
		if (data->grid)
			free_map(data->grid);
		if (data->i_exit || data->i_floor || data->i_obj
			|| data->i_player || data->i_wall)
			free_images(data);
		if (data->win)
		{
			mlx_destroy_window(data->mlx, data->win);
			data->win = NULL;
		}
		if (data->mlx)
		{
			mlx_destroy_display(data->mlx);
			free(data->mlx);
			data->mlx = NULL;
		}
	}
	exit(0);
}

int	close_game(t_data *data)
{
	free_everything(data);
	return (0);
}
