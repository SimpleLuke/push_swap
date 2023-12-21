/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:51:25 by llai              #+#    #+#             */
/*   Updated: 2023/12/21 14:46:05 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** 
 *  Summary of File:                                                          
 *  
 *  	This program is a part of push_swap program.
 *  	This program contains code which sorts a stack of integers
 *  	with a size of 100 list.
 *  	Since there are limited options for a size of 100 list,
 *  	we can sort it with simple operations.
 *
 * ************************************************************************** */

#include "push_swap.h"

int	*create_chunk(t_node *head, t_node *tail);
void	fill_chunk(int *chunk,int len, t_node *head);
int	*check_chunk(int *chunk, int len, t_node *head, t_node *tail);
int		large_in_chunk(int *chunk, int len);

/* **************************************************************************
 * void	sort_large_size(t_node *head_a, t_node *tail_a,
 * 						t_node *head_b, t_node *tail_b)
 *
 * Summary of the function:
 * 
 * 	This function sorts a list with a size of 100  or less.
 * 	It outputs the operation intrustions.
 *
 * Parameters : The head node and the tail node of the list.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	sort_large_size(t_node *head, t_node *tail,
			t_node *head_b, t_node *tail_b)
{
	int	*chunk;
	int	len;
	int	i;

	(void)head_b;
	(void)tail_b;
	len = (list_size(head, tail)) / 5;
	chunk = create_chunk(head, tail);
	i = 0;
	while (i < len)
	{
		ft_printf("%d\n", chunk[i]);
		i++;
	}
}

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
	//int		temp;

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
	large_idx = -1;
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
