/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_asc_or_des_five.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:17:29 by jhwang2           #+#    #+#             */
/*   Updated: 2023/01/22 18:17:29 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_des_five_to_a(t_swap *swap)
{
	long	data[5];

	data[0] = swap->stack_b->head->next->data;
	data[1] = swap->stack_b->head->next->next->data;
	data[2] = swap->stack_b->head->next->next->next->data;
	data[3] = swap->stack_b->head->before->data;
	data[4] = swap->stack_b->head->before->before->data;
	if (data[0] < data[1] && data[0] < data[2]
		&& data[0] < data[3] && data[0] < data[4])
		init_des_five_one (swap);
	else if (data[1] < data[0] && data[1] < data[2]
		&& data[1] < data[3] && data[1] < data[4])
		init_des_five_two (swap);
	else if (data[2] < data[0] && data[2] < data[1]
		&& data[2] < data[3] && data[2] < data[4])
		init_des_five_three (swap);
	else if (data[3] < data[0] && data[3] < data[1]
		&& data[3] < data[2] && data[3] < data[4])
		init_des_five_four (swap);
	else if (data[4] < data[0] && data[4] < data[1]
		&& data[4] < data[2] && data[4] < data[3])
		init_des_five_five (swap);
}

void	init_des_five_to_b(t_swap *swap)
{
	long	data[5];

	data[0] = swap->stack_a->head->next->data;
	data[1] = swap->stack_a->head->next->next->data;
	data[2] = swap->stack_a->head->next->next->next->data;
	data[3] = swap->stack_a->head->before->data;
	data[4] = swap->stack_a->head->before->before->data;
	if (data[0] < data[1] && data[0] < data[2]
		&& data[0] < data[3] && data[0] < data[4])
		init_des_five_one (swap);
	else if (data[1] < data[0] && data[1] < data[2]
		&& data[1] < data[3] && data[1] < data[4])
		init_des_five_two (swap);
	else if (data[2] < data[0] && data[2] < data[1]
		&& data[2] < data[3] && data[2] < data[4])
		init_des_five_three (swap);
	else if (data[3] < data[0] && data[3] < data[1]
		&& data[3] < data[2] && data[3] < data[4])
		init_des_five_four (swap);
	else if (data[4] < data[0] && data[4] < data[1]
		&& data[4] < data[2] && data[4] < data[3])
		init_des_five_five (swap);
}

void	init_asc_five_to_a(t_swap *swap)
{
	long	data[5];

	data[0] = swap->stack_b->head->next->data;
	data[1] = swap->stack_b->head->next->next->data;
	data[2] = swap->stack_b->head->next->next->next->data;
	data[3] = swap->stack_b->head->before->data;
	data[4] = swap->stack_b->head->before->before->data;
	if (data[0] > data[1] && data[0] > data[2]
		&& data[0] > data[3] && data[0] > data[4])
		init_asc_five_one (swap);
	else if (data[1] > data[0] && data[1] > data[2]
		&& data[1] > data[3] && data[1] > data[4])
		init_asc_five_two (swap);
	else if (data[2] > data[0] && data[2] > data[1]
		&& data[2] > data[3] && data[2] > data[4])
		init_asc_five_three (swap);
	else if (data[3] > data[0] && data[3] > data[1]
		&& data[3] > data[2] && data[3] > data[4])
		init_asc_five_four (swap);
	else if (data[4] > data[0] && data[4] > data[1]
		&& data[4] > data[2] && data[4] > data[3])
		init_asc_five_five (swap);
}

void	init_asc_five_to_b(t_swap *swap)
{
	long	data[5];

	data[0] = swap->stack_a->head->next->data;
	data[1] = swap->stack_a->head->next->next->data;
	data[2] = swap->stack_a->head->next->next->next->data;
	data[3] = swap->stack_a->head->before->data;
	data[4] = swap->stack_a->head->before->before->data;
	if (data[0] > data[1] && data[0] > data[2]
		&& data[0] > data[3] && data[0] > data[4])
		init_asc_five_one (swap);
	else if (data[1] > data[0] && data[1] > data[2]
		&& data[1] > data[3] && data[1] > data[4])
		init_asc_five_two (swap);
	else if (data[2] > data[0] && data[2] > data[1]
		&& data[2] > data[3] && data[2] > data[4])
		init_asc_five_three (swap);
	else if (data[3] > data[0] && data[3] > data[1]
		&& data[3] > data[2] && data[3] > data[4])
		init_asc_five_four (swap);
	else if (data[4] > data[0] && data[4] > data[1]
		&& data[4] > data[2] && data[4] > data[3])
		init_asc_five_five (swap);
}
