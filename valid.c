/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:18:56 by llai              #+#    #+#             */
/*   Updated: 2023/12/14 15:21:13 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** 
 *  Summary of File:                                                          
 *  
 *  	This file contains code which validate the argument input.
 *  	The function displays "Error" and exit if the input is invalid. 
 *
 * ************************************************************************** */
#include "push_swap.h"

bool	check_numeric(char **int_str, int len);
bool	check_duplicate(char **int_str);
bool	check_integer(char **int_str);

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
void	check_valid_arg(char **int_str, int len)
{
	//if (!check_numeric(int_str) || !check_duplicate(int_str) || !check_integer(int_str))
	if (!check_numeric(int_str, len))
	{
		write(1, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}

/* **************************************************************************
 * bool	check_numeric(char **int_str, int len)
 *
 * Summary of the function:
 * 
 * 	This function checks if the array of string are all numeric.
 *
 * Parameters : A array of string.
 *
 * Return Value : It returns true or false.
 * **************************************************************************/
bool check_numeric(char **int_str, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (int_str[i][j])
		{
			if (!ft_isdigit(int_str[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
