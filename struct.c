/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:18:06 by jhwang2           #+#    #+#             */
/*   Updated: 2023/01/28 23:31:43 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "share.h"

int	check_pow(int i)
{
	int	a;
	int	m;

	a = 0;
	m = i;
	if (i < 2)
		return (0);
	while (m)
	{
		m /= 3;
		a++;
	}
	m = 3;
	while (a)
	{
		if (i == m)
			return (1);
		m *= 3;
		a--;
	}
	return (0);
}

void	check_ascending(int **arr, int *idx)
{
	int	two_over_three;

	two_over_three = 0;
	if (idx[1] == idx[0] / 3)
		idx[2] = 1;
	while (idx[1] != idx[0])
	{
		if (idx[1] >= (idx[0] / 3) * 2 && !two_over_three)
		{
			idx[2] = (idx[0] / 3) + 1;
			two_over_three = 1;
		}
		arr[1][idx[1]] = arr[1][idx[1] - idx[2]] * -1;
		idx[1]++;
		idx[2] += 2;
	}
}

void	divide(int argc, int **arr, int *idx, int depth)
{
	int	mid1;
	int	mid2;
	int	mid3;

	if (depth >= 1)
	{
		mid1 = argc / 3;
		mid2 = (argc / 3) + (argc % 3);
		mid3 = argc / 3;
		divide (mid1, arr, idx, depth - 1);
		divide (mid2, arr, idx, depth - 1);
		divide (mid3, arr, idx, depth - 1);
	}
	else
	{
		arr[0][idx[0]++] = argc;
		if (check_pow (idx[0]))
			check_ascending (arr, idx);
	}
}

void	check_tri(int argc, int i, int *depth)
{
	int	top;
	int	mid;

	top = argc / 3;
	mid = (argc / 3) + (argc % 3);
	if (mid < 6)
	{
		if (*depth < i)
			*depth = i;
		return ;
	}
	check_tri (top, i + 1, depth);
	check_tri (mid, i + 1, depth);
}

int	check_struct(t_swap *swap, int argc, int *depth)
{
	int	n;
	int	j;

	n = 1;
	j = 0;
	*depth = 0;
	check_tri (argc, 1, depth);
	swap->start = 1;
	swap->to_a = !(*depth % 2);
	while (j < *depth)
	{
		n *= 3;
		j++;
	}
	swap->num_of_tri = n;
	return (n);
}
