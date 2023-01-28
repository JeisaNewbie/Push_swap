/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:15:05 by jhwang2           #+#    #+#             */
/*   Updated: 2023/01/23 15:38:40 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_sort_four(t_swap *swap)
{
	long	a[4];

	a[0] = swap->stack_a->head->next->data;
	a[1] = swap->stack_a->head->next->next->data;
	a[2] = swap->stack_a->head->before->data;
	a[3] = swap->stack_a->head->before->before->data;
	if (a[0] < a[1] && a[0] < a[2] && a[0] < a[3])
		simple_sort_four_one(swap);
	else if (a[1] < a[0] && a[1] < a[2] && a[1] < a[3])
		simple_sort_four_two(swap);
	else if (a[2] < a[0] && a[2] < a[1] && a[2] < a[3])
		simple_sort_four_three(swap);
	else if (a[3] < a[0] && a[3] < a[1] && a[3] < a[2])
		simple_sort_four_four(swap);
}

void	simple_sort_four_one(t_swap *swap)
{
	push_b (swap->stack_b, swap->stack_a);
	simple_sort_three (swap);
	push_a (swap->stack_a, swap->stack_b);
}

void	simple_sort_four_two(t_swap *swap)
{
	swap_a (swap->stack_a->head);
	push_b (swap->stack_b, swap->stack_a);
	simple_sort_three (swap);
	push_a (swap->stack_a, swap->stack_b);
}

void	simple_sort_four_three(t_swap *swap)
{
	reverse_ra(swap->stack_a);
	push_b (swap->stack_b, swap->stack_a);
	simple_sort_three (swap);
	push_a (swap->stack_a, swap->stack_b);
}

void	simple_sort_four_four(t_swap *swap)
{
	reverse_ra(swap->stack_a);
	reverse_ra(swap->stack_a);
	push_b (swap->stack_b, swap->stack_a);
	simple_sort_three (swap);
	push_a (swap->stack_a, swap->stack_b);
}
