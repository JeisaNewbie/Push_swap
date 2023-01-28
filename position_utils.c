/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:17:46 by jhwang2           #+#    #+#             */
/*   Updated: 2023/01/22 18:17:47 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	position_one(t_list *stack_a, t_list *stack_b, int to_a)
{
	if (to_a)
	{
		reverse_ra (stack_a);
		if (stack_a->head->data == 0)
			stack_a->head->data = stack_a->head->next->data;
	}
	else
	{
		reverse_rb (stack_b);
		if (stack_b->head->data == 0)
			stack_b->head->data = stack_b->head->next->data;
	}
	return ;
}

void	position_two(t_list *stack_a, t_list *stack_b, int to_a)
{
	if (to_a)
	{
		push_a (stack_a, stack_b);
		if (stack_a->head->data == 0)
			stack_a->head->data = stack_a->head->next->data;
	}
	else
	{
		push_b (stack_b, stack_a);
		if (stack_b->head->data == 0)
			stack_b->head->data = stack_b->head->next->data;
	}
}

void	position_three(t_list *stack_a, t_list *stack_b, int to_a)
{
	if (to_a)
	{
		reverse_rb (stack_b);
		push_a (stack_a, stack_b);
		if (stack_a->head->data == 0)
			stack_a->head->data = stack_a->head->next->data;
	}
	else
	{
		reverse_ra (stack_a);
		push_b (stack_b, stack_a);
		if (stack_b->head->data == 0)
			stack_b->head->data = stack_b->head->next->data;
	}
}
