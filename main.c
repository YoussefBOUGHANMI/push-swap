/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Youssef <youssef.boughanmi.pro@gmail.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:51:49 by Youssef           #+#    #+#             */
/*   Updated: 2022/06/07 18:30:28 by Youssef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "push_swap.h"

void	do_push_swap(char **stack_a)
{
	int		ternary_len;
	int		nb_el;
	char	**stack_b;		

	nb_el = len_stack(stack_a);
	ternary_len = get_ternary_len(nb_el);
	stack_b = init_b(nb_el, ternary_len);
	if (nb_el == 5 || nb_el == 3)
		push_swap_low(stack_a, stack_b, nb_el);
	else
		push_swap(stack_a, stack_b, ternary_len);
	free_stack(stack_a, nb_el);
	free_stack(stack_b, nb_el);
}

void	do_nothing(void)
{
	return ;
}

int	main(int argc, char *argv[])
{
	char	**stack_a;

	if (argc == 1)
		do_nothing();
	else
	{
		stack_a = init_a(argc - 1, &argv[1]);
		if ((ft_strncmp(stack_a[0], "Error", 5) == 0)
			|| (ft_strncmp(stack_a[0], "order", 5) == 0))
		{
			if (ft_strncmp(stack_a[0], "Error", 5) == 0)
				write(2, "Error\n", 6);
			free_stack(stack_a, 0);
		}
		else
			do_push_swap(stack_a);
	}
}
