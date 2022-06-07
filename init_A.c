/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_A.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Youssef <youssef.boughanmi.pro@gmail.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:47:30 by Youssef           #+#    #+#             */
/*   Updated: 2022/06/07 20:43:00 by Youssef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	*get_rank(int len_list, int *list_int)
{
	int	*list_rank;
	int	i;
	int	rank;
	int	ii;

	list_rank = malloc(len_list * sizeof(int));
	i = 0;
	while (i < len_list)
	{
		ii = 0;
		rank = 0;
		while (ii < len_list)
		{
			if (list_int[i] < list_int[ii])
			{
				rank++;
			}
			ii++;
		}			
		list_rank[i] = rank;
		i++;
	}
	return (list_rank);
}

char	*int_to_ternary(int max_len, int number)
{
	char	*ternary;
	int		i;

	i = 0;
	ternary = malloc((max_len + 1) * sizeof(char));
	while (i < max_len)
	{
		ternary[max_len - i - 1] = number % 3 + 48;
		number = number / 3;
		i++;
	}
	ternary[i] = '\0';
	return (ternary);
}

char	**transform_rank_to_ternary(int len_list, int *list_rank)
{
	char	**list_rank_ternary;
	int		i;
	int		ternary_len;
	int		nb_el;

	ternary_len = 0;
	nb_el = len_list - 1;
	while (nb_el != 0)
	{
		nb_el = nb_el / 3;
		ternary_len++;
	}
	i = 0;
	list_rank_ternary = malloc((len_list + 1) * sizeof(char *));
	while (i < len_list)
	{	
		list_rank_ternary[i] = int_to_ternary(ternary_len, list_rank[i]);
		i++;
	}
	list_rank_ternary[i] = NULL;
	return (list_rank_ternary);
}

char	**init_aa(int len_list, char **list, int top_free_split)
{
	int		*list_int;
	int		*list_rank;
	char	**list_rank_ternary;

	list_int = transform_char_int(len_list, list);
	list_rank = get_rank(len_list, list_int);
	list_rank_ternary = transform_rank_to_ternary(len_list, list_rank);
	free(list_int);
	free(list_rank);
	if (top_free_split == 1)
		free_stack(list, len_list);
	return (list_rank_ternary);
}

char	**init_a(int len_list, char **list)
{
	char	**list_rank_ternary;
	int		top_free_split;

	top_free_split = 0;
	if (len_list == 1)
	{
		list = ft_split(list[0], ' ');
		top_free_split = 1;
		len_list = 0;
		while (list[len_list])
			len_list++;
	}
	if (check_all_error(len_list, list) != 0)
	{
		if (check_all_error(len_list, list) == 1)
			return (get_return_error(list, len_list, top_free_split));
		else
			return (get_order_return(list, len_list, top_free_split));
	}
	list_rank_ternary = init_aa(len_list, list, top_free_split);
	return (list_rank_ternary);
}
