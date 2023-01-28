/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:35:07 by jhwang2           #+#    #+#             */
/*   Updated: 2023/01/27 12:03:03 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_sort_five_three(t_swap *swap)
{
	rotate_a(swap->stack_a);
	swap_a (swap->stack_a->head);
	push_b (swap->stack_b, swap->stack_a);
	reverse_ra(swap->stack_a);
	simple_sort_four (swap);
	push_a (swap->stack_a, swap->stack_b);
}

void	simple_sort_five_four(t_swap *swap)
{
	reverse_ra(swap->stack_a);
	push_b (swap->stack_b, swap->stack_a);
	simple_sort_four (swap);
	push_a (swap->stack_a, swap->stack_b);
}

void	simple_sort_five_five(t_swap *swap)
{
	reverse_ra(swap->stack_a);
	reverse_ra(swap->stack_a);
	push_b (swap->stack_b, swap->stack_a);
	simple_sort_four (swap);
	push_a (swap->stack_a, swap->stack_b);
}
