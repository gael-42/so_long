/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarian <lemarian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 14:32:56 by lemarian          #+#    #+#             */
/*   Updated: 2024/09/13 16:39:26 by lemarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	insert_tail(t_node **head, char *str)
{
	t_node	*new_node;
	t_node	*tail;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->str = str;
	new_node->next = NULL;
	tail = *head;
	if (*head == NULL)
		*head = new_node;
	else
	{
		while (tail->next != NULL)
			tail = tail->next;
		tail->next = new_node;
	}
}

void	free_list(t_node **head)
{
	t_node	*current;

	current = *head;
	if (*head == NULL)
		return;
	while (*head != NULL)
	{
		current = *head;
		*head = (*head)->next;
		free(current->str);
		free(current);
	}
	free(*head);
}

void	print_list(t_node *head)//remove later
{
	while (head)
	{
		ft_printf("%s", head->str);
		head = head->next;
	}
}

int	count_nodes(t_node *head)
{
	int	count;

	count = 0;
	while (head)
	{
		head = head->next;
		count++;
	}
	return (count);
}

size_t	line_len(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\n')
		i++;
	return (i);
}

char	*copy_line(char *src, char *copy)
{
	int	i;

	i = 0;
	while (src[i] && src[i] != '\n')
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
