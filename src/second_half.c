/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_half.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 23:07:13 by fporto            #+#    #+#             */
/*   Updated: 2022/03/06 23:13:47 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_trio(t_ps *ps)
{
	t_stack_elem	*elem;

	elem = ps->a->top;
	if (elem->cont.i > elem->prev->cont.i)
	{
		if (elem->cont.i > elem->prev->prev->cont.i)
			ra(ps);
		else
			sa(ps);
	}
	else
	{
		if (elem->cont.i > elem->prev->prev->cont.i)
			rra(ps);
		else
		{
			if (elem->prev->cont.i > elem->prev->prev->cont.i)
			{
				ra(ps);
				sa(ps);
				rra(ps);
			}
			return ;
		}
	}
}

int	find_highest(t_ps *ps)
{
	int				biggest;
	int				index;
	t_stack_elem	*elem;
	size_t			i;

	elem = ps->b->top;
	biggest = elem->cont.i;
	index = 0;
	i = 0;
	while (i < ps->chunks->top->cont.size - 1)
	{
		elem = elem->prev;
		i++;
		if (elem->cont.i > biggest)
		{
			biggest = elem->cont.i;
			index = i;
		}
	}
	return (index);
}

void	move_highest(t_ps *ps)
{
	size_t			i;
	size_t			j;

	i = find_highest(ps);
	j = i;
	i++;
	while (--i > 0)
		rb(ps);
	subtract_from_chunk(ps);
	pa(ps);
	i--;
	while (++i < j)
		rrb(ps);
	if (ps->chunks->top->cont.size == 1)
	{
		pa(ps);
		free(ps->chunks->top->cont.arr);
		ft_stackpop(ps->chunks);
		return ;
	}
	move_highest(ps);
}
