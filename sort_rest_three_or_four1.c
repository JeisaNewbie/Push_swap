/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rest_three_or_four1.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:17:58 by jhwang2           #+#    #+#             */
/*   Updated: 2023/01/22 18:17:59 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_rest_des(t_swap *swap, long *abc)
{
	if (abc[0] < abc[1] && abc[1] < abc[2])
		sort_three_one (swap);
	else if (abc[0] < abc[2] && abc[2] < abc[1])
		sort_three_two (swap);
	else if (abc[1] < abc[0] && abc[0] < abc[2])
		sort_three_three (swap);
	else if (abc[1] < abc[2] && abc[2] < abc[0])
		sort_three_four (swap);
	else if (abc[2] < abc[0] && abc[0] < abc[1])
		sort_three_five (swap);
	else if (abc[2] < abc[1] && abc[1] < abc[0])
		sort_three_six (swap);
}

void	sort_rest_asc(t_swap *swap, long *abc)
{
	if (abc[0] > abc[1] && abc[1] > abc[2])
		sort_three_one (swap);
	else if (abc[0] > abc[2] && abc[2] > abc[1])
		sort_three_two (swap);
	else if (abc[1] > abc[0] && abc[0] > abc[2])
		sort_three_three (swap);
	else if (abc[1] > abc[2] && abc[2] > abc[0])
		sort_three_four (swap);
	else if (abc[2] > abc[0] && abc[0] > abc[1])
		sort_three_five (swap);
	else if (abc[2] > abc[1] && abc[1] > abc[0])
		sort_three_six (swap);
}

void	sort_three_one(t_swap *swap)
{
	if (swap->to_a)
	{
		push_a (swap->stack_a, swap->stack_b);
		push_a (swap->stack_a, swap->stack_b);
	}
	else
	{
		push_b (swap->stack_b, swap->stack_a);
		push_b (swap->stack_b, swap->stack_a);
	}
}
