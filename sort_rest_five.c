/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rest_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:17:55 by jhwang2           #+#    #+#             */
/*   Updated: 2023/01/27 13:35:22 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_rest_des_five_one(t_swap *swap)
{
	if (swap->to_a)
	{
		if (swap->stack_a->head->next->data > swap->stack_b->head->next->data)
		{
			rotate_a (swap->stack_a);
			push_a (swap->stack_a, swap->stack_b);
			if (swap->stack_a->head->next->data
				< swap->stack_a->head->next->next->data)
				swap_a (swap->stack_a->head);
			push_a (swap->stack_a, swap->stack_b);
			if (swap->stack_a->head->next->data
				< swap->stack_a->head->next->next->data)
				swap_a (swap->stack_a->head);
			reverse_ra (swap->stack_a);
			if (swap->stack_a->head->next->data
				< swap->stack_a->head->next->next->data)
				swap_a (swap->stack_a->head);
		}
		else
			double_pa (swap);
	}
	else
		sort_rest_des_five_two (swap);
}

void	sort_rest_des_five_two(t_swap *swap)
{
	if (swap->stack_b->head->next->data > swap->stack_a->head->next->data)
	{
		rotate_b (swap->stack_b);
		push_b (swap->stack_b, swap->stack_a);
		if (swap->stack_b->head->next->data
			< swap->stack_b->head->next->next->data)
			swap_b (swap->stack_b->head);
		push_b (swap->stack_b, swap->stack_a);
		if (swap->stack_b->head->next->data
			< swap->stack_b->head->next->next->data)
			swap_b (swap->stack_b->head);
		reverse_rb (swap->stack_b);
		if (swap->stack_b->head->next->data
			< swap->stack_b->head->next->next->data)
			swap_b (swap->stack_b->head);
	}
	else
		double_pb (swap);
}

void	sort_rest_asc_five_one(t_swap *swap)
{
	if (swap->to_a)
	{
		if (swap->stack_a->head->next->data < swap->stack_b->head->next->data)
		{
			rotate_a (swap->stack_a);
			push_a (swap->stack_a, swap->stack_b);
			if (swap->stack_a->head->next->data
				> swap->stack_a->head->next->next->data)
				swap_a (swap->stack_a->head);
			push_a (swap->stack_a, swap->stack_b);
			if (swap->stack_a->head->next->data
				> swap->stack_a->head->next->next->data)
				swap_a (swap->stack_a->head);
			reverse_ra (swap->stack_a);
			if (swap->stack_a->head->next->data
				> swap->stack_a->head->next->next->data)
				swap_a (swap->stack_a->head);
		}
		else
			double_pa (swap);
	}
	else
		sort_rest_asc_five_two (swap);
}

void	sort_rest_asc_five_two(t_swap *swap)
{
	if (swap->stack_b->head->next->data < swap->stack_a->head->next->data)
	{
		rotate_b (swap->stack_b);
		push_b (swap->stack_b, swap->stack_a);
		if (swap->stack_b->head->next->data
			> swap->stack_b->head->next->next->data)
			swap_b (swap->stack_b->head);
		push_b (swap->stack_b, swap->stack_a);
		if (swap->stack_b->head->next->data
			> swap->stack_b->head->next->next->data)
			swap_b (swap->stack_b->head);
		reverse_rb (swap->stack_b);
		if (swap->stack_b->head->next->data
			> swap->stack_b->head->next->next->data)
			swap_b (swap->stack_b->head);
	}
	else
		double_pb (swap);
}
