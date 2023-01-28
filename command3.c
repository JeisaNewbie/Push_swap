/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:17:04 by jhwang2           #+#    #+#             */
/*   Updated: 2023/01/28 23:35:32 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "share.h"

int	reverse_ra(t_list *stack)
{
	long	tmp;

	if (stack->cur == NULL)
		return (0);
	stack->cur = stack->head->before;
	tmp = stack->cur->data;
	while (stack->cur->check_dummy != 1)
	{
		stack->cur->data = stack->cur->before->data;
		stack->cur = stack->cur->before;
	}
	stack->cur->next->data = tmp;
	if (stack->head->flag)
		write (1, "rra\n", 4);
	return (1);
}

int	reverse_rb(t_list *stack)
{
	long	tmp;

	if (stack->cur == NULL)
		return (0);
	stack->cur = stack->head->before;
	tmp = stack->cur->data;
	while (stack->cur->check_dummy != 1)
	{
		stack->cur->data = stack->cur->before->data;
		stack->cur = stack->cur->before;
	}
	stack->cur->next->data = tmp;
	if (stack->head->flag)
		write (1, "rrb\n", 4);
	return (1);
}

int	reverse_rr(t_list *stack_a, t_list *stack_b)
{
	int	return_a;
	int	return_b;

	return_a = reverse_ra (stack_a);
	return_b = reverse_rb (stack_b);
	if (stack_a->head->flag)
		write (1, "rrr\n", 4);
	if (!return_a || !return_b)
		return (0);
	return (1);
}

void	double_rra(t_swap *swap)
{
	reverse_ra (swap->stack_a);
	reverse_ra (swap->stack_a);
}

void	double_rrb(t_swap *swap)
{
	reverse_rb (swap->stack_b);
	reverse_rb (swap->stack_b);
}
