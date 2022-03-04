/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:46:37 by fporto            #+#    #+#             */
/*   Updated: 2022/03/04 19:34:22 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_ps *ps)
{
	t_stack_elem	*tmp;
	t_stack_elem	*curr;

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
