/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   midpoint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:47:24 by fporto            #+#    #+#             */
/*   Updated: 2022/03/03 19:33:37 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	middle_index(t_stack *stack)
{
	size_t	index;

	index = stack->size / 2;
	return ((int) index);
}

int	find_lower_top(int *arr, int size, int mid)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] < mid)
			return (i);
		i++;
	}
	return (-1);
}

int	find_lower_bottom(int *arr, int size, int mid)
{
	int	i;

	i = size;
	while (size > 0)
	{
		if (arr[--i] <= mid)
			return (i);
		size--;
	}
	return (-1);
}

int	find_nearest(int *arr, int size, int mid)
{
	int	top;
	int	bot;

	top = find_lower_top(arr, size, mid);
	bot = find_lower_bottom(arr, size, mid);
	if (top != -1 && bot != -1)
	{
		if (top < bot)
			return (top);
		else
			return (bot);
	}
	else
		return (-1);
}

void	pb_in_a_row(t_ps *ps, int mid)
{
	t_stack_elem	*elem;

	elem = ps->a->top;
	while (elem->cont.i < mid)
	{
		pb(ps);
		elem = elem->prev;
	}
}

void	move_lower_than(t_ps *ps, int mid, int nearest)
{
	int	i;

	if (nearest < mid)
	{
		i = -1;
		while (++i < nearest)
			ra(ps);
		pb_in_a_row(ps, mid);
	}
	else
	{
		i = ps->a->size;
		while (--i > nearest)
			rra(ps);
		pb_in_a_row(ps, mid);
	}
}

int	midpoint(t_ps *ps)
{
	int				*arr;
	int				*sorted;
	int				nearest;
	t_stack_elem	*elem;
	int				mid;

	arr = stack_to_array(ps->a, ps->a->size);
	sorted = stack_to_array(ps->a, ps->a->size);
	quicksort(sorted, 0, ps->a->size - 1);
	mid = middle_index(ps->a);
	elem = ps->a->top;
	pb_in_a_row(ps, mid);
	nearest = find_nearest(arr, ps->a->size, mid);
	free(arr);
	free(sorted);
	if (nearest >= 0)
		move_lower_than(ps, mid, nearest);
	else
		midpoint(ps);
	return (0);
}
