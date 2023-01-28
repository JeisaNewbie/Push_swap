/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:54:16 by jhwang2           #+#    #+#             */
/*   Updated: 2023/01/28 23:52:09 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "share.h"

t_list	*lstnew(int fd)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = NULL;
	new->next = NULL;
	new->fd = fd;
	return (new);
}

void	lstfree(t_list **backup)
{
	if ((*backup)->content != NULL)
	{
		free ((*backup)->content);
		(*backup)->content = NULL;
	}
	free (*backup);
}

int	ft_strchr(const char *s, int c)
{
	char	*string;
	char	ch;
	int		i;

	i = 0;
	string = (char *)s;
	ch = (char)c;
	while (string[i] != '\0')
	{
		if (string[i] == ch)
			return (i + 1);
		i++;
	}
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*string1;
	unsigned char	*string2;
	int				i;

	string1 = (unsigned char *)s1;
	string2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (n && (string1[i] == string2[i]))
	{
		if (string1[i] == '\0' && string2[i] == '\0')
			break ;
		i++;
		n--;
	}
	if (n == 0)
		return (string1[i - 1] - string2[i - 1]);
	return (string1[i] - string2[i]);
}
