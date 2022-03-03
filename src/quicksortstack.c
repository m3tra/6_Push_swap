/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksortstack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:45:52 by fporto            #+#    #+#             */
/*   Updated: 2022/03/03 16:46:08 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_stack.h"

static void	swapqs(t_stack *stack, int first, int second)
{
	t_stack_elem	*elem1;
	t_stack_elem	*elem2;
	t_stack_elem	*temp;
	int				i;

	i = 0;
	elem1 = stack->top;
	elem2 = stack->top;
	while (i++ < first)
		elem1 = elem1->prev;
	temp = elem1;
	i = 0;
	while (i++ < second)
		elem2 = elem2->prev;
	elem1 = elem2;
	elem2 = temp;
}

static int	partitionqs(t_stack *stack, int lower, int upper)
{
	int				pivot;
	int				i;
	int				j;
	t_stack_elem	*elem;

	elem = stack->top;
	i = 0;
	while (i++ < upper)
	{
		if (!elem->prev)
			break ;
		elem = elem->prev;
	}
	pivot = elem->cont.i;
	i = lower - 1;
	j = lower - 1;
	while (++j < upper)
	{
		if (get_cont_i(stack, j) <= pivot)
			swapqs(stack, ++i, j);
	}
	swapqs(stack, i + 1, upper);
	return (i + 1);
}

void	quicksort_stack(t_stack *stack, int lower, int upper)
{
	int	partition_index;

	if (upper > lower)
	{
		partition_index = partitionqs(stack, lower, upper);
		quicksort_stack(stack, lower, partition_index - 1);
		quicksort_stack(stack, partition_index + 1, upper);
	}
}
