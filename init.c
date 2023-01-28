/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:17:37 by jhwang2           #+#    #+#             */
/*   Updated: 2023/01/29 00:55:05 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "share.h"

t_list	*init_stack(int flag)
{
	t_list	*stack;

	stack = (t_list *)malloc (sizeof (t_list));
	if (stack == NULL)
		print_error();
	stack->head = (t_node *)malloc(sizeof (t_node));
	if (stack->head == NULL)
		print_error();
	stack->head->next = NULL;
	stack->head->before = NULL;
	stack->head->data = 0;
	stack->head->check_dummy = 1;
	stack->head->flag = flag;
	stack->cur = NULL;
	stack->numofdata = 0;
	stack->start = 1;
	return (stack);
}

int	*create_idx(void)
{
	int	*idx;

	idx = (int *)malloc (sizeof (int) * 3);
	if (idx == NULL)
		print_error();
	idx[0] = 0;
	idx[1] = 1;
	idx[2] = 2;
	return (idx);
}

int	**create_arr(int n)
{
	int	**arr;

	arr = (int **) malloc(sizeof (int *) * 2);
	if (arr == NULL)
		print_error();
	arr[0] = (int *)malloc (sizeof (int) * n);
	arr[1] = (int *)malloc (sizeof (int) * n);
	if (arr[0] == NULL || arr[1] == NULL)
		print_error();
	arr[1][0] = 1;
	return (arr);
}

t_swap	*init_swap(int argc, int flag)
{
	t_swap	*swap;

	swap = (t_swap *)malloc (sizeof (t_swap));
	if (!swap)
		print_error();
	swap->stack_a = init_stack (flag);
	swap->stack_b = init_stack (flag);
	swap->arr = create_arr (check_struct (swap, argc, &swap->depth));
	swap->idx = create_idx ();
	return (swap);
}
