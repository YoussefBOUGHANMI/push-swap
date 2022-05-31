/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Youssef <youssef.boughanmi.pro@gmail.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 08:01:58 by Youssef           #+#    #+#             */
/*   Updated: 2022/05/31 19:59:17 by Youssef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	do_swap(char **stack)
{
	char	*tmp;
	int		ternary_len;

	ternary_len = ft_strlen(stack[0]);
	tmp = malloc((ternary_len + 1) * sizeof(char));
	ft_strlcpy(tmp, stack[0], ternary_len + 1);
	ft_strlcpy(stack[0], stack[1], ternary_len + 1);
	ft_strlcpy(stack[1], tmp, ternary_len + 1);
	free(tmp);
}

void	swap(char **stack, char stack_name)
{
	int	nb_el;

	nb_el = len_stack(stack);
	if (nb_el < 2)
		return ;
	do_swap(stack);
	if (stack_name == 'A')
		write(1, "sa\n", 3);
	if (stack_name == 'B')
		write(1, "sb\n", 3);
	return ;
}

void	double_swap(char **stack_a, char **stack_b)
{
	int	len_stack_a;
	int	len_stack_b;

	len_stack_a = len_stack(stack_a);
	len_stack_b = len_stack(stack_b);
	if (len_stack_a < 2 || len_stack_b < 2)
		return ;
	swap(stack_a, 'A');
	swap(stack_b, 'B');
	write(1, "ss\n", 3);
}

void	free_stack(char **stack, int nb_el)
{
	int	i;

	i = 0;
	while (i < nb_el)
	{
		free(stack[i]);
		i++;
	}
	free(stack);
}

char	**init_b(int nb_el, int ternary_len)
{
	char	**stack_b;
	int		i;

	i = 0;
	stack_b = malloc((nb_el + 1) * sizeof(char *));
	while (i < nb_el)
	{
		stack_b[i] = malloc((ternary_len + 1) * sizeof(char));
		ft_strlcpy(stack_b[i], "v", ternary_len + 1);
		i++;
	}
	return (stack_b);
}
