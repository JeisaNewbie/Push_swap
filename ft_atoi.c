/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:42:09 by jhwang2           #+#    #+#             */
/*   Updated: 2023/01/29 00:45:50 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "share.h"

long	ft_atoi(const char *string, long minus, int i)
{
	char	*str;
	long	atoi;

	str = ft_strdup (string);
	atoi = 2147483649;
	if ((9 <= str[i] && str[i] <= 13) || str[i] == ' ')
	{
		while (((9 <= str[i] && str[i] <= 13) || str[i] == ' ')
			&& str[i] != '\0')
			i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	if ('0' <= str[i] && str[i] <= '9')
		atoi = check_string(&str[i], minus);
	free (str);
	if (atoi == 2147483649 || atoi == -2147483649)
		return (2147483649);
	return (atoi);
}

char	*ft_strdup(const char *s1)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	while (s1[i])
		i++;
	tmp = (char *)malloc(sizeof(char) * i + 1);
	if (tmp == NULL)
		print_error();
	j = 0;
	while (i >= 0)
	{
		tmp[j] = s1[j];
		j++;
		i--;
	}
	return (tmp);
}

long	check_string(char *str, long minus)
{
	long	return_atoi;
	int		i;

	return_atoi = 0;
	i = 0;
	while (str[i] != '\0' && ('0' <= str[i] && str[i] <= '9'))
	{
		return_atoi = return_atoi * 10 + (str[i] - '0');
		i++;
		if (!('0' <= str[i] && str[i] <= '9') && str[i] != '\0')
			return (2147483649);
	}
	return_atoi *= minus;
	if (-2147483648 > return_atoi || return_atoi > 2147483647)
		return (2147483649);
	return (return_atoi);
}
