/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:35:00 by llai              #+#    #+#             */
/*   Updated: 2023/12/19 10:34:59 by llai             ###   ########.fr       */
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
	struct s_node	*prev;
	struct s_node	*next;
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
t_node	*create_new_node(int value);

/* **************************************************************************
 * t_node	*init_list(char **int_str, int len)
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
void	init_list(char **int_str, int len, t_node *head, t_node *tail);

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
