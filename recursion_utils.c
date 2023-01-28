/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:17:53 by jhwang2           #+#    #+#             */
/*   Updated: 2023/01/27 11:53:36 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	part_of_data(t_swap *swap, int argc, int i)
{
	int	some;

	if (swap->start)
		return (part_of_data_s(swap, argc));
	else
	{
		some = 0;
		while (i < swap->num_of_tri / 3)
			some += swap->arr[0][i++];
		if (!swap->to_a)
		{
			swap->stack_a->numofdata = argc - some;
			swap->stack_b->numofdata = some;
		}
		else
		{
			swap->stack_a->numofdata = some;
			swap->stack_b->numofdata = argc - some;
		}
	}
	return (some);
}

int	part_of_data_s(t_swap *swap, int argc)
{
	swap->stack_b->numofdata = argc;
	if (swap->to_a)
	{
		swap->stack_a->numofdata = argc;
		swap->stack_b->numofdata = 0;
	}
	else
	{
		swap->stack_a->numofdata = 0;
		swap->stack_b->numofdata = argc;
	}
	return (argc);
}

void	setup_asc_or_des(t_swap *swap, int *check_rest, int i)
{
	long	min_or_max;

	if (swap->arr[1][i] == 1)
		min_or_max = LONG_MIN;
	else
		min_or_max = LONG_MAX;
	if (check_rest[i] == 5)
		data_in_five (swap, min_or_max);
	else if (check_rest[i] == 4)
		data_in_four (swap, min_or_max);
	else
		data_in_three (swap, check_rest, min_or_max, i);
}

void	asc_or_des(t_swap *swap, int *check_rest, int i)
{
	long	min_or_max;
	int		number;
	int		j;

	if (swap->arr[1][i] == 1)
		min_or_max = LONG_MIN;
	else
		min_or_max = LONG_MAX;
	j = 0;
	while (j < swap->arr[0][i])
	{
		number = compared_data (swap, check_rest, min_or_max, i);
		if (number == -1)
			return ;
		change_position (swap, number);
		check_rest[number + i]--;
		j++;
	}
}
