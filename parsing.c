/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarian <lemarian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:35:02 by lemarian          #+#    #+#             */
/*   Updated: 2024/09/13 16:49:09 by lemarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**fill_map(char **map, t_node *list)
{
	int	i;
	int	size;

	i = 0;
	size = line_len(list->str);
	while (list != NULL)
	{
		map[i] = malloc(sizeof(char) * size + 1);
		map[i] = copy_line(list->str, map[i]);
		i++;
		list = list->next;
	}
	return (map);
}

char	**parse(int fd)
{
	t_node	*list;
	char	*str;
	char	**map;
	int	rows;

	rows = 0;
	list = NULL;
	str = get_next_line(fd);
	while (str)
	{
		insert_tail(&list, str);
		str = get_next_line(fd);
	}
	free(str);
	rows = count_nodes(list);
	map = malloc(sizeof(char *) * (rows + 1));
	if (!map)
		return (free_list(&list), NULL);
	map[rows] = 0;
	fill_map(map, list);
	free_list(&list);
	return (map);
}

int	main(void)
{
	int	fd;
	char	**map;
	int	i;

	i = 0;
	fd = open("map.ber", O_RDONLY);
	map = parse(fd);
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
	while (i >= 0)
	{
		free(map[i]);
		i--;
	}
	free(map);//what's this one for
	close(fd);
	return (0);
}
