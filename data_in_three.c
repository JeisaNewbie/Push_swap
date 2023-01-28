/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_in_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:17:19 by jhwang2           #+#    #+#             */
/*   Updated: 2023/01/27 13:13:07 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	data_in_three(t_swap *swap, int *check_rest, long min_or_max, int i)
{
	if (check_rest[i] == 3)
	{
		if (swap->to_a)
			sorting_three_to_a (swap, min_or_max);
		else
			sorting_three_to_b (swap, min_or_max);
	}
	else if (check_rest[i] == 2)
	{
		if (swap->to_a)
			sorting_two_to_a (swap, min_or_max);
		else
			sorting_two_to_b (swap, min_or_max);
	}
	else
	{
		if (swap->to_a)
			push_a (swap->stack_a, swap->stack_b);
		else
			push_b (swap->stack_b, swap->stack_a);
	}
}

void	sorting_two_to_a(t_swap *swap, long min_or_max)
{
	long	a[2];

	push_a (swap->stack_a, swap->stack_b);
	push_a (swap->stack_a, swap->stack_b);
	a[0] = swap->stack_a->head->next->data;
	a[1] = swap->stack_a->head->next->next->data;
	if (min_or_max == LONG_MAX)
	{
		if (a[0] < a[1])
			swap_a (swap->stack_a->head);
	}
	else
	{
		if (a[0] > a[1])
			swap_a (swap->stack_a->head);
	}
}

void	sorting_two_to_b(t_swap *swap, long min_or_max)
{
	long	b[2];

	push_b (swap->stack_b, swap->stack_a);
	push_b (swap->stack_b, swap->stack_a);
	b[0] = swap->stack_b->head->next->data;
	b[1] = swap->stack_b->head->next->next->data;
	if (min_or_max == LONG_MAX)
	{
		if (b[0] < b[1])
			swap_b (swap->stack_b->head);
	}
	else
	{
		if (b[0] > b[1])
			swap_b (swap->stack_b->head);
	}
}

void	sorting_three_to_a(t_swap *swap, long min_or_max)
{
	long	abc[3];

	push_a (swap->stack_a, swap->stack_b);
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

void	sorting_three_to_b(t_swap *swap, long min_or_max)
{
	long	abc[3];

	push_b (swap->stack_b, swap->stack_a);
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
