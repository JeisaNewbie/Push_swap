/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_in_four2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:17:16 by jhwang2           #+#    #+#             */
/*   Updated: 2023/01/22 18:17:17 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_des_in_four_to_a(t_swap *swap)
{
	long	data[4];

	data[0] = swap->stack_b->head->next->data;
	data[1] = swap->stack_b->head->next->next->data;
	data[2] = swap->stack_b->head->before->data;
	data[3] = swap->stack_b->head->before->before->data;
	if (data[0] < data[1] && data[0] < data[2] && data[0] < data[3])
		init_four_one (swap);
	else if (data[1] < data[0] && data[1] < data[2] && data[1] < data[3])
		init_four_two (swap);
	else if (data[2] < data[0] && data[2] < data[1] && data[2] < data[3])
		init_four_three (swap);
	else if (data[3] < data[0] && data[3] < data[1] && data[3] < data[2])
		init_four_four (swap);
}

void	init_des_in_four_to_b(t_swap *swap)
{
	long	data[4];

	data[0] = swap->stack_a->head->next->data;
	data[1] = swap->stack_a->head->next->next->data;
	data[2] = swap->stack_a->head->before->data;
	data[3] = swap->stack_a->head->before->before->data;
	if (data[0] < data[1] && data[0] < data[2] && data[0] < data[3])
		init_four_one (swap);
	else if (data[1] < data[0] && data[1] < data[2] && data[1] < data[3])
		init_four_two (swap);
	else if (data[2] < data[0] && data[2] < data[1] && data[2] < data[3])
		init_four_three (swap);
	else if (data[3] < data[0] && data[3] < data[1] && data[3] < data[2])
		init_four_four (swap);
}

void	init_asc_in_four_to_b(t_swap *swap)
{
	long	data[4];

	data[0] = swap->stack_a->head->next->data;
	data[1] = swap->stack_a->head->next->next->data;
	data[2] = swap->stack_a->head->before->data;
	data[3] = swap->stack_a->head->before->before->data;
	if (data[0] > data[1] && data[0] > data[2] && data[0] > data[3])
		init_four_one (swap);
	else if (data[1] > data[0] && data[1] > data[2] && data[1] > data[3])
		init_four_two (swap);
	else if (data[2] > data[0] && data[2] > data[1] && data[2] > data[3])
		init_four_three (swap);
	else if (data[3] > data[0] && data[3] > data[1] && data[3] > data[2])
		init_four_four (swap);
}

void	init_asc_in_four_to_a(t_swap *swap)
{
	long	data[4];

	data[0] = swap->stack_b->head->next->data;
	data[1] = swap->stack_b->head->next->next->data;
	data[2] = swap->stack_b->head->before->data;
	data[3] = swap->stack_b->head->before->before->data;
	if (data[0] > data[1] && data[0] > data[2] && data[0] > data[3])
		init_four_one (swap);
	else if (data[1] > data[0] && data[1] > data[2] && data[1] > data[3])
		init_four_two (swap);
	else if (data[2] > data[0] && data[2] > data[1] && data[2] > data[3])
		init_four_three (swap);
	else if (data[3] > data[0] && data[3] > data[1] && data[3] > data[2])
		init_four_four (swap);
}
