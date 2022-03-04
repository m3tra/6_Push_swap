/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:46:53 by fporto            #+#    #+#             */
/*   Updated: 2022/03/04 19:34:37 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_ps *ps)
{
	t_content	tmp1;
	t_content	tmp2;

	if (ps->b->size < 2)
		return ;
	tmp1 = ft_stackpop(ps->b);
	tmp2 = ft_stackpop(ps->b);
	ft_stackpush(ps->b, tmp1);
	ft_stackpush(ps->b, tmp2);
	if (PRINT_MOVES)
		ft_putstr_fd("sb\n", 1);
}
