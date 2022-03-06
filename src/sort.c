/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:47:35 by fporto            #+#    #+#             */
/*   Updated: 2022/03/06 23:18:38 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			err_exit("Has duplicates");
		}
	}
	free(arr);
}
