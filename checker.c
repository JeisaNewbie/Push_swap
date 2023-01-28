/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:47:44 by jhwang2           #+#    #+#             */
/*   Updated: 2023/01/29 04:51:54 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "share.h"

int	main(int argc, char *argv[])
{
	t_swap	*swap;
	int		i;

	argv = init_input (&argc, argv);
	if (!argv)
		return (0);
	if (!check_error (argc, argv, 0, 0))
	{
		write (2, "Error\n", 6);
		return (0);
	}
	swap = init_swap (argc, 0);
	i = argc - 1;
	while (i >= 0)
		list_insert (swap->stack_a, ft_atoi(argv[i--], 1, 0));
	do_command (swap);
	if (!check_stack_sorted (swap))
	{
		write (2, "KO\n", 3);
		exit (1);
	}
	free_all (argv, swap);
	write (2, "OK\n", 3);
	return (0);
}

int	do_command(t_swap *swap)
{
	char	*command;
	int		i;

	i = 0;
	while (1)
	{
		command = get_next_line (0);
		if (command == 0)
			return (0);
		while (command[i])
			i++;
		if (i <= 2 || check_command (swap, command, i - 1))
		{
			write (2, "Error\n", 6);
			exit (1);
		}
		free (command);
		i = 0;
	}
	return (0);
}

int	check_command(t_swap *swap, char *command, int length)
{
	if (!ft_strncmp_p ("pa", command, length))
		push_a (swap->stack_a, swap->stack_b);
	else if (!ft_strncmp_p ("pb", command, length))
		push_b (swap->stack_b, swap->stack_a);
	else if (!ft_strncmp_p ("sa", command, length))
		swap_a (swap->stack_a->head);
	else if (!ft_strncmp_p ("sb", command, length))
		swap_b (swap->stack_b->head);
	else if (!ft_strncmp_p ("ss", command, length))
		ss (swap->stack_a->head, swap->stack_b->head);
	else if (!ft_strncmp_p ("ra", command, length))
		rotate_a (swap->stack_a);
	else if (!ft_strncmp_p ("rb", command, length))
		rotate_b (swap->stack_b);
	else if (!ft_strncmp_p ("rr", command, length))
		rr (swap->stack_a, swap->stack_b);
	else if (!ft_strncmp_p ("rra", command, length))
		reverse_ra (swap->stack_a);
	else if (!ft_strncmp_p ("rrb", command, length))
		reverse_rb (swap->stack_b);
	else if (!ft_strncmp_p ("rrr", command, length))
		reverse_rr (swap->stack_a, swap->stack_b);
	else
		return (1);
	return (0);
}

int	check_stack_sorted(t_swap *swap)
{
	long	a;
	long	b;

	if (!list_first (swap->stack_a))
		return (0);
	while (swap->stack_a->cur->next->check_dummy != 1)
	{
		a = swap->stack_a->cur->data;
		b = swap->stack_a->cur->next->data;
		if (a > b)
			return (0);
		list_next (swap->stack_a);
	}
	if (swap->stack_b->head->next != NULL)
		return (0);
	return (1);
}

int	ft_strncmp_p(char *s1, char *s2, size_t n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (n && (s1[i] == s2[i]))
	{
		i++;
		n--;
	}
	if (n == 0)
		return (s1[i - 1] - s2[i - 1]);
	return (s1[i] - s2[i]);
}
