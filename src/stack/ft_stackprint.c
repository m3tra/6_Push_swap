/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackprint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 19:18:50 by mgueifao          #+#    #+#             */
/*   Updated: 2022/03/03 19:29:28 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stackprint(t_stack *stack, char *(*to_str)(t_content), char *delim)
{
	t_stack_elem	*elem;

	if (stack->size > 0)
	{
		if (!stack)
			return ;
		elem = stack->top;
		if (to_str && elem)
			ft_putstr_fd(to_str(elem->cont), 1);
		else if (elem)
			ft_putnbr_fd(elem->cont.i, 1);
		while (elem->prev)
		{
			elem = elem->prev;
			ft_putstr_fd(delim, 1);
			if (to_str)
				ft_putstr_fd(to_str(elem->cont), 1);
			else
				ft_putnbr_fd(elem->cont.i, 1);
		}
	}
	ft_putstr_fd("\n", 1);
}
