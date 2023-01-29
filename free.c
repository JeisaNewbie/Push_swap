/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:17:22 by jhwang2           #+#    #+#             */
/*   Updated: 2023/01/29 04:45:14 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "share.h"

void	free_stack(t_swap *swap)
{
	t_node	*tmp;

	swap->stack_a->cur = swap->stack_a->head->next;
	while (swap->stack_a->cur->check_dummy != 1)
	{
		tmp = swap->stack_a->cur;
		list_next (swap->stack_a);
		free (tmp);
	}
	free (swap->stack_a->head);
	free (swap->stack_b->head);
	free (swap->arr[0]);
	free (swap->arr[1]);
	free (swap->arr);
	free (swap->idx);
	free (swap->stack_a);
	free (swap->stack_b);
	free (swap);
}

void	free_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free (argv[i]);
		i++;
	}
	free (argv);
}

void	free_all(char **argv, t_swap *swap)
{
	free_argv (argv);
	free_stack (swap);
}

void	print_error(void)
{
	write (1, "Malloc Fail!!!\n", 15);
	exit (1);
}
