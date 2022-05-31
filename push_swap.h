/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssef <youssef.boughanmi.pro@gmail.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 18:01:09 by youssef           #+#    #+#             */
/*   Updated: 2022/05/31 20:08:46 by Youssef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>

int		*transform_char_int(int len_list, char **list);
int		*get_rank(int len_list, int *list_int);
int		get_ternary_len(int nb_el);
void	swap(char **stack, char stack_name);
void	double_swap(char **stack_a, char **stack_b);
void	free_stack(char **stack, int nb_el);
char	**init_b(int nb_el, int ternary_len);
char	*int_to_ternary(int max_len, int number);
char	**transform_rank_to_ternary(int len_list, int *list_rank);
char	**init_a(int len_list, char **list);
int		len_stack(char **stack);
void	do_push(char **stack_src, char **stack_dest);
void	push(char **stack_src, char **stack_dest, char stack_src_name);
void	do_rotate(char **stack);
void	rotate(char **stack, char stack_name);
void	double_rotate(char **stack_a, char **stack_b);
void	do_swap(char **stack);
void	do_reverse(char **stack);
void	reverse(char **stack, char stack_name);
void	double_reverse(char **stack_a, char **stack_b);
char	**get_return_error(void);
int		check_double(int len_list, int *list_int);
int		check_digital_condition(int len_list, char **list);
int		check_biginit_condition(int len_list, char **list);
int		ft_is_big_int(char *number);
void	push_swap(char **stack_a, char **stack_b, int ternary_len);
void	pw_second_st(char **stack_a, char **stack_b, int pos, int ternary_len);
void	pw_first_step(char **stack_a, char **stack_b, int pos);
int		is_greater(char *el_1, char *el_2);
void	pw_low_first_step(char **stack_a, char **stack_b);
void	pw_low_second_step(char **stack_a, char **stack_b);
void	push_swap_low(char **stack_a, char **stack_b, int nb_el);
int		check_minus_error(int len_list, char **list);
char	**get_order_return(void);
int		*transform_char_int(int len_list, char **list);
int		check_all_error(int len_list, char **list);
int		check_order(int len_list, int *list);

#endif
