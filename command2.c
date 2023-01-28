/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:17:01 by jhwang2           #+#    #+#             */
/*   Updated: 2023/01/28 23:34:57 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "share.h"

int	rotate_a(t_list *stack)
{
	long	tmp;

	if (stack->cur == NULL)
		return (0);
	stack->cur = stack->head->next;
	tmp = stack->cur->data;
	while (stack->cur->check_dummy != 1)
	{
		stack->cur->data = stack->cur->next->data;
		stack->cur = stack->cur->next;
	}
	stack->cur->before->data = tmp;
	if (stack->head->flag)
		write (1, "ra\n", 3);
	return (1);
}

int	rotate_b(t_list *stack)
{
	long	tmp;

	if (stack->cur == NULL)
		return (0);
	stack->cur = stack->head->next;
	tmp = stack->cur->data;
	while (stack->cur->check_dummy != 1)
	{
		stack->cur->data = stack->cur->next->data;
		stack->cur = stack->cur->next;
	}
	stack->cur->before->data = tmp;
	if (stack->head->flag)
		write (1, "rb\n", 3);
	return (1);
}

int	rr(t_list *stack_a, t_list *stack_b)
{
	int	return_a;
	int	return_b;

	return_a = rotate_a(stack_a);
	return_b = rotate_b(stack_b);
	if (stack_a->head->flag)
		write (1, "rr\n", 3);
	if (!return_a || !return_b)
		return (0);
	return (1);
}

void	double_pa(t_swap *swap)
{
	push_a (swap->stack_a, swap->stack_b);
	push_a (swap->stack_a, swap->stack_b);
}

void	double_pb(t_swap *swap)
{
	push_b (swap->stack_b, swap->stack_a);
	push_b (swap->stack_b, swap->stack_a);
}
