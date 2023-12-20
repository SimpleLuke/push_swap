/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:35:00 by llai              #+#    #+#             */
/*   Updated: 2023/12/20 16:30:44 by llai             ###   ########.fr       */
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
void	insert_front(int value, t_node *head);

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
void	insert_end(int value, t_node *tail);

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
void	remove_front(t_node *head);

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
void	remove_end(t_node *tail);

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
void	free_list(t_node *head, t_node *tail);

/* **************************************************************************
 * void	push_swap(t_node *head, t_node *tail, int len)
 *
 * Summary of the function:
 * 
 * 	This function sorts the list and ouput the steps.
 * 	It excutes different sorting algorithms depends on the size
 * 	of the list.
 *
 * Parameters : The head node and the tail node.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	push_swap(t_node *head, t_node *tail, int len);

/* **************************************************************************
 * bool	is_sorted(t_node *head, t_node *tail)
 *
 * Summary of the function:
 * 
 * 	This function checks if the nodes in the list are sorted
 * 	from small to large.
 *
 * Parameters : The head node and the tail node.
 *
 * Return Value : It returns true or false.
 * **************************************************************************/
bool	is_sorted(t_node *head, t_node *tail);

/* **************************************************************************
 * bool	cmp(t_node *node_1, t_node *node_2)
 *
 * Summary of the function:
 * 
 * 	This function checks if node_1 is bigger than node_2
 *
 * Parameters : The two nodes in the list.
 *
 * Return Value : It returns true or false.
 * **************************************************************************/
bool	cmp(t_node *node_1, t_node *node_2);

/* **************************************************************************
 * void	swap_a(t_node *head, bool is_print)
 *
 * Summary of the function:
 * 
 * 	This function swaps the first 2 elements at the top of stack a.
 * 	Do nothing if there is only one or no elements.
 * 	It also prints out 'sa'.
 *
 * Parameters : The head node of the stack.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	swap_a(t_node *head, bool is_print);

/* **************************************************************************
 * void	swap_b(t_node *head, bool is_print)
 *
 * Summary of the function:
 * 
 * 	This function swaps the first 2 elements at the top of stack b.
 * 	Do nothing if there is only one or no elements.
 * 	It also prints out 'sb'.
 *
 * Parameters : The head node of the stack.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	swap_b(t_node *head, bool is_print);

/* **************************************************************************
 * void	swap_both(t_node *head_a, t_node *head_b)
 *
 * Summary of the function:
 * 
 * 	This function swaps the first 2 elements at the top of stack a & b.
 * 	Do nothing if there is only one or no elements.
 * 	It also prints out 'ss'.
 *
 * Parameters : The head node of the stacks.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	swap_both(t_node *head_a, t_node *head_b);

/* **************************************************************************
 * void	push_a(t_node *head_a, t_node *head_b, t_node *tail_b)
 *
 * Summary of the function:
 * 
 * 	This function pushes the first element at the top of b
 * 	and put it at the top of a.
 * 	Do nothing if b is empty.
 * 	Display "pa";
 *
 * Parameters : The head node of the stacks.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	push_a(t_node *head_a, t_node *head_b, t_node *tail_b);

/* **************************************************************************
 * void	push_b(t_node *head_a, t_node *head_b, t_node *tail_a);
 *
 * Summary of the function:
 * 
 * 	This function pushes the first element at the top of a
 * 	and put it at the top of b.
 * 	Do nothing if a is empty.
 * 	Display "pb";
 *
 * Parameters : The head node of the stacks.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	push_b(t_node *head_a, t_node *head_b, t_node *tail_a);

/* **************************************************************************
 * void	rotate_a(t_node *head_a, t_node *tail_a, bool is_print)
 *
 * Summary of the function:
 * 
 * 	This function shifts up all elements of stack a by 1.
 * 	The first element becomes the last one.
 * 	Display "ra";
 *
 * Parameters : The head node of the stack.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	rotate_a(t_node *head_a, t_node *tail_a, bool is_print);

/* **************************************************************************
 * void	rotate_b(t_node *head_b, t_node *tail_b, bool is_print)
 *
 * Summary of the function:
 * 
 * 	This function shifts up all elements of stack b by 1.
 * 	The first element becomes the last one.
 * 	Display "rb";
 *
 * Parameters : The head node of the stack.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	rotate_b(t_node *head_b, t_node *tail_b, bool is_print);

/* **************************************************************************
 * void	rotate_both(t_node *head_a, t_node *tail_a, 
 * 					t_node *head_b, t_node *tail_b);
 *
 * Summary of the function:
 * 
 * 	This function shifts up all elements of stack a & b by 1.
 * 	The first element becomes the last one.
 * 	Display "rr";
 *
 * Parameters : The head node of the stack.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	rotate_both(t_node *head_a, t_node *tail_a,
			t_node *head_b, t_node *tail_b);

/* **************************************************************************
 * void	rotate_rev_a(t_node *head_a, t_node *tail_a, bool is_print)
 *
 * Summary of the function:
 * 
 * 	This function shifts down all elements of stack a by 1.
 * 	The last element becomes the first one.
 * 	Display "rra";
 *
 * Parameters : The head node of the stack.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	rotate_rev_a(t_node *head_a, t_node *tail_a, bool is_print);

/* **************************************************************************
 * void	rotate_rev_b(t_node *head_b, t_node *tail_b, bool is_print)
 *
 * Summary of the function:
 * 
 * 	This function shifts down all elements of stack b by 1.
 * 	The last element becomes the first one.
 * 	Display "rrb";
 *
 * Parameters : The head node of the stack.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	rotate_rev_b(t_node *head_b, t_node *tail_b, bool is_print);

/* **************************************************************************
 * void	rotate_rev_both(t_node *head_a, t_node *tail_a, 
 * 						t_node *head_b, t_node *tail_b);
 *
 * Summary of the function:
 * 
 * 	This function shifts down all elements of stack a & b by 1.
 * 	The last element becomes the first one.
 * 	Display "rrr";
 *
 * Parameters : The head node of the stack.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	rotate_rev_both(t_node *head_a, t_node *tail_a,
			t_node *head_b, t_node *tail_b);

/* **************************************************************************
 * void	sort_small_size(t_node *head, t_node *tail)
 *
 * Summary of the function:
 * 
 * 	This function sorts a list with a size of three or less.
 * 	It outputs the operation intrustions.
 *
 * Parameters : The head node and the tail node of the list.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	sort_small_size(t_node *head, t_node *tail);

/* **************************************************************************
 * void	sort_mid_size(t_node *head_a, t_node *tail_a,
 * 						t_node *head_b, t_node *tail_b)
 *
 * Summary of the function:
 * 
 * 	This function sorts a list with a size of five or less.
 * 	It outputs the operation intrustions.
 *
 * Parameters : The head node and the tail node of the list.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	sort_mid_size(t_node *head_a, t_node *tail_a,
			t_node *head_b, t_node *tail_b);

/* **************************************************************************
 * bool	is_smallest(t_node *head, t_node *tail, t_node *node)
 *
 * Summary of the function:
 * 
 * 	This function checks if the node is the smallest in the list.
 *
 * Parameters : The head and tail nodes in the list and a target node.
 *
 * Return Value : It returns true or false.
 * **************************************************************************/
bool	is_smallest(t_node *head, t_node *tail, t_node *node);

/* **************************************************************************
 * bool	is_largest(t_node *head, t_node *tail, t_node *node)
 *
 * Summary of the function:
 * 
 * 	This function checks if the node is the largest in the list.
 *
 * Parameters : The head and tail nodes in the list and a target node.
 *
 * Return Value : It returns true or false.
 * **************************************************************************/
bool	is_largest(t_node *head, t_node *tail, t_node *node);

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
int		smallest_in_list(t_node *head, t_node *tail);

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
int		largest_in_list(t_node *head, t_node *tail);

/* **************************************************************************
 * bool	is_reverse(t_node *head, t_node *tail, int smallest)
 *
 * Summary of the function:
 * 
 * 	This function checks if the rotation needs to be reverse rotating.
 *
 * Parameters : The head and tail nodes in the list and the number to determine.
 *
 * Return Value : It returns true or false.
 * **************************************************************************/
bool	is_reverse(t_node *head, t_node *tail, int smallest);
#endif
