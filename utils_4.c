/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Youssef <youssef.boughanmi.pro@gmail.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:40:12 by Youssef           #+#    #+#             */
/*   Updated: 2022/06/07 20:42:16 by Youssef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	do_reverse(char **stack)
{
	char	*el_tomov;
	int		i;
	int		ternary_len;

	i = len_stack(stack);
	i--;
	ternary_len = ft_strlen(stack[i]);
	el_tomov = malloc((ternary_len + 1) * sizeof(char));
	ft_strlcpy(el_tomov, stack[i], ternary_len + 1);
	while (i > 0)
	{
		ft_strlcpy(stack[i], stack[i - 1], ternary_len + 1);
		i--;
	}
	ft_strlcpy(stack[i], el_tomov, ternary_len + 1);
	free(el_tomov);
}

void	reverse(char **stack, char stack_name)
{
	int	nb_el;

	nb_el = len_stack(stack);
	if (nb_el < 2)
		return ;
	do_reverse(stack);
	if (stack_name == 'A')
		write(1, "rra\n", 4);
	if (stack_name == 'B')
		write(1, "rrb\n", 4);
	return ;
}

void	double_reverse(char **stack_a, char **stack_b)
{
	int	len_stack_a;
	int	len_stack_b;

	len_stack_a = len_stack(stack_a);
	len_stack_b = len_stack(stack_b);
	if (len_stack_a < 2 || len_stack_b < 2)
		return ;
	do_reverse(stack_a);
	do_reverse(stack_b);
	write(1, "rrr\n", 4);
}

int	check_minus_error(int len_list, char **list)
{
	int	i;

	i = 0;
	while (i < len_list)
	{
		if ((list[i][0] == '-') && (ft_strlen(list[i]) == 1))
			return (1);
		i++;
	}
	return (0);
}

char	**get_order_return(char **list, int len_list, int top_free_split)
{
	char	**error_return;

	if (top_free_split == 1)
		free_stack(list, len_list);
	error_return = malloc (2 * sizeof(char *));
	error_return[0] = "order";
	return (error_return);
}
