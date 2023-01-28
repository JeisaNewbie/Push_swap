/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:15:01 by jhwang2           #+#    #+#             */
/*   Updated: 2023/01/23 15:29:13 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_sort(t_swap *swap, int argc)
{
	if (argc == 2)
		swap_a (swap->stack_a->head);
	else if (argc == 3)
		simple_sort_three (swap);
	else if (argc == 4)
		simple_sort_four (swap);
	else
		simple_sort_five (swap);
}

void	simple_sort_three(t_swap *swap)
{
	long	a[3];

	a[0] = swap->stack_a->head->next->data;
	a[1] = swap->stack_a->head->next->next->data;
	a[2] = swap->stack_a->head->next->next->next->data;
	if (a[0] < a[1] && a[0] < a[2])
		simple_sort_three_one(swap);
	else if (a[1] < a[0] && a[1] < a[2])
		simple_sort_three_two(swap);
	else if (a[2] < a[0] && a[2] < a[1])
		simple_sort_three_three(swap);
}

void	simple_sort_three_one(t_swap *swap)
{
	long	a[2];

	rotate_a (swap->stack_a);
	a[0] = swap->stack_a->head->next->data;
	a[1] = swap->stack_a->head->next->next->data;
	if (a[0] > a[1])
		swap_a (swap->stack_a->head);
	reverse_ra(swap->stack_a);
}

void	simple_sort_three_two(t_swap *swap)
{
	long	a[2];

	reverse_ra(swap->stack_a);
	a[0] = swap->stack_a->head->next->data;
	a[1] = swap->stack_a->head->next->next->data;
	if (a[0] > a[1])
		swap_a (swap->stack_a->head);
	reverse_ra(swap->stack_a);
}

void	simple_sort_three_three(t_swap *swap)
{
	long	a[2];

	a[0] = swap->stack_a->head->next->data;
	a[1] = swap->stack_a->head->next->next->data;
	if (a[0] > a[1])
		swap_a (swap->stack_a->head);
	reverse_ra(swap->stack_a);
}
