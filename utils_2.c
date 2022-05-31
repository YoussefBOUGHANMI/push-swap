/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Youssef <youssef.boughanmi.pro@gmail.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 14:10:52 by Youssef           #+#    #+#             */
/*   Updated: 2022/05/31 20:01:15 by Youssef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	len_stack(char **stack)
{
	int	len;

	len = 0;
	while ((stack[len]) && (stack[len][0] != 'v'))
		len ++;
	return (len);
}

void	do_push(char **stack_src, char **stack_dest)
{
	char	*el_tomov;
	int		i;
	int		ternary_len;

	ternary_len = ft_strlen(stack_src[0]);
	i = 1;
	el_tomov = malloc((ternary_len + 1) * sizeof(char));
	ft_strlcpy(el_tomov, stack_src[0], ternary_len + 1);
	while (stack_src[i] && (stack_src[i][0] != 'v'))
	{
		ft_strlcpy(stack_src[i - 1], stack_src[i], ternary_len + 1);
		i++;
	}
	ft_strlcpy(stack_src[i - 1], "v", ternary_len + 1);
	i = len_stack(stack_dest);
	while (i > 0)
	{
		ft_strlcpy(stack_dest[i], stack_dest[i - 1], ternary_len + 1);
		i--;
	}
	ft_strlcpy(stack_dest[i], el_tomov, ternary_len + 1);
	free(el_tomov);
}

void	push(char **stack_src, char **stack_dest, char stack_src_name)
{
	int	len_stack_src;

	len_stack_src = len_stack(stack_src);
	if (len_stack_src == 0)
		return ;
	do_push(stack_src, stack_dest);
	if (stack_src_name == 'A')
		write(1, "pb\n", 3);
	if (stack_src_name == 'B')
		write(1, "pa\n", 3);
	return ;
}

int	get_ternary_len(int nb_el)
{
	int	ternary_len;

	nb_el = nb_el - 1;
	ternary_len = 0;
	while (nb_el != 0)
	{
		nb_el = nb_el / 3;
		ternary_len++;
	}
	return (ternary_len);
}

int	check_all_error(int len_list, char **list)
{
	int	*list_int;

	if (len_list == 0)
		return (2);
	if (check_minus_error(len_list, list) == 1)
		return (1);
	if (check_digital_condition(len_list, list) == 1)
		return (1);
	if (check_biginit_condition(len_list, list) == 1)
		return (1);
	list_int = transform_char_int(len_list, list);
	if (check_double(len_list, list_int) == 1)
	{
		return (1);
	}
	if (check_order(len_list, list_int) == 1)
		return (2);
	free(list_int);
	return (0);
}
