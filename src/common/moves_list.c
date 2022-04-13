/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 23:47:01 by fporto            #+#    #+#             */
/*   Updated: 2022/04/13 17:21:44 by fporto           ###   ########.fr       */
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

t_moves_list	*moves_list_new(void)
{
	t_moves_list	*list;

	list = malloc(sizeof(t_moves_list));
	if (!list)
		err_exit();
	list->size = 0;
	list->first = NULL;
	return (list);
}

t_move	*moves_lstlast(t_moves_list *list)
{
	t_move	*move;

	if (!list->first)
		return (NULL);
	move = list->first;
	while (move->next)
		move = move->next;
	return (move);
}

void	moves_list_cat(t_moves_list *list, t_move *move)
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

void	moves_list_pop(t_moves_list *list, t_move *move)
{
	move->prev->next = move->next;
	move->next->prev = move->prev;
	free(move);
	list->size--;
}

void	moves_list_destroy(t_moves_list *list)
{
	t_move	*tmp;

	tmp = list->first;
	while (tmp->next)
	{
		tmp = tmp->next;
		free(tmp->prev);
	}
	free(tmp);
	free(list);
}
