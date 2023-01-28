/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:17:34 by jhwang2           #+#    #+#             */
/*   Updated: 2023/01/22 18:17:35 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_four_one(t_swap *swap)
{
	if (swap->to_a)
	{
		push_a (swap->stack_a, swap->stack_b);
		push_a (swap->stack_a, swap->stack_b);
		reverse_rb (swap->stack_b);
		reverse_rb (swap->stack_b);
	}
	else
	{
		push_b (swap->stack_b, swap->stack_a);
		push_b (swap->stack_b, swap->stack_a);
		reverse_ra (swap->stack_a);
		reverse_ra (swap->stack_a);
	}
}

void	init_four_two(t_swap *swap)
{
	if (swap->to_a)
	{
		push_a (swap->stack_a, swap->stack_b);
		push_a (swap->stack_a, swap->stack_b);
		swap_a (swap->stack_a->head);
		reverse_rb (swap->stack_b);
		reverse_rb (swap->stack_b);
	}
	else
	{
		push_b (swap->stack_b, swap->stack_a);
		push_b (swap->stack_b, swap->stack_a);
		swap_b (swap->stack_b->head);
		reverse_ra (swap->stack_a);
		reverse_ra (swap->stack_a);
	}
}

void	init_four_three(t_swap *swap)
{
	if (swap->to_a)
	{
		reverse_rb (swap->stack_b);
		push_a (swap->stack_a, swap->stack_b);
		reverse_rb (swap->stack_b);
		push_a (swap->stack_a, swap->stack_b);
	}
	else
	{
		reverse_ra (swap->stack_a);
		push_b (swap->stack_b, swap->stack_a);
		reverse_ra (swap->stack_a);
		push_b (swap->stack_b, swap->stack_a);
	}
}

void	init_four_four(t_swap *swap)
{
	if (swap->to_a)
	{
		reverse_rb (swap->stack_b);
		reverse_rb (swap->stack_b);
		push_a (swap->stack_a, swap->stack_b);
		push_a (swap->stack_a, swap->stack_b);
	}
	else
	{
		reverse_ra (swap->stack_a);
		reverse_ra (swap->stack_a);
		push_b (swap->stack_b, swap->stack_a);
		push_b (swap->stack_b, swap->stack_a);
	}
}
