/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarian <lemarian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:28:57 by lemarian          #+#    #+#             */
/*   Updated: 2024/09/13 16:39:02 by lemarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "new_libft/libft.h"

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

typedef struct s_node
{
	char	*str;
	struct s_node	*next;
}	t_node;

void	insert_tail(t_node **head, char *str);
void	print_list(t_node *head);
void	free_list(t_node **head);
int	count_nodes(t_node *head);
size_t	line_len(char *str);
char	*copy_line(char *src, char*copy);
