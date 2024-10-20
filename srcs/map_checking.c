/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarian <lemarian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:21:56 by lemarian          #+#    #+#             */
/*   Updated: 2024/10/19 13:48:39 by lemarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_data(t_data *data)
{
	if (data->collectibles < 1)
		print_error("Map needs at least one collectible", data);
	if (data->exit != 1)
		print_error("Map needs one exit", data);
	if (data->player != 1)
		print_error("Map needs one player start position", data);
}

void	check_walls(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < data->height)
	{
		if (i == 0 || i == (data->height - 1))
		{
			j = 0;
			while (data->map[i][j])
			{
				if (data->map[i][j] != '1')
					print_error("Map should be surrounded by walls", data);
				j++;
			}
		}
		if (data->map[i][0] != '1' || data->map[i][(data->width - 1)] != '1')
			print_error("Map should be surrounded by walls", data);
		i++;
	}
}

void	check_shape(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (data->map[i][j])
		j++;
	data->width = j;
	j = 0;
	while (i < data->height)
	{
		j = 0;
		while (data->map[i][j])
			j++;
		if (j != data->width)
			print_error("Map should be rectangular", data);
		i++;
	}
}

void	check_content(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		if (!data->map[i])
			print_error("Invalid map content", data);
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				data->collectibles++;
			else if (data->map[i][j] == 'E')
				data->exit++;
			else if (data->map[i][j] == 'P')
				data->player++;
			else if (data->map[i][j] != '0' && data->map[i][j] != '1')
				print_error("Invalid map content", data);
			j++;
		}
		i++;
	}
}

void	check_map(t_data *data)
{
	check_content(data);
	check_data(data);
	check_shape(data);
	check_walls(data);
}
