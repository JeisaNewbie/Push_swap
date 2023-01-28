/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:17:49 by jhwang2           #+#    #+#             */
/*   Updated: 2023/01/29 04:46:06 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_swap	*swap;
	int		i;

	argv = init_input (&argc, argv);
	if (!argv)
		return (0);
	if (!check_error (argc, argv, 0, 1))
	{
		write (2, "Error\n", 6);
		return (0);
	}
	swap = init_swap (argc, 1);
	i = argc - 1;
	while (i >= 0)
		list_insert (swap->stack_a, ft_atoi(argv[i--], 1, 0));
	if (argc <= 5)
	{
		simple_sort (swap, argc);
		free_all (argv, swap);
		return (0);
	}
	divide (argc, swap->arr, swap->idx, swap->depth);
	sort_start (swap, swap->depth, argc);
	free_all (argv, swap);
	return (0);
}

int	sort_start(t_swap *swap, int depth, int argc)
{
	int	*check_rest;

	if (depth == 0)
	{
		check_rest = move_datas (swap, argc);
		setup_data (swap, check_rest);
		free (check_rest);
		return (1);
	}
	sort_start (swap, depth - 1, argc);
	check_rest = move_datas (swap, argc);
	sort (swap, check_rest);
	free (check_rest);
	return (1);
}

int	*move_datas(t_swap *swap, int argc)
{
	int	*check_rest;
	int	sorted_datas;
	int	i;

	check_rest = (int *)malloc (sizeof (int) * swap->num_of_tri);
	if (check_rest == NULL)
		print_error();
	i = 0;
	sorted_datas = part_of_data (swap, argc, i);
	while (i < sorted_datas)
	{
		if (!swap->start)
		{
			if (!swap->to_a)
				push_b (swap->stack_b, swap->stack_a);
			else
				push_a (swap->stack_a, swap->stack_b);
		}
		else if (swap->to_a && swap->start)
			push_b (swap->stack_b, swap->stack_a);
		i++;
	}
	swap->stack_a->head->data = 0;
	swap->stack_b->head->data = 0;
	return (check_rest);
}

int	setup_data(t_swap *swap, int *check_rest)
{
	int	i;

	i = 0;
	while (i < swap->num_of_tri)
	{
		check_rest[i] = swap->arr[0][i];
		i++;
	}
	i = 0;
	while (i < swap->num_of_tri)
	{
		setup_asc_or_des (swap, check_rest, i);
		i++;
	}
	swap->to_a = !swap->to_a;
	if (swap->start)
		swap->start = 0;
	return (1);
}

int	sort(t_swap *swap, int *check_rest)
{
	int	i;

	i = 0;
	while (i < swap->num_of_tri)
	{
		check_rest[i] = swap->arr[0][i];
		if (!swap->start && i < swap->num_of_tri / 3)
			swap->arr[0][i] = swap->arr[0][i]
				+ swap->arr[0][i + (swap->num_of_tri / 3)]
				+ swap->arr[0][i + (swap->num_of_tri / 3) * 2];
		i++;
	}
	i = 0;
	while (i < swap->num_of_tri / 3)
	{
		asc_or_des (swap, check_rest, i);
		i++;
	}
	if (!swap->start)
		swap->num_of_tri = swap->num_of_tri / 3;
	swap->to_a = !swap->to_a;
	return (1);
}
