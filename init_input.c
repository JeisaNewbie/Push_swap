/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:47:44 by jhwang2           #+#    #+#             */
/*   Updated: 2023/01/29 00:47:34 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "share.h"

int	check_number(char *argv, int check_num)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] == '-' || argv[i] == '+')
		{
			if (i > 0)
			{
				if ('0' <= argv[i - 1] && argv[i - 1] <= '9')
					return (0);
			}
			if (!('0' <= argv[i + 1] && argv[i + 1] <= '9'))
				return (0);
			i++;
		}
		if (!('0' <= argv[i] && argv[i] <= '9') && argv[i] != ' ')
			return (0);
		if ('0' <= argv[i] && argv[i] <= '9')
			check_num = 1;
		i++;
	}
	if (!check_num)
		return (0);
	return (1);
}

int	count_number(char *argv)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (argv[i])
	{
		if ('0' <= argv[i] && argv[i] <= '9')
		{
			while ('0' <= argv[i] && argv[i] <= '9')
				i++;
			count++;
			i--;
		}
		i++;
	}
	return (count);
}

char	**init_input(int *argc, char **argv)
{
	int	count;
	int	i;

	count = 0;
	i = 1;
	if (argv[i] == NULL)
		return (0);
	if (argv[i][0] == 0)
	{
		write (1, "Error\n", 6);
		exit (1);
	}
	while (argv[i])
	{
		if (!check_number (argv[i], 0))
		{
			write (1, "Error\n", 6);
			exit (1);
		}
		count += count_number (argv[i]);
		i++;
	}
	*argc = count;
	return (remake_input (argv, count));
}

char	**remake_input(char **argv, int count)
{
	char	**tmp;
	int		i;
	int		idx_argv;

	i = 0;
	idx_argv = 1;
	tmp = (char **)malloc (sizeof (char *) * count + 1);
	if (tmp == NULL)
		print_error();
	while (argv[idx_argv])
	{
		if (!ft_strchr_s (argv[idx_argv], ' '))
			tmp[i++] = ft_strdup (argv[idx_argv++]);
		else
			ft_split_p (tmp, argv[idx_argv++], &i);
	}
	tmp[count] = 0;
	return (tmp);
}
