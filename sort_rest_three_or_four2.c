/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rest_three_or_four2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:18:00 by jhwang2           #+#    #+#             */
/*   Updated: 2023/01/22 18:18:01 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_two(t_swap *swap)
{
	if (swap->to_a)
	{
		push_a (swap->stack_a, swap->stack_b);
		push_a (swap->stack_a, swap->stack_b);
		swap_a (swap->stack_a->head);
	}
	else
	{
		push_b (swap->stack_b, swap->stack_a);
		push_b (swap->stack_b, swap->stack_a);
		swap_b (swap->stack_b->head);
	}
}

void	sort_three_three(t_swap *swap)
{
	if (swap->to_a)
	{
		push_a (swap->stack_a, swap->stack_b);
		swap_a (swap->stack_a->head);
		push_a (swap->stack_a, swap->stack_b);
	}
	else
	{
		push_b (swap->stack_b, swap->stack_a);
		swap_b (swap->stack_b->head);
		push_b (swap->stack_b, swap->stack_a);
	}
}

void	sort_three_four(t_swap *swap)
{
	if (swap->to_a)
	{
		push_a (swap->stack_a, swap->stack_b);
		swap_a (swap->stack_a->head);
		push_a (swap->stack_a, swap->stack_b);
		swap_a (swap->stack_a->head);
	}
	else
	{
		push_b (swap->stack_b, swap->stack_a);
		swap_b (swap->stack_b->head);
		push_b (swap->stack_b, swap->stack_a);
		swap_b (swap->stack_b->head);
	}
}

void	sort_three_five(t_swap *swap)
{
	if (swap->to_a)
	{
		swap_b (swap->stack_b->head);
		push_a (swap->stack_a, swap->stack_b);
		swap_a (swap->stack_a->head);
		push_a (swap->stack_a, swap->stack_b);
	}
	else
	{
		swap_a (swap->stack_a->head);
		push_b (swap->stack_b, swap->stack_a);
		swap_b (swap->stack_b->head);
		push_b (swap->stack_b, swap->stack_a);
	}
}

void	sort_three_six(t_swap *swap)
{
	if (swap->to_a)
	{
		swap_b (swap->stack_b->head);
		push_a (swap->stack_a, swap->stack_b);
		swap_a (swap->stack_a->head);
		push_a (swap->stack_a, swap->stack_b);
		swap_a (swap->stack_a->head);
	}
	else
	{
		swap_a (swap->stack_a->head);
		push_b (swap->stack_b, swap->stack_a);
		swap_b (swap->stack_b->head);
		push_b (swap->stack_b, swap->stack_a);
		swap_b (swap->stack_b->head);
	}
}
