/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarian <lemarian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:03:55 by lemarian          #+#    #+#             */
/*   Updated: 2024/10/12 15:28:47 by lemarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_pointers(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->i_exit = NULL;
	data->i_floor = NULL;
	data->i_front = NULL;
	data->i_obj = NULL;
	data->i_player = NULL;
	data->i_wall = NULL;
}

void	init_data(t_data *data)
{
	data->map = NULL;
	data->grid = NULL;
	data->width = 0;
	data->height = 1;
	data->collectibles = 0;
	data->exit = 0;
	data->player = 0;
	data->found_exit = false;
	data->c_found = 0;
	data->p_pos = (t_pos){0, 0};
	data->collected = 0;
	data->moves = 0;
	init_pointers(data);
}

void	copy_map(t_data *data)
{
	size_t	i;

	i = 0;
	data->grid = malloc(sizeof(char *) * (data->height + 1));
	if (!data->grid)
		print_error("Malloc failed, failed to check path", data);
	data->grid[data->height] = 0;
	while (i < data->height)
	{
		data->grid[i] = ft_strdup(data->map[i]);
		if (!data->grid[i])
		{
			free_map(data->grid);
			print_error("Malloc failed, failed to check path", data);
		}
		i++;
	}
}

void	print_moves(t_data *data)
{
	data->moves++;
	ft_printf("Moves: %d\n", data->moves);
}

void	victory_message(t_data *data)
{
	ft_printf("You win !\nTotal ");
	print_moves(data);
	ft_printf("Total mushrooms: %d\n", data->collectibles);
	if (data->collectibles > 9)
		ft_printf("Who needs that many mushrooms?\n");
	else if (data->collectibles == 1)
		ft_printf("That mushroom has eyes, is it edible?\n");
	else
		ft_printf("That was a nice mushroom hunt.\n");
	free_everything(data);
}
