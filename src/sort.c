/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:47:35 by fporto            #+#    #+#             */
/*   Updated: 2022/03/03 18:22:01 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *arr)
{
	t_stack_elem	*temp;

	if (arr->size < 2 || !arr->top)
		return (-1);
	temp = arr->top;
	while (temp->prev)
	{
		// if (ft_atoi(temp->cont.ptr) > ft_atoi(temp->prev->cont.ptr))
		if (temp->cont.i > temp->prev->cont.i)
			return (0);
		temp = temp->prev;
	}
	return (1);
}

// int	has_duplicates(t_stack *stack)
// {
// 	size_t			i;
// 	// size_t		j;
// 	t_stack_elem	*temp;
// 	// t_stack_elem	*temp2;

// 	i = 0;

// 	printf("Stack size: %zu\n", stack->size);
// 	printf("Before sort:\n");
// 	ft_stackprint(stack, NULL, "\n");

// 	printf("Ptr: %p\n", (void *)stack);
// 	quicksort_stack(stack, 0, stack->size - 1);

// 	printf("After sort:\n");
// 	ft_stackprint(stack, NULL, "\n");

// 	// printf("Ptr: %p\n", (void *)stack);

// 	// temp = stack->top;
// 	// temp2 = stack->top->prev;
// 	// while (i < stack->size)
// 	// {
// 	// 	// printf("i: %zu\n", i);
// 	// 	j = -1;
// 	// 	while (j < stack->size)
// 	// 	{
// 	// 		j++;
// 	// 		// printf("j: %zu\n", j);
// 	// 		if (i == j)
// 	// 			continue ;
// 	// 		if (temp->cont.i == temp2->cont.i)
// 	// 			return (1);
// 	// 		temp2 = temp2->prev;
// 	// 	}
// 	// 	temp = temp->prev;
// 	// 	i++;
// 	// }

// 	temp = stack->top;
// 	while (temp->prev)
// 	{
// 		if (temp->cont.i == temp->prev->cont.i)
// 			return (1);
// 		temp = temp->prev;
// 	}
// 	return (0);
// }

int	has_duplicates(t_stack *stack)
{
	size_t			i;
	t_stack_elem	*temp;
	int				*arr;

	i = 0;

	// printf("Stack size: %zu\n", stack->size);
	// printf("Before sort:\n");
	// ft_stackprint(stack, NULL, "\n");

	arr = stack_to_array(stack, stack->size);
	quicksort(arr, 0, stack->size - 1);
	stack = array_to_stack(arr, stack->size);

	// printf("After sort:\n");
	// ft_stackprint(stack, NULL, "\n");

	temp = stack->top;
	while (temp->prev)
	{
		if (temp->cont.i == temp->prev->cont.i)
			return (1);
		temp = temp->prev;
	}

	return (0);
}
