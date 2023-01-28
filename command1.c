/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:16:56 by jhwang2           #+#    #+#             */
/*   Updated: 2023/01/28 23:34:11 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "share.h"

int	swap_a(t_node *dummy)
{
	long	tmp;

	if (dummy->next == NULL || dummy->next->next->check_dummy)
		return (0);
	tmp = dummy->next->next->data;
	dummy->next->next->data = dummy->next->data;
	dummy->next->data = tmp;
	if (dummy->flag)
		write (1, "sa\n", 3);
	return (1);
}

int	swap_b(t_node *dummy)
{
	long	tmp;

	if (dummy->next == NULL || dummy->next->next->check_dummy)
		return (0);
	tmp = dummy->next->next->data;
	dummy->next->next->data = dummy->next->data;
	dummy->next->data = tmp;
	if (dummy->flag)
		write (1, "sb\n", 3);
	return (1);
}

int	ss(t_node *dummy_a, t_node *dummy_b)
{
	if (dummy_a->next == NULL || dummy_a->next->next == NULL)
		return (0);
	if (dummy_b->next == NULL || dummy_b->next->next == NULL)
		return (0);
	swap_a(dummy_a);
	swap_b(dummy_b);
	if (dummy_a->flag)
		write (1, "ss\n", 3);
	return (1);
}

int	push_a(t_list *stack_a, t_list *stack_b)
{
	if (stack_b->head->next == NULL)
		return (0);
	list_insert(stack_a, stack_b->head->next->data);
	list_remove (stack_b->head->next);
	if (stack_b->head->next == NULL)
	{
		stack_b->start = 1;
		stack_b->cur = NULL;
	}
	else
		stack_b->cur = stack_b->head->next;
	if (stack_a->head->flag)
		write (1, "pa\n", 3);
	return (1);
}

int	push_b(t_list *stack_b, t_list *stack_a)
{
	if (stack_a->head->next == NULL)
		return (0);
	list_insert(stack_b, stack_a->head->next->data);
	list_remove (stack_a->head->next);
	if (stack_a->head->next == NULL)
	{
		stack_a->start = 1;
		stack_a->cur = NULL;
	}
	else
		stack_a->cur = stack_a->head->next;
	if (stack_a->head->flag)
		write (1, "pb\n", 3);
	return (1);
}
