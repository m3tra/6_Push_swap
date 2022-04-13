/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:46:51 by fporto            #+#    #+#             */
/*   Updated: 2022/04/13 14:58:48 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_ps *ps)
{
	t_content	tmp1;
	t_content	tmp2;

	moves_list_cat(ps->moves, move_new("sa"));
	if (ps->a->size < 2)
		return ;
	tmp1 = ft_stackpop(ps->a);
	tmp2 = ft_stackpop(ps->a);
	ft_stackpush(ps->a, tmp1);
	ft_stackpush(ps->a, tmp2);
	if (PRINT_MOVES)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_ps *ps)
{
	t_content	tmp1;
	t_content	tmp2;

	moves_list_cat(ps->moves, move_new("sb"));
	if (ps->b->size < 2)
		return ;
	tmp1 = ft_stackpop(ps->b);
	tmp2 = ft_stackpop(ps->b);
	ft_stackpush(ps->b, tmp1);
	ft_stackpush(ps->b, tmp2);
	if (PRINT_MOVES)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_ps *ps)
{
	moves_list_cat(ps->moves, move_new("ss"));
	sa(ps);
	sb(ps);
	if (PRINT_MOVES)
		ft_putstr_fd("ss\n", 1);
}
