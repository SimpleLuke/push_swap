/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:51:03 by llai              #+#    #+#             */
/*   Updated: 2023/12/21 16:30:44 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*create_chunk(t_node *head, t_node *tail);
void	fill_chunk(int *chunk,int len, t_node *head);
int		*check_chunk(int *chunk, int len, t_node *head, t_node *tail);
int		large_in_chunk(int *chunk, int len);
bool	is_in_chunk(int target, int *chunk, int len);

int	*create_chunk(t_node *head, t_node *tail)
{
	int		len;
	int		size;
	int		*chunk;

	size = list_size(head, tail);
	len = size / 5;
	chunk = malloc(sizeof(int) * len);
	if (!chunk)
		exit(EXIT_FAILURE);
	fill_chunk(chunk, len, head);
	chunk = check_chunk(chunk, len, head, tail);
	return (chunk);
}

void	fill_chunk(int *chunk,int len, t_node *head)
{
	t_node	*curr;
	int		i;

	i = 0;
	curr = head->next;
	while (i < len)
	{
		chunk[i] = curr->value;
		curr = curr->next;
		i++;
	}
}

int	*check_chunk(int *chunk, int len, t_node *head, t_node *tail)
{
	t_node	*curr;
	int		i;
	int		temp_idx;

	i = 0;
	temp_idx = -1;
	curr = head->next;
	while (i++ < len)
		curr = curr->next;
	while (curr != tail)
	{
		i = 0;
		while (i < len)
		{
			if (curr->value < chunk[i])
			{
				temp_idx = large_in_chunk(chunk, len);
				chunk[temp_idx] = curr->value;
				break ;
			}
			i++;
		}
		curr = curr->next;
	}
	return (chunk);
}

int		large_in_chunk(int *chunk, int len)
{
	int	i;
	int	large_idx;
	int	large;

	i = 0;
	large_idx = 0;
	large = chunk[0];
	while (i < len)
	{
		if (chunk[i] > large)
		{
			large = chunk[i];
			large_idx = i;
		}
		i++;
	}
	return (large_idx);
}

bool	is_in_chunk(int target, int *chunk, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (target == chunk[i])
			return (true);
		i++;
	}
	return (false);
}
