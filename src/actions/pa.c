/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:46:33 by fporto            #+#    #+#             */
/*   Updated: 2022/04/13 15:02:12 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_ps *ps)
{
	if (ps->b->size < 1)
		return ;
	moves_list_cat(ps->moves, move_new("pa"));
	ft_stackpush(ps->a, ft_stackpop(ps->b));
	if (PRINT_MOVES)
		ft_putstr_fd("pa\n", 1);
}
