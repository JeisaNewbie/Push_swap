/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_in_four1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:17:12 by jhwang2           #+#    #+#             */
/*   Updated: 2023/01/27 11:51:29 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	data_in_four(t_swap *swap, long min_or_max)
{
	if (min_or_max == LONG_MAX)
		init_des_in_four (swap);
	else
		init_asc_in_four (swap);
	if (swap->to_a)
		sorting_four_to_a (swap, min_or_max);
	else
		sorting_four_to_b (swap, min_or_max);
}

void	init_des_in_four(t_swap *swap)
{
	if (swap->to_a)
		init_des_in_four_to_a (swap);
	else
		init_des_in_four_to_b (swap);
}

void	init_asc_in_four(t_swap *swap)
{
	if (swap->to_a)
		init_asc_in_four_to_a (swap);
	else
		init_asc_in_four_to_b (swap);
}

void	sorting_four_to_a(t_swap *swap, long min_or_max)
{
	long	abc[3];

	abc[0] = swap->stack_a->head->next->data;
	abc[1] = swap->stack_b->head->next->data;
	abc[2] = swap->stack_b->head->next->next->data;
	if (min_or_max == LONG_MAX)
		sort_rest_des (swap, abc);
	else
		sort_rest_asc (swap, abc);
	if (swap->start)
		swap->start = 0;
}

void	sorting_four_to_b(t_swap *swap, long min_or_max)
{
	long	abc[3];

	abc[0] = swap->stack_b->head->next->data;
	abc[1] = swap->stack_a->head->next->data;
	abc[2] = swap->stack_a->head->next->next->data;
	if (min_or_max == LONG_MAX)
		sort_rest_des (swap, abc);
	else
		sort_rest_asc (swap, abc);
	if (swap->start)
		swap->start = 0;
}
