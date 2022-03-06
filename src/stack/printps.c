/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:03:27 by fporto            #+#    #+#             */
/*   Updated: 2022/03/05 21:08:44 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_stack.h"

void	print_elem(t_stack_elem *s)
{
	printf("\t\t\tsize: %ld\n", s->cont.size);
	printf("\t\t\ti: %d\n", s->cont.i);
	if (s->cont.arr)
		printf("\t\t\tarr: %s\n", s->cont.arr);
	else
		printf("\t\t\tarr: %p\n", (void *)s->cont.arr);
}

void	print_stack(t_stack *s)
{
	t_stack_elem	*e;
	int				i;

	if (!s)
		return ;
	i = 0;
	printf("\tsize: %ld,\n", s->size);
	e = s->top;
	while (e)
	{
		printf("\t\t%d elem [%p]\n", i++, (void *)e);
		printf("\t\tprev [%p]\n", (void *)e->prev);
		print_elem(e);
		e = e->prev;
	}
}

void	print_ps(t_ps *ps)
{
	printf("PS [%p]:\n", (void *)ps);
	printf("PS->A [%p]:\n", (void *)ps->a);
	print_stack(ps->a);
	printf("PS->B [%p]:\n", (void *)ps->b);
	print_stack(ps->b);
	printf("PS->CHUNKS [%p]:\n", (void *)ps->chunks);
	print_stack(ps->chunks);
}
