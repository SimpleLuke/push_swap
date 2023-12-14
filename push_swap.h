/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:35:00 by llai              #+#    #+#             */
/*   Updated: 2023/12/14 13:16:04 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	struct node_s	*prev;
	struct node_s	*next;
}	t_node;

/* **************************************************************************
 * size_t stack_size(char **argv)
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
size_t	stack_size(char **argv);

#endif
