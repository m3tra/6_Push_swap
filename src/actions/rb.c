/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:46:40 by fporto            #+#    #+#             */
/*   Updated: 2022/03/04 19:34:25 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_ps *ps)
{
	t_stack_elem	*tmp;
	t_stack_elem	*curr;

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
