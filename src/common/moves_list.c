/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 23:47:01 by fporto            #+#    #+#             */
/*   Updated: 2022/04/14 00:50:02 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_move	*move_new(char *str)
{
	t_move	*move;

	move = malloc(sizeof(t_move));
	if (!move)
		err_exit();
	move->move = str;
	move->prev = NULL;
	move->next = NULL;
	return (move);
}

t_mvs_lst	*moves_list_new(void)
{
	t_mvs_lst	*list;

	list = malloc(sizeof(t_mvs_lst));
	if (!list)
		err_exit();
	list->size = 0;
	list->first = NULL;
	return (list);
}

t_move	*moves_lstlast(t_mvs_lst *list)
{
	t_move	*move;

	if (!list->first)
		return (NULL);
	move = list->first;
	while (move->next)
		move = move->next;
	return (move);
}

void	moves_list_cat(t_mvs_lst *list, t_move *move)
{
	t_move	*prev;

	if (!list)
		list = moves_list_new();
	if (!list->first)
		list->first = move;
	list->size++;
	prev = moves_lstlast(list);
	if (prev)
		prev->next = move;
	move->prev = prev;
	move->next = NULL;
}

void	moves_list_pop(t_mvs_lst *list, t_move *move)
{
	if (list->first == move)
		list->first = move->next;
	move->prev->next = move->next;
	move->next->prev = move->prev;
	free(move);
	list->size--;
}
