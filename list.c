/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:44:47 by llai              #+#    #+#             */
/*   Updated: 2023/12/21 13:40:58 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	init_list(char **int_str, int len, t_node *head, t_node *tail);
t_node	*create_new_node(int value);
int		list_size(t_node *head, t_node *tail);
int		smallest_in_list(t_node *head, t_node *tail);
int		largest_in_list(t_node *head, t_node *tail);

/* **************************************************************************
 * void	init_list(char **int_str, int len, t_node *head, t_node *tail)
 *
 * Summary of the function:
 * 
 * 	This function initialises the list from arguments.
 * 	It sets up a doubly linked list.
 *
 * Parameters : The arguments integers from the terminal 
 * 				and the size of the list.
 *
 * Return Value : It returns the first node of the list.
 * **************************************************************************/
void	init_list(char **int_str, int len, t_node *head, t_node *tail)
{
	int		i;

	i = 0;
	head->next = tail;
	tail->prev = head;
	while (i < len)
	{
		insert_end(ft_atoi(int_str[i]), tail);
		i++;
	}
}

/* **************************************************************************
 * t_node	*create_new_node(int value)
 *
 * Summary of the function:
 * 
 * 	This function creates and initialises a new node.
 *
 * Parameters : The value is an integer. 
 *
 * Return Value : It returns a new node.
 * **************************************************************************/
t_node	*create_new_node(int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
	{
		ft_printf("Error: malloc failed in add_to_list\n");
		exit(EXIT_FAILURE);
	}
	new_node->value = value;
	return (new_node);
}

int		list_size(t_node *head, t_node *tail)
{
	t_node	*curr;
	int		count;

	count = 0;
	curr = head->next;
	while (curr != tail)
	{
		count++;
		curr = curr->next;
	}
	return (count);
}

/* **************************************************************************
 * int	smallest_in_list(t_node *head, t_node *tail)
 *
 * Summary of the function:
 * 
 * 	This function finds the smallest value in the list.
 *
 * Parameters : The head node and the tail node in the list.
 *
 * Return Value : It returns the smallest number in the list.
 * **************************************************************************/
int	smallest_in_list(t_node *head, t_node *tail)
{
	t_node	*curr;
	int		smallest;

	curr = head->next;
	smallest = curr->value;
	while (curr != tail)
	{
		if (curr->value <= smallest)
			smallest = curr->value;
		curr = curr->next;
	}
	return (smallest);
}

/* **************************************************************************
 * int	largest_in_list(t_node *head, t_node *tail)
 *
 * Summary of the function:
 * 
 * 	This function finds the largest value in the list.
 *
 * Parameters : The head node and the tail node in the list.
 *
 * Return Value : It returns the largest number in the list.
 * **************************************************************************/
int	largest_in_list(t_node *head, t_node *tail)
{
	t_node	*curr;
	int		largest;

	curr = head->next;
	largest = curr->value;
	while (curr != tail)
	{
		if (curr->value >= largest)
			largest = curr->value;
		curr = curr->next;
	}
	return (largest);
}
