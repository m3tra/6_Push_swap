/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   midpoint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:47:24 by fporto            #+#    #+#             */
/*   Updated: 2022/03/06 23:09:16 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_lower(int *arr, int size, int mid, int top)
{
	int	i;

	i = 0;
	if (top)
	{
		while (i < size)
		{
			if (arr[i] < mid)
				return (i);
			i++;
		}
		return (-1);
	}
	else
	{
		while (size > 0)
		{
			if (arr[size - 1] < mid)
				return (--size);
			size--;
		}
		return (-1);
	}
}

int	find_nearest_lower(int *arr, int size, int mid)
{
	int	from_first;
	int	from_last;

	if (size <= 2)
		return (-1);
	from_first = find_lower(arr, size, mid, 1);
	from_last = find_lower(arr, size, mid, 0);
	// printf("*******\nMid: %d Size: %d\n", mid, size);
	// printf("from_first: %d\nfrom_last: %d\n", from_first, from_last);
	// printf("arr[0]: %d\n", arr[0]);
	if (from_first != -1 && from_last != -1)
	{
		if ((size - 1 - from_last) < from_first)
			return (from_last);
		else
			return (from_first);
	}
	else
		return (-1);
}

void	nearest_way(t_ps *ps, int nearest)
{
	int	i;

	if (((int) ps->a->size - 1 - nearest) < nearest)
	{
		i = ps->a->size;
		while (--i >= nearest)
			rra(ps);
	}
	else
	{
		i = -1;
		while (++i < nearest)
			ra(ps);
	}
}

void	move_lower_than(t_ps *ps, int mid, int *nearest)
{
	int	*arr;

	arr = stack_to_array(ps->a);
	*nearest = find_nearest_lower(arr, ps->a->size, mid);
	free(arr);
	if (*nearest == -1)
		return ;
	// printf("Nearest: %d Mid: %d Size: %ld\n", *nearest, mid, ps->a->size);
	// ft_stackprint(ps->a, NULL, " ");
	nearest_way(ps, *nearest);
	add_to_chunk(ps);
	pb(ps);
	arr = stack_to_array(ps->a);
	*nearest = find_nearest_lower(arr, ps->a->size, mid);
	free(arr);
	if (*nearest >= 0 && ps->a->size > 1)
		move_lower_than(ps, mid, nearest);
}

void	midpoint(t_ps *ps)
{
	int			*arr;
	int			*sorted;
	int			nearest;
	int			mid;

	new_chunk(ps);
	arr = stack_to_array(ps->a);
	sorted = stack_to_array(ps->a);
	quicksort(sorted, 0, ps->a->size - 1);
	mid = sorted[(int)(ps->a->size / 2)];
	free(sorted);

	// printf("\nmid_index: %d\n", find_in_arr(arr, ps->a->size, mid));
	// printf("StackB:\nSize: %zu\n", ps->b->size);
	// ft_stackprint(ps->b, NULL, "\n");

	nearest = find_nearest_lower(arr, ps->a->size, mid);
	// printf("-----Move Lower Than-----\n");
	while (nearest >= 0)
		move_lower_than(ps, mid, &nearest);
	free(arr);
	if (ps->a->size == 3)
		return ;
	midpoint(ps);
}
