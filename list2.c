/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:17:43 by jhwang2           #+#    #+#             */
/*   Updated: 2023/01/28 23:33:37 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "share.h"

long	list_first(t_list *list)
{
	if (list == NULL || list->head->next == NULL)
		return (0);
	list->cur = list->head->next;
	return (1);
}

long	list_last(t_list *list)
{
	if (list == NULL || list->head->before == NULL)
		return (0);
	list->cur = list->head->before;
	return (list->cur->data);
}

long	list_next(t_list *list)
{
	if (list == NULL)
		return (0);
	list->cur = list->cur->next;
	return (list->cur->data);
}

long	list_previous(t_list *list)
{
	if (list == NULL)
		return (0);
	list->cur = list->cur->before;
	if (list->cur->check_dummy == 1)
		list->cur = list->cur->before;
	return (list->cur->data);
}
