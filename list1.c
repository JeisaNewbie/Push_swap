/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:17:40 by jhwang2           #+#    #+#             */
/*   Updated: 2023/01/29 04:52:08 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "share.h"

void	list_insert(t_list *list, long data)
{
	t_node	*old_top;
	t_node	*new_node;

	if (list == NULL)
		return ;
	old_top = list->head->next;
	new_node = (t_node *)malloc (sizeof (t_node));
	if (new_node == NULL)
		print_error();
	new_node->data = data;
	new_node->check_dummy = 0;
	new_node->before = list->head;
	list->head->next = new_node;
	if (list->start == 1)
	{
		new_node->next = list->head;
		list->head->before = new_node;
		list->start = 0;
	}
	else
	{
		new_node->next = old_top;
		old_top->before = new_node;
	}
	list->cur = new_node;
}

void	list_remove(t_node *node)
{
	t_node	*tmp;

	if (node == NULL || node->next == NULL)
		return ;
	tmp = node;
	if (node->next == node->before)
	{
		node->before->next = NULL;
		node->next->before = NULL;
		node->before->data = 0;
	}
	else
	{
		node->before->next = node->next;
		node->next->before = node->before;
		node->before->data = node->next->data;
	}
	free (tmp);
}
