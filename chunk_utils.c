/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:51:03 by llai              #+#    #+#             */
/*   Updated: 2023/12/21 19:25:43 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_chunk		*create_chunk(t_node *head, t_node *tail);
void	fill_chunk(t_chunk *chunk, t_node *head);
t_chunk		*check_chunk(t_chunk *chunk, t_node *head, t_node *tail);
int			large_in_chunk(t_chunk *chunk);
bool		is_in_chunk(int target, t_chunk *chunk);

t_chunk	*create_chunk(t_node *head, t_node *tail)
{
	int		size;
	size_t	total_size;
	t_chunk	*chunk;

	size = list_size(head, tail);
	total_size = sizeof(t_chunk) + sizeof(int) * size; chunk = malloc(total_size);
	if (!chunk)
		exit(EXIT_FAILURE);
	chunk->len = size;
	fill_chunk(chunk, head);
	chunk = check_chunk(chunk, head, tail);
	return (chunk);
}

void	fill_chunk(t_chunk *chunk, t_node *head)
{
	t_node	*curr;
	int		i;

	i = 0;
	curr = head->next;
	while (i < chunk->len)
	{
		chunk->arr[i] = curr->value;
		curr = curr->next;
		i++;
	}
}

t_chunk	*check_chunk(t_chunk *chunk, t_node *head, t_node *tail)
{
	t_node	*curr;
	int		i;
	int		temp_idx;

	i = 0;
	temp_idx = -1;
	curr = head->next;
	//while (i++ < len)
	//	curr = curr->next;
	while (curr != tail)
	{
		i = 0;
		while (i < chunk->len)
		{
			if (curr->value < chunk->arr[i])
			{
				temp_idx = large_in_chunk(chunk);
				chunk->arr[temp_idx] = curr->value;
				break ;
			}
			i++;
		}
		curr = curr->next;
	}
	return (chunk);
}

int		large_in_chunk(t_chunk *chunk)
{
	int	i;
	int	large_idx;
	int	large;

	i = 0;
	large_idx = 0;
	large = chunk->arr[0];
	while (i < chunk->len)
	{
		if (chunk->arr[i] > large)
		{
			large = chunk->arr[i];
			large_idx = i;
		}
		i++;
	}
	return (large_idx);
}

bool	is_in_chunk(int target, t_chunk *chunk)
{
	int	i;

	i = 0;
	while (i < chunk->len)
	{
		if (target == chunk->arr[i])
			return (true);
		i++;
	}
	return (false);
}
