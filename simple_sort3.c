/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:29:04 by jhwang2           #+#    #+#             */
/*   Updated: 2023/01/23 15:41:40 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_sort_five(t_swap *swap)
{
	long	a[5];

	a[0] = swap->stack_a->head->next->data;
	a[1] = swap->stack_a->head->next->next->data;
	a[2] = swap->stack_a->head->next->next->next->data;
	a[3] = swap->stack_a->head->before->data;
	a[4] = swap->stack_a->head->before->before->data;
	if (a[0] < a[1] && a[0] < a[2] && a[0] < a[3] && a[0] < a[4])
		simple_sort_five_one(swap);
	else if (a[1] < a[0] && a[1] < a[2] && a[1] < a[3] && a[1] < a[4])
		simple_sort_five_two(swap);
	else if (a[2] < a[0] && a[2] < a[1] && a[2] < a[3] && a[2] < a[4])
		simple_sort_five_three(swap);
	else if (a[3] < a[0] && a[3] < a[1] && a[3] < a[2] && a[3] < a[4])
		simple_sort_five_four(swap);
	else if (a[4] < a[0] && a[4] < a[1] && a[4] < a[2] && a[4] < a[3])
		simple_sort_five_five(swap);
}

void	simple_sort_five_one(t_swap *swap)
{
	push_b (swap->stack_b, swap->stack_a);
	simple_sort_four (swap);
	push_a (swap->stack_a, swap->stack_b);
}

void	simple_sort_five_two(t_swap *swap)
{
	swap_a (swap->stack_a->head);
	push_b (swap->stack_b, swap->stack_a);
	simple_sort_four (swap);
	push_a (swap->stack_a, swap->stack_b);
}
