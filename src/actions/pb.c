/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:46:35 by fporto            #+#    #+#             */
/*   Updated: 2022/04/13 15:02:03 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_ps *ps)
{
	if (ps->a->size < 1)
		return ;
	moves_list_cat(ps->moves, move_new("pb"));
	ft_stackpush(ps->b, ft_stackpop(ps->a));
	if (PRINT_MOVES)
		ft_putstr_fd("pb\n", 1);
}
