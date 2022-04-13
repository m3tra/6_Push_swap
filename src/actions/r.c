/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:46:37 by fporto            #+#    #+#             */
/*   Updated: 2022/04/13 15:00:59 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_ps *ps)
{
	t_stack_elem	*tmp;
	t_stack_elem	*curr;

	moves_list_cat(ps->moves, move_new("ra"));
	if (ps->a->size < 2)
		return ;
	tmp = ps->a->top;
	ps->a->top = ps->a->top->prev;
	tmp->prev = NULL;
	curr = ps->a->top;
	while (curr->prev)
		curr = curr->prev;
	curr->prev = tmp;
	if (PRINT_MOVES)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_ps *ps)
{
	t_stack_elem	*tmp;
	t_stack_elem	*curr;

	moves_list_cat(ps->moves, move_new("rb"));
	if (ps->b->size < 2)
		return ;
	tmp = ps->b->top;
	ps->b->top = ps->b->top->prev;
	tmp->prev = NULL;
	curr = ps->b->top;
	while (curr->prev)
		curr = curr->prev;
	curr->prev = tmp;
	if (PRINT_MOVES)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_ps *ps)
{
	moves_list_cat(ps->moves, move_new("rr"));
	ra(ps);
	rb(ps);
	if (PRINT_MOVES)
		ft_putstr_fd("rr\n", 1);
}
