/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   midpoint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:47:24 by fporto            #+#    #+#             */
/*   Updated: 2022/03/04 22:36:59 by fporto           ###   ########.fr       */
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

int	find_nearest(int arr[], int size, int mid)
{
	int	top;
	int	bot;

	if (size <= 1)
		return (-1);
	top = find_lower_top(arr, size, mid);
	bot = find_lower_bottom(arr, size, mid);
	if (top != -1 && bot != -1)
	{
		if ((size - 1 - bot) < top)
			return(bot);
		else
			return (top);
	}
	else
		return (-1);
}

int	find_in_arr(int *arr, int size, int n)
{
	int	i;

	i = -1;
	while (++i < size)
		if (arr[i] == n)
			return (i);
	return (-1);
}

void	move_lower_than(t_ps *ps, int mid, int *nearest)
{
	int	i;
	int	*arr;

	arr = stack_to_array(ps->a, ps->a->size);

	printf("Nearest: %d Mid: %d\n", *nearest, mid);
	ft_stackprint(ps->a, NULL, " ");

	*nearest = find_nearest(arr, ps->a->size, mid);
	if (((int) ps->a->size - 1 - *nearest) < *nearest)
	{
		i = ps->a->size;
		while (--i >= *nearest)
			rra(ps);
		pb(ps);
	}
	else
	{
		i = -1;
		while (++i < *nearest)
			ra(ps);
		pb(ps);
	}
	*nearest = find_nearest(arr, ps->a->size, mid);
	if (*nearest >= 0 && ps->a->size > 1)
	{
		free(arr);
		move_lower_than(ps, mid, nearest);
	}
	else
		free(arr);
}

void	midpoint(t_ps *ps)
{
	int			*arr;
	int			*sorted;
	int			nearest;
	int			mid;
	t_content	content;
	content.size = 0;

	content.arr = "";
	ft_stackpush(ps->chunks, content);
	arr = stack_to_array(ps->a, ps->a->size);
	sorted = stack_to_array(ps->a, ps->a->size);
	quicksort(sorted, 0, ps->a->size - 1);
	mid = sorted[middle_index(ps->a)];
	free(sorted);

	printf("\nmid_index: %d\n", find_in_arr(arr, ps->a->size, mid));
	printf("Midpoint: %d\n", mid);
	printf("StackB:\nSize: %zu\n", ps->b->size);
	ft_stackprint(ps->b, NULL, "\n");

	nearest = find_nearest(arr, ps->a->size, mid);
	while (nearest >= 0)
		move_lower_than(ps, mid, &nearest);
	free(arr);
	if (ps->a->size <= 1)
		return ;
	else
		midpoint(ps);
}
