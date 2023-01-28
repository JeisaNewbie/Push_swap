/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:18:03 by jhwang2           #+#    #+#             */
/*   Updated: 2023/01/22 18:18:04 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compared_data(t_swap *swap, int *check_rest, long min_or_max, int i)
{
	if (min_or_max == LONG_MAX)
		return (smallest_data_in_three (swap, check_rest, min_or_max, i));
	else
		return (biggest_data_in_three (swap, check_rest, min_or_max, i));
}

int	biggest_data_in_three(t_swap *swap, int *check_rest, long biggest, int i)
{
	long	data[3];
	int		biggest_idx;
	int		j;

	j = 0;
	init_three_data (swap, data, biggest);
	while (j < 3)
	{
		if (biggest < data[j] && check_rest[i + (j * (swap->num_of_tri / 3))])
		{
			biggest = data[j];
			biggest_idx = j;
		}
		j++;
	}
	if (biggest == LONG_MIN)
		return (-1);
	else
		return (biggest_idx * (swap->num_of_tri / 3));
}

int	smallest_data_in_three(t_swap *swap, int *check_rest, long smallest, int i)
{
	long	data[3];
	int		smallest_idx;
	int		j;

	j = 0;
	init_three_data (swap, data, smallest);
	while (j < 3)
	{
		if (smallest > data[j] && check_rest[i + (j * (swap->num_of_tri / 3))])
		{
			smallest = data[j];
			smallest_idx = j;
		}
		j++;
	}
	if (smallest == LONG_MAX)
		return (-1);
	else
		return (smallest_idx * (swap->num_of_tri / 3));
}

void	init_three_data(t_swap *swap, long *data, long biggest_or_smallest)
{
	if (swap->to_a)
	{
		data[0] = swap->stack_a->head->before->data;
		if (swap->stack_b->head->next == NULL)
		{
			data[1] = biggest_or_smallest;
			data[2] = biggest_or_smallest;
			return ;
		}
		data[1] = swap->stack_b->head->next->data;
		data[2] = swap->stack_b->head->before->data;
	}
	else
	{
		data[0] = swap->stack_b->head->before->data;
		if (swap->stack_a->head->next == NULL)
		{
			data[1] = biggest_or_smallest;
			data[2] = biggest_or_smallest;
			return ;
		}
		data[1] = swap->stack_a->head->next->data;
		data[2] = swap->stack_a->head->before->data;
	}
	return ;
}

void	change_position(t_swap *swap, int number)
{
	if (number == 0)
		position_one (swap->stack_a, swap->stack_b, swap->to_a);
	else if (number == (swap->num_of_tri / 3))
		position_two (swap->stack_a, swap->stack_b, swap->to_a);
	else if (number == (swap->num_of_tri / 3) * 2)
		position_three (swap->stack_a, swap->stack_b, swap->to_a);
	return ;
}
