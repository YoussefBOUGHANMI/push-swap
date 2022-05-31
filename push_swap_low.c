/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_low.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Youssef <youssef.boughanmi.pro@gmail.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 20:08:19 by Youssef           #+#    #+#             */
/*   Updated: 2022/05/31 17:14:06 by Youssef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	pw_low_first_step(char **stack_a, char **stack_b)
{
	int	nb_mouv;

	nb_mouv = 0;
	while (nb_mouv < 2)
	{
		if (ft_strncmp(stack_a[0], "10", 2) == 0
			|| ft_strncmp(stack_a[0], "11", 2) == 0)
		{
			push(stack_a, stack_b, 'A');
			nb_mouv++;
		}
		else
			rotate(stack_a, 'A');
	}
	if (ft_strncmp(stack_b[0], "11", 2) == 0)
		rotate(stack_b, 'B');
}

void	pw_low_second_step(char **stack_a, char **stack_b)
{
	if (stack_a[0][1] < stack_a[1][1])
		swap(stack_a, 'A');
	if (stack_a[2][1] == '2')
		reverse(stack_a, 'A');
	else if (stack_a[2][1] == '1')
	{
		reverse(stack_a, 'A');
		swap(stack_a, 'A');
	}
	push(stack_b, stack_a, 'B');
	push(stack_b, stack_a, 'B');
}

void	low_low_ps(char **stack_a)
{
	if (stack_a[0][0] < stack_a[1][0])
		swap(stack_a, 'A');
	if (stack_a[2][0] == '2')
		reverse(stack_a, 'A');
	else if (stack_a[2][0] == '1')
	{
		reverse(stack_a, 'A');
		swap(stack_a, 'A');
	}
}

void	push_swap_low(char **stack_a, char **stack_b, int nb_el)
{
	if (nb_el == 5)
	{
		pw_low_first_step(stack_a, stack_b);
		pw_low_second_step(stack_a, stack_b);
	}
	else
		low_low_ps(stack_a);
}
