/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Youssef <youssef.boughanmi.pro@gmail.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:10:18 by Youssef           #+#    #+#             */
/*   Updated: 2022/05/31 20:02:16 by Youssef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	check_order(int len_list, int *list)
{
	int	i;

	i = 0;
	while (i < len_list - 1)
	{
		if (list[i] > list[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	do_rotate(char **stack)
{
	char	*el_tomov;
	int		i;
	int		ternary_len;

	ternary_len = ft_strlen(stack[0]);
	i = 1;
	el_tomov = malloc((ternary_len + 1) * sizeof(char));
	ft_strlcpy(el_tomov, stack[0], ternary_len + 1);
	while (stack[i] && (stack[i][0] != 'v'))
	{
		ft_strlcpy(stack[i - 1], stack[i], ternary_len + 1);
		i++;
	}
	ft_strlcpy(stack[i - 1], el_tomov, ternary_len + 1);
	free(el_tomov);
}

void	rotate(char **stack, char stack_name)
{
	int	nb_el;

	nb_el = len_stack(stack);
	if (nb_el < 2)
		return ;
	do_rotate(stack);
	if (stack_name == 'A')
		write(1, "ra\n", 3);
	if (stack_name == 'B')
		write(1, "rb\n", 3);
	return ;
}

void	double_rotate(char **stack_a, char **stack_b)
{
	int	len_stack_a;
	int	len_stack_b;

	len_stack_a = len_stack(stack_a);
	len_stack_b = len_stack(stack_b);
	if (len_stack_a < 2 || len_stack_b < 2)
		return ;
	do_rotate(stack_a);
	do_rotate(stack_b);
	write(0, "rr\n", 3);
}

int	*transform_char_int(int len_list, char **list)
{
	int	*list_int;
	int	i;

	i = 0;
	list_int = malloc((len_list) * sizeof(int));
	while (i <= len_list - 1)
	{
		list_int[i] = ft_atoi(list[i]);
		i++;
	}
	return (list_int);
}
