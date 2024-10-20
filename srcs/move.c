/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarian <lemarian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:11:01 by lemarian          #+#    #+#             */
/*   Updated: 2024/10/19 13:48:50 by lemarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_target(t_data *data, size_t x, size_t y)
{
	if (data->map[y][x] == WALL)
		return ;
	else if (data->map[y][x] == OBJECT)
		data->collected++;
	else if (data->map[y][x] == EXIT)
	{
		if (data->collected != data->collectibles)
			data->map[y][x] = 'Q';
		else
			victory_message(data);
	}
	if (data->map[data->p_pos.y][data->p_pos.x] != 'E')
		data->map[data->p_pos.y][data->p_pos.x] = 'Z';
	data->p_pos = (t_pos){x, y};
	redraw_map(data);
	print_moves(data);
}

int	action(int keycode, t_data *data)
{
	if (keycode == 65307)
		free_everything(data);
	if (keycode == UP || keycode == W)
		check_target(data, data->p_pos.x, data->p_pos.y - 1);
	else if (keycode == LEFT || keycode == A)
		check_target(data, data->p_pos.x - 1, data->p_pos.y);
	else if (keycode == DOWN || keycode == S)
		check_target(data, data->p_pos.x, data->p_pos.y + 1);
	else if (keycode == RIGHT || keycode == D)
		check_target(data, data->p_pos.x + 1, data->p_pos.y);
	return (0);
}
