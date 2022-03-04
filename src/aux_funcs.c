/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:47:13 by fporto            #+#    #+#             */
/*   Updated: 2022/03/04 18:07:47 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_stack.h"

void	err_exit(char *err)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(err, 1);
	ft_putchar_fd('\n', 1);
	exit(EXIT_FAILURE);
}

int	get_cont_i(t_stack *stack, int n)
{
	t_stack_elem	*elem;
	int				i;

	elem = stack->top;
	i = -1;
	while (++i < n)
	{
		if (!elem->prev)
			break ;
		elem = elem->prev;
	}
	return (elem->cont.i);
}

int	*stack_to_array(t_stack *s, int size)
{
	int				*ret;
	t_stack_elem	*curr;
	int				i;

	ret = malloc(sizeof(int) * size);
	curr = s->top;
	i = 0;
	while (i < size)
	{
		ret[i++] = curr->cont.i;
		curr = curr->prev;
	}
	return (ret);
}

t_stack	*array_to_stack(int arr[], int size)
{
	t_stack		*stack;
	t_content	cont;

	stack = ft_stacknew();
	while (--size >= 0)
	{
		cont.arr = NULL;
		cont.i = arr[size];
		ft_stackpush(stack, cont);
	}
	return (stack);
}

void	sort_chunk(int *arr, int size)
{
	quicksort(arr, 0, size - 1);
}

// void	track_chunks(t_stack *stack, )
// {

// }
