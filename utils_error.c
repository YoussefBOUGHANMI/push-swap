/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Youssef <youssef.boughanmi.pro@gmail.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:10:03 by Youssef           #+#    #+#             */
/*   Updated: 2022/06/07 20:40:16 by Youssef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_is_big_int(char *number)
{
	char	*max_int;
	int		i;

	i = 0;
	max_int = "2147483647";
	if (number[0] == '-')
	{
		max_int = "2147483648";
		number++;
	}
	if (ft_strlen(number) > 10)
		return (1);
	else if (ft_strlen(number) < 10)
		return (0);
	while (i <= 9)
	{
		if (number[i] < max_int[i])
			i = 10;
		if (number[i] > max_int[i])
			return (1);
		i++;
	}
	return (0);
}

int	check_biginit_condition(int len_list, char **list)
{
	int	i;

	i = 0;
	while (i < len_list)
	{
		if (ft_is_big_int(list[i]) == 1)
		{	
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_digital_condition(int len_list, char **list)
{
	int	i;
	int	ii;

	i = 0;
	while (i < len_list)
	{
		ii = 0;
		if (list[i][ii] == '-')
			ii++;
		while (ii < (int)ft_strlen(list[i]))
		{	
			if (ft_isdigit(list[i][ii]) == 0)
			{	
				return (1);
			}
			ii++;
		}
		i++;
	}
	return (0);
}

int	check_double(int len_list, int *list_int)
{
	int	i;
	int	ii;

	i = 0;
	while (i < len_list - 1)
	{
		ii = i + 1;
		while (ii < len_list)
		{	
			if (list_int[i] == list_int[ii])
			{
				return (1);
			}
			ii++;
		}
		i++;
	}
	return (0);
}

char	**get_return_error(char **list, int len_list, int top_free_split)
{
	char	**error_return;

	if (top_free_split == 1)
		free_stack(list, len_list);
	error_return = malloc(2 * sizeof(char *));
	error_return[0] = "Error";
	return (error_return);
}
