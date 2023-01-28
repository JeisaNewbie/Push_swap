/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:09:29 by jhwang2           #+#    #+#             */
/*   Updated: 2023/01/29 00:46:34 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "share.h"

int	ft_split_p(char **input, char *argv, int *i)
{
	int	idx_argv;
	int	j;

	idx_argv = 0;
	j = 0;
	while (argv[j])
	{
		while (argv[j] == ' ')
			j++;
		if (argv[j] == '\0')
			return (1);
		idx_argv = j;
		input[(*i)++] = ft_strdup_s (&argv[idx_argv], &j);
		j++;
	}
	return (1);
}

int	ft_strchr_s(char *s, int c)
{
	char	*string;
	char	ch;
	int		i;

	i = 0;
	string = s;
	ch = (char)c;
	while (string[i] != '\0')
	{
		if (string[i] == ch)
			return (i + 1);
		i++;
	}
	return (0);
}

char	*ft_strdup_s(char *s1, int *idx)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	while (s1[i] && s1[i] != ' ')
		i++;
	tmp = (char *)malloc(sizeof(char) * i + 1);
	if (tmp == NULL)
		print_error();
	j = 0;
	while (j < i)
	{
		tmp[j] = s1[j];
		j++;
	}
	tmp[j] = '\0';
	*idx += i - 1;
	return (tmp);
}
