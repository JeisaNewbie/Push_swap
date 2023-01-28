/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_in_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:17:08 by jhwang2           #+#    #+#             */
/*   Updated: 2023/01/27 11:49:25 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	data_in_five(t_swap *swap, long min_or_max)
{
	if (min_or_max == LONG_MAX)
	{
		if (swap->to_a)
			init_des_five_to_a (swap);
		else
			init_des_five_to_b (swap);
	}
	else
	{
		if (swap->to_a)
			init_asc_five_to_a (swap);
		else
			init_asc_five_to_b (swap);
	}
	if (swap->to_a)
		sorting_five_to_a (swap, min_or_max);
	else
		sorting_five_to_b (swap, min_or_max);
}

void	sorting_five_to_a(t_swap *swap, long min_or_max)
{
	long	abc[4];

	abc[0] = swap->stack_a->head->next->data;
	abc[1] = swap->stack_a->head->next->next->data;
	abc[2] = swap->stack_b->head->next->data;
	abc[3] = swap->stack_b->head->next->next->data;
	if (min_or_max == LONG_MAX)
		sort_rest_des_five_one (swap);
	else
		sort_rest_asc_five_one (swap);
	if (swap->start)
		swap->start = 0;
}

void	sorting_five_to_b(t_swap *swap, long min_or_max)
{
	long	abc[4];

	abc[0] = swap->stack_b->head->next->data;
	abc[1] = swap->stack_b->head->next->next->data;
	abc[2] = swap->stack_a->head->next->data;
	abc[3] = swap->stack_a->head->next->next->data;
	if (min_or_max == LONG_MAX)
		sort_rest_des_five_one (swap);
	else
		sort_rest_asc_five_one (swap);
	if (swap->start)
		swap->start = 0;
}

void	sort_des_rest_datas(t_swap *swap)
{
	long	a_or_b[4];

	a_or_b[0] = swap->stack_a->head->next->data;
	a_or_b[1] = swap->stack_a->head->next->next->data;
	a_or_b[2] = swap->stack_b->head->next->data;
	a_or_b[3] = swap->stack_b->head->next->next->data;
	if (swap->to_a)
	{
		if (a_or_b[0] < a_or_b[1])
			swap_a (swap->stack_a->head);
		if (a_or_b[2] > a_or_b[3])
			swap_b (swap->stack_b->head);
	}
	else
	{
		if (a_or_b[2] < a_or_b[3])
			swap_b (swap->stack_b->head);
		if (a_or_b[0] > a_or_b[1])
			swap_a (swap->stack_a->head);
	}
}

void	sort_asc_rest_datas(t_swap *swap)
{
	long	a_or_b[4];

	a_or_b[0] = swap->stack_a->head->next->data;
	a_or_b[1] = swap->stack_a->head->next->next->data;
	a_or_b[2] = swap->stack_b->head->next->data;
	a_or_b[3] = swap->stack_b->head->next->next->data;
	if (swap->to_a)
	{
		if (a_or_b[0] > a_or_b[1])
			swap_a (swap->stack_a->head);
		if (a_or_b[2] < a_or_b[3])
			swap_b (swap->stack_b->head);
	}
	else
	{
		if (a_or_b[2] > a_or_b[3])
			swap_b (swap->stack_b->head);
		if (a_or_b[0] < a_or_b[1])
			swap_a (swap->stack_a->head);
	}
}
