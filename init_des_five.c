/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_des_five.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:17:32 by jhwang2           #+#    #+#             */
/*   Updated: 2023/01/27 13:36:26 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_des_five_one(t_swap *swap)
{
	if (swap->to_a)
	{
		double_pa (swap);
		push_a (swap->stack_a, swap->stack_b);
		double_rrb (swap);
		sort_des_rest_datas (swap);
	}
	else
	{
		double_pb (swap);
		push_b (swap->stack_b, swap->stack_a);
		double_rra (swap);
		sort_des_rest_datas (swap);
	}
}

void	init_des_five_two(t_swap *swap)
{
	if (swap->to_a)
	{
		swap_b (swap->stack_b->head);
		double_pa (swap);
		push_a (swap->stack_a, swap->stack_b);
		double_rrb (swap);
		sort_des_rest_datas (swap);
	}
	else
	{
		swap_a (swap->stack_a->head);
		double_pb (swap);
		push_b (swap->stack_b, swap->stack_a);
		double_rra (swap);
		sort_des_rest_datas (swap);
	}
}

void	init_des_five_three(t_swap *swap)
{
	if (swap->to_a)
	{
		push_a (swap->stack_a, swap->stack_b);
		swap_b (swap->stack_b->head);
		push_a (swap->stack_a, swap->stack_b);
		swap_a (swap->stack_a->head);
		push_a (swap->stack_a, swap->stack_b);
		double_rrb (swap);
		sort_des_rest_datas (swap);
	}
	else
	{
		push_b (swap->stack_b, swap->stack_a);
		swap_a (swap->stack_a->head);
		push_b (swap->stack_b, swap->stack_a);
		swap_b (swap->stack_b->head);
		push_b (swap->stack_b, swap->stack_a);
		double_rra (swap);
		sort_des_rest_datas (swap);
	}
}

void	init_des_five_four(t_swap *swap)
{
	if (swap->to_a)
	{
		reverse_rb (swap->stack_b);
		push_a (swap->stack_a, swap->stack_b);
		reverse_rb (swap->stack_b);
		double_pa (swap);
		sort_des_rest_datas (swap);
	}
	else
	{
		reverse_ra (swap->stack_a);
		push_b (swap->stack_b, swap->stack_a);
		reverse_ra (swap->stack_a);
		double_pb (swap);
		sort_des_rest_datas (swap);
	}
}

void	init_des_five_five(t_swap *swap)
{
	if (swap->to_a)
	{
		double_rrb (swap);
		push_a (swap->stack_a, swap->stack_b);
		double_pa (swap);
		sort_des_rest_datas (swap);
	}
	else
	{
		double_rra (swap);
		push_b (swap->stack_b, swap->stack_a);
		double_pb (swap);
		sort_des_rest_datas (swap);
	}
}
