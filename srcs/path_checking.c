/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarian <lemarian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 14:05:20 by lemarian          #+#    #+#             */
/*   Updated: 2024/10/07 13:55:06 by lemarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_positions(t_data *data)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (data->grid[y][x] == 'P')
			{
				data->p_pos.x = x;
				data->p_pos.y = y;
			}
			x++;
		}
		y++;
	}
}

void	search_path(t_data *data, size_t x, size_t y)
{
	if (x > data->width || y > data->height || x < 0 || y < 0)
		return ;
	if (data->grid[y][x] == WALL || data->grid[y][x] == 'Z')
		return ;
	if (data->grid[y][x] == EXIT)
		data->found_exit = true;
	if (data->grid[y][x] == OBJECT)
		data->c_found++;
	data->grid[y][x] = 'Z';
	search_path(data, (x + 1), y);
	search_path(data, (x - 1), y);
	search_path(data, x, (y + 1));
	search_path(data, x, (y - 1));
}

void	check_path(t_data *data)
{
	copy_map(data);
	get_positions(data);
	search_path(data, data->p_pos.x, data->p_pos.y);
	if (!data->found_exit || data->c_found != data->collectibles)
		print_error("No valid path found", data);
}
