/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:16:48 by jhwang2           #+#    #+#             */
/*   Updated: 2023/01/29 04:32:30 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "share.h"

int	check_error(int argc, char **argv, int i, int flag)
{
	long	*arr;

	arr = (long *)malloc (sizeof (long) * argc);
	if (arr == NULL)
		print_error();
	while (argv[i])
	{
		arr[i] = ft_atoi (argv[i], 1, 0);
		if (arr[i] == 2147483649 || check_reduplication (arr, i))
		{
			free_argv (argv);
			free (arr);
			return (0);
		}
		i++;
	}
	if (check_sorted (arr, i, flag))
	{
		free_argv (argv);
		free (arr);
		exit (0);
	}
	free (arr);
	return (1);
}

int	check_reduplication(long *arr, int length)
{
	int	i;
	int	j;

	i = 0;
	while (i < length)
	{
		j = i + 1;
		while (j <= length)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_sorted(long *arr, int length, int flag)
{
	int	i;
	int	j;

	i = 0;
	if (!flag)
		return (0);
	while (i < length - 1)
	{
		j = i + 1;
		while (j < length)
		{
			if (arr[i] > arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
