/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarian <lemarian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 14:54:26 by lemarian          #+#    #+#             */
/*   Updated: 2024/10/08 12:40:24 by lemarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*join_map(char *map, char *buffer, t_data *data)
{
	char	*join;

	join = ft_strjoin(map, buffer);
	free(map);
	free(buffer);
	if (!join)
		print_error("Failed to create map", data);
	return (join);
}

void	get_map(int fd, t_data *data)
{
	char	*map;
	char	*buffer;

	map = get_next_line(fd);
	if (!map)
		print_error("Failed to read map", data);
	buffer = get_next_line(fd);
	while (buffer)
	{
		map = join_map(map, buffer, data);
		buffer = get_next_line(fd);
		data->height++;
	}
	data->map = ft_split(map, '\n');
	free(map);
	if (!data->map)
		print_error("Failed to create map", data);
}

void	parse(int ac, char **av, t_data *data)
{
	int	fd;

	if (ac != 2)
		print_error("Wrong argument count", data);
	if (!ft_strnstr(&av[1][ft_strlen(av[1]) - 4], ".ber", 4))
		print_error("Need '.ber' file format", data);
	if (ft_strlen(av[1]) < 5)
		print_error("Need valid '.ber' file", data);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		print_error("Failed to open file", data);
	get_map(fd, data);
	if (close(fd) < 0)
		print_error("Failed to close file", data);
}
