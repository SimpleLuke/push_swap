/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:44:47 by llai              #+#    #+#             */
/*   Updated: 2023/12/19 11:08:33 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	init_list(char **int_str, int len, t_node *head, t_node *tail);
t_node	*create_new_node(int value);
void	insert_front(int value, t_node *head);
void	insert_end(int value, t_node *tail);
void	free_list(t_node *head, t_node *tail);

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

/* **************************************************************************
 * void	insert_front(int value, t_node *head)
 *
 * Summary of the function:
 * 
 * 	This function initialises the node in the doubly linked list.
 * 	It sets up the value and add the node to the front of the list.
 *
 * Parameters : The value is an integer. prev and node are pointing to
 * 				a node struct.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	insert_front(int value, t_node *head)
{
	t_node	*new_node;

	new_node = create_new_node(value);
	new_node->prev = head;
	new_node->next = head->next;
	head->next->prev = new_node;
	head->next = new_node;
}

/* **************************************************************************
 * void	insert_end(int value, t_node *tail)
 *
 * Summary of the function:
 * 
 * 	This function initialises the node in the doubly linked list.
 * 	It sets up the value and add the node to the end of the list.
 *
 * Parameters : The value is an integer. prev and node are pointing to
 * 				a node struct.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	insert_end(int value, t_node *tail)
{
	t_node	*new_node;

	new_node = create_new_node(value);
	new_node->next = tail;
	new_node->prev = tail->prev;
	tail->prev->next = new_node;
	tail->prev = new_node;
}
/* **************************************************************************
 * void	free_list(t_node *head)
 *
 * Summary of the function:
 * 
 * 	This function frees all the nodes in the list.
 *
 * Parameters : The head of the list.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	free_list(t_node *head, t_node *tail)
{
	t_node *del_node;

	while (head->next != tail)
	{
		head->next->next->prev = head;
		del_node = head->next;
		head->next = head->next->next;
		free(del_node);
	}
	free(head);
	free(tail);
}
