/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:16:33 by jhwang2           #+#    #+#             */
/*   Updated: 2023/01/29 00:02:21 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "share.h"

void	simple_sort(t_swap *swap, int argc);
void	simple_sort_three(t_swap *swap);
void	simple_sort_three_one(t_swap *swap);
void	simple_sort_three_two(t_swap *swap);
void	simple_sort_three_three(t_swap *swap);
void	simple_sort_four(t_swap *swap);
void	simple_sort_four_one(t_swap *swap);
void	simple_sort_four_two(t_swap *swap);
void	simple_sort_four_three(t_swap *swap);
void	simple_sort_four_four(t_swap *swap);
void	simple_sort_five(t_swap *swap);
void	simple_sort_five_one(t_swap *swap);
void	simple_sort_five_two(t_swap *swap);
void	simple_sort_five_three(t_swap *swap);
void	simple_sort_five_four(t_swap *swap);
void	simple_sort_five_five(t_swap *swap);
void	data_in_five(t_swap *swap, long min_or_max);
void	sorting_five_to_a(t_swap *swap, long min_or_max);
void	sorting_five_to_b(t_swap *swap, long min_or_max);
void	sort_des_rest_datas(t_swap *swap);
void	sort_asc_rest_datas(t_swap *swap);
void	data_in_four(t_swap *swap, long min_or_max);
void	init_des_in_four(t_swap *swap);
void	init_asc_in_four(t_swap *swap);
void	sorting_four_to_a(t_swap *swap, long min_or_max);
void	sorting_four_to_b(t_swap *swap, long min_or_max);
void	init_des_in_four_to_a(t_swap *swap);
void	init_des_in_four_to_b(t_swap *swap);
void	init_asc_in_four_to_b(t_swap *swap);
void	init_asc_in_four_to_a(t_swap *swap);
void	data_in_three(t_swap *swap, int *check_rest, long min_or_max, int i);
void	sorting_two_to_a(t_swap *swap, long min_or_max);
void	sorting_two_to_b(t_swap *swap, long min_or_max);
void	sorting_three_to_a(t_swap *swap, long min_or_max);
void	sorting_three_to_b(t_swap *swap, long min_or_max);
void	init_des_five_to_a(t_swap *swap);
void	init_des_five_to_b(t_swap *swap);
void	init_asc_five_to_a(t_swap *swap);
void	init_asc_five_to_b(t_swap *swap);
void	init_asc_five_one(t_swap *swap);
void	init_asc_five_two(t_swap *swap);
void	init_asc_five_three(t_swap *swap);
void	init_asc_five_four(t_swap *swap);
void	init_asc_five_five(t_swap *swap);
void	init_des_five_one(t_swap *swap);
void	init_des_five_two(t_swap *swap);
void	init_des_five_three(t_swap *swap);
void	init_des_five_four(t_swap *swap);
void	init_des_five_five(t_swap *swap);
void	init_four_one(t_swap *swap);
void	init_four_two(t_swap *swap);
void	init_four_three(t_swap *swap);
void	init_four_four(t_swap *swap);
void	position_one(t_list *stack_a, t_list *stack_b, int to_a);
void	position_two(t_list *stack_a, t_list *stack_b, int to_a);
void	position_three(t_list *stack_a, t_list *stack_b, int to_a);
int		sort_start(t_swap *swap, int depth, int argc);
int		*move_datas(t_swap *swap, int argc);
int		setup_data(t_swap *swap, int *check_rest);
int		sort(t_swap *swap, int *check_rest);
int		part_of_data(t_swap *swap, int argc, int i);
int		part_of_data_s(t_swap *swap, int argc);
void	setup_asc_or_des(t_swap *swap, int *check_rest, int i);
void	asc_or_des(t_swap *swap, int *check_rest, int i);
void	sort_rest_des_five_one(t_swap *swap);
void	sort_rest_des_five_two(t_swap *swap);
void	sort_rest_asc_five_one(t_swap *swap);
void	sort_rest_asc_five_two(t_swap *swap);
void	sort_rest_des(t_swap *swap, long *abc);
void	sort_rest_asc(t_swap *swap, long *abc);
void	sort_three_one(t_swap *swap);
void	sort_three_two(t_swap *swap);
void	sort_three_three(t_swap *swap);
void	sort_three_four(t_swap *swap);
void	sort_three_five(t_swap *swap);
void	sort_three_six(t_swap *swap);
int		compared_data(t_swap *swap, int *check_rest, long min_or_max, int i);
int		biggest_data_in_three(t_swap *swap, int *check_rest,
			long biggest, int i);
int		smallest_data_in_three(t_swap *swap, int *check_rest,
			long smallest, int i);
void	init_three_data(t_swap *swap, long *data, long biggest_or_smallest);
void	change_position(t_swap *swap, int number);

#endif