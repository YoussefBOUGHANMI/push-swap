/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Youssef <youssef.boughanmi.pro@gmail.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 20:08:46 by Youssef           #+#    #+#             */
/*   Updated: 2022/05/31 17:34:17 by Youssef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	is_greater(char *el_1, char *el_2)
{
	int	ternary_len;
	int	i;

	i = 0;
	ternary_len = ft_strlen(el_1);
	while (i < ternary_len)
	{
		if (el_1[i] > el_2[i])
			return (1);
		if (el_1[i] < el_2[i])
			return (0);
		i++;
	}
	return (0);
}

void	pw_first_step(char **stack_a, char **stack_b, int pos)
{	
	int	nb_el;
	int	i;

	i = 0;
	nb_el = len_stack(stack_a);
	while (i < nb_el)
	{
		if (stack_a[0][pos] == '0')
			rotate(stack_a, 'A');
		else if (stack_a[0][pos] == '1')
			push(stack_a, stack_b, 'A');
		else if (stack_a[0][pos] == '2')
		{
			push(stack_a, stack_b, 'A');
			rotate(stack_b, 'B');
		}
		i++;
	}
}

void	pw_second_st(char **stack_a, char **stack_b, int pos, int ternary_len)
{
	int	nb_el;
	int	i;

	i = 0;
	nb_el = len_stack(stack_b);
	while ((i <= nb_el && pos == ternary_len -1)
		|| (i <= nb_el && stack_b[0][pos] == '1'))
	{
		push(stack_b, stack_a, 'B');
		i++;
	}
	while ((i <= nb_el && pos != ternary_len - 1 && stack_b[0][pos] == '2'))
	{
		reverse(stack_b, 'B');
		push(stack_b, stack_a, 'B');
		i++;
	}
}

void	push_swap(char **stack_a, char **stack_b, int ternary_len)
{
	int	pos;

	pos = ternary_len - 1 ;
	while (pos >= 0)
	{
		pw_first_step(stack_a, stack_b, pos);
		pw_second_st(stack_a, stack_b, pos, ternary_len);
		pos--;
	}
}
