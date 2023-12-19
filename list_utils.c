/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:03:16 by llai              #+#    #+#             */
/*   Updated: 2023/12/19 18:57:00 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_front(int value, t_node *head);
void	insert_end(int value, t_node *tail);
void	remove_front(t_node *head);
void	remove_end(t_node *tail);
void	free_list(t_node *head, t_node *tail);

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
 * void	remove_front(t_node *head)
 *
 * Summary of the function:
 * 
 * 	This function removes the node in the front of the list.
 *
 * Parameters : The head node of the list.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	remove_front(t_node *head)
{
	head->next->next->prev = head;
	head->next = head->next->next;
}

/* **************************************************************************
 * void	remove_end(t_node *tail)
 *
 * Summary of the function:
 * 
 * 	This function removes the node in the end of the list.
 *
 * Parameters : The tail node of the list.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	remove_end(t_node *tail)
{
	tail->prev->prev->next = tail;
	tail->prev = tail->prev->prev;
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
	t_node	*del_node;

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
