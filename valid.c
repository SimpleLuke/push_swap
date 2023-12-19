/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:18:56 by llai              #+#    #+#             */
/*   Updated: 2023/12/19 09:13:10 by llai             ###   ########.fr       */
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

static bool	check_numeric(char **int_str, int len);
static bool	check_duplicate(char **int_str, int len);
static bool	check_integer(char **int_str, int len);

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
	if (!check_numeric(int_str, len) || !check_integer(int_str, len)
		|| !check_duplicate(int_str, len))
	{
		ft_printf("Error\n");
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
static bool	check_numeric(char **int_str, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		if (int_str[i][j] == '-' || int_str[i][j] == '+')
			j++;
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

/* **************************************************************************
 * bool	check_integer(char **int_str, int len)
 *
 * Summary of the function:
 * 
 * 	This function checks if the array of string are valid integer.
 *
 * Parameters : A array of string.
 *
 * Return Value : It returns true or false.
 * **************************************************************************/
static bool	check_integer(char **int_str, int len)
{
	int			i;

	i = 0;
	while (i < len)
	{
		if (ft_atoll(int_str[i]) > INT_MAX || ft_atoll(int_str[i]) < INT_MIN)
			return (false);
		i++;
	}
	return (true);
}

/* **************************************************************************
 * bool	check_duplicate(char **int_str, int len)
 *
 * Summary of the function:
 * 
 * 	This function checks if the array of string are duplicated.
 *
 * Parameters : A array of string.
 *
 * Return Value : It returns true or false.
 * **************************************************************************/
static bool	check_duplicate(char **int_str, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (ft_atoll(int_str[i]) == ft_atoll(int_str[j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
