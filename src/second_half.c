/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_half.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 23:07:13 by fporto            #+#    #+#             */
/*   Updated: 2022/03/09 20:59:47 by fporto           ###   ########.fr       */
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
		{
			if (elem->prev->cont.i < elem->prev->prev->cont.i)
				rra(ps);
			else
			{
				ra(ps);
				sa(ps);
			}
		}
		else
			sa(ps);
	}
	else
	{
		if (elem->cont.i < elem->prev->prev->cont.i)
		{
			rra(ps);
			sa(ps);
		}
		else
			rra(ps);
	}
}

static int	find_highest(t_ps *ps)
{
	int				biggest;
	int				index;
	t_stack_elem	*elem;
	size_t			i;

	// printf("-------------------------------------------\n");
	// print_ps(ps);
	elem = ps->b->top;
	biggest = elem->cont.i;
	if (ps->b->size == 1)
		return (biggest);
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
	// printf("Highest: %d\n", index);
	return (index);
}

void	move_highest(t_ps *ps)
{
	size_t	i;
	size_t	j;

	if (ps->chunks->top->cont.size == 1)
	{
		// print_ps(ps);
		pa(ps);
		free(ps->chunks->top->cont.arr);
		ft_stackpop(ps->chunks);
		return ;
	}
	i = find_highest(ps);
	j = i;
	i++;

	// ft_putstr_fd("move highest\n", 1);
	// ft_stackprint(ps->b, NULL, "\n");
	// print_chunks(ps);

	while (--i > 0)
		rb(ps);
	pa(ps);
	ps->chunks->top->cont.size--;

	// ft_stackprint(ps->b, NULL, "\n");
	i--;
	while (++i < j)
		rrb(ps);
	move_highest(ps);
}
