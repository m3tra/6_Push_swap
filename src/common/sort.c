/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:47:35 by fporto            #+#    #+#             */
/*   Updated: 2022/04/14 01:01:26 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *a)
{
	t_stack_elem	*tmp;
	int				min;

	tmp = a->top;
	min = tmp->cont.i;
	while (tmp)
	{
		if (tmp->cont.i < min)
			min = tmp->cont.i;
		tmp = tmp->prev;
	}
	return (min);
}

int	find_index(t_stack *a, int min)
{
	t_stack_elem	*tmp;
	int				i;

	tmp = a->top;
	i = 0;
	while (tmp)
	{
		if (tmp->cont.i == min)
			return (i + 1);
		i++;
		tmp = tmp->prev;
	}
	return (-1);
}

int	is_sorted(t_stack *arr, int asc)
{
	t_stack_elem	*temp;

	if (arr->size <= 2 || !arr->top)
		return (-1);
	temp = arr->top;
	while (temp->prev)
	{
		if (asc)
		{
			if (temp->cont.i > temp->prev->cont.i)
				return (0);
		}
		else
		{
			if (temp->cont.i < temp->prev->cont.i)
				return (0);
		}
		temp = temp->prev;
	}
	return (1);
}

void	has_duplicates(t_ps *ps)
{
	int		i;
	int		*arr;
	t_stack	*stack;

	stack = ps->a;
	arr = stack_to_array(stack);
	quicksort(arr, 0, stack->size - 1);
	i = -1;
	while (++i < (int) stack->size - 1)
	{
		if (arr[i] == arr[i + 1])
		{
			free(arr);
			destroy_ps(ps);
			err_exit();
		}
	}
	free(arr);
}

void	sort(t_ps *ps)
{
	int		min_index;

	while (ps->a->top)
	{
		min_index = find_index(ps->a, find_min(ps->a));
		if (min_index < (get_size(ps->a) / 2 + 1))
		{
			while (min_index > 1)
			{
				ra(ps);
				min_index--;
			}
		}
		else
		{
			while (min_index != get_size(ps->a) + 1)
			{
				rra(ps);
				min_index++;
			}
		}
		pb(ps);
	}
	while (!is_empty(ps->b))
		pa(ps);
}
