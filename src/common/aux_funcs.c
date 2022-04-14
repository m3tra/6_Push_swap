/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:47:13 by fporto            #+#    #+#             */
/*   Updated: 2022/04/14 00:50:06 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_stack.h"

void	err_exit(void)
{
	ft_putstr_fd("Error\n", 2);
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

int	*stack_to_array(t_stack *stack)
{
	int				*ret;
	t_stack_elem	*curr;
	size_t			i;

	ret = malloc(sizeof(int) * stack->size);
	curr = stack->top;
	i = 0;
	while (i < stack->size)
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

void	moves_list_destroy(t_mvs_lst *list)
{
	t_move	*tmp;

	tmp = list->first;
	if (tmp)
	{
		while (tmp->next)
		{
			tmp = tmp->next;
			free(tmp->prev);
		}
		free(tmp);
		free(list);
	}
}
