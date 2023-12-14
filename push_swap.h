/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:35:00 by llai              #+#    #+#             */
/*   Updated: 2023/12/14 15:05:29 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "libft/libft.h"

typedef struct s_node
{
	int				value;
	struct node_s	*prev;
	struct node_s	*next;
}	t_node;

/* **************************************************************************
 * void	check_valid_arg(char **int_str, int len)
 *
 * Summary of the function:
 * 
 * 	This function checks if the arguments are valid,
 * 	which they are NOT non numeric, duplicated and within the value of int.
 * 	In invalid cases, it outputs "Error" and exit the program.
 *
 * Parameters : A pointer to the argument string.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	check_valid_arg(char **int_str, int len);

/* **************************************************************************
 * size_t stack_size(char **int_str)
 *
 * Summary of the function:
 * 
 * 	This function finds the size of the input integers,
 * 	it helps to manipulate the stacks/lists.
 *
 * Parameters : array of string - index 0 would be the programme name.
 *
 * Return Value : Positive integer as the size.
 * **************************************************************************/
size_t	stack_size(char **int_str);

/* **************************************************************************
 * t_node	*init_list(char **int_str, size_t size)
 *
 * Summary of the function:
 * 
 * 	This function initialises the list from arguments.
 * 	It sets up a doubly linked list.
 *
 * Parameters : The arguments integers from the terminal 
 * 				(index 0 is programme name) and the size of the list.
 *
 * Return Value : It returns the first node of the list.
 * **************************************************************************/
t_node	*init_list(char **int_str, size_t size);

/* **************************************************************************
 * t_node	*add_to_list(int value, t_node *prev, t_node *next)
 *
 * Summary of the function:
 * 
 * 	This function initialises the node in the doubly linked list.
 * 	It sets up the value and points to previous and next node.
 *
 * Parameters : The value is an integer. prev and node are pointing to
 * 				a node struct.
 *
 * Return Value : It returns a new node.
 * **************************************************************************/
t_node	*add_to_list(int value, t_node *prev, t_node *next);

/* **************************************************************************
 * void	push_swap(t_node *first, size_t size)
 *
 * Summary of the function:
 * 
 * 	This function sorts the list and ouput the steps.
 * 	It excutes different sorting algorithms depends on the size
 * 	of the list.
 *
 * Parameters : The first node of the list and the size of the list
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	push_swap(t_node *first, size_t size);

#endif
