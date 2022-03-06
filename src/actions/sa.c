/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:46:51 by fporto            #+#    #+#             */
/*   Updated: 2022/03/05 15:38:20 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_ps *ps)
{
	t_content	tmp1;
	t_content	tmp2;

	if (ps->a->size < 2)
		return ;
	tmp1 = ft_stackpop(ps->a);
	tmp2 = ft_stackpop(ps->a);
	ft_stackpush(ps->a, tmp1);
	ft_stackpush(ps->a, tmp2);
	if (PRINT_MOVES)
		ft_putstr_fd("sa\n", 1);
}
