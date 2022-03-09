/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:54:40 by fporto            #+#    #+#             */
/*   Updated: 2022/03/09 20:59:37 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_stack.h"

void	new_chunk(t_ps *ps)
{
	t_content	content;

	content.size = 0;
	content.i = 0;
	content.arr = malloc(sizeof(char));
	content.arr[0] = '\0';
	ft_stackpush(ps->chunks, content);
}

void	add_to_chunk(t_ps *ps)
{
	t_stack_elem	*elem;
	char			*tmp;
	char			*conv;

	elem = ps->chunks->top;
	conv = ft_itoa(ps->a->top->cont.i);
	// printf("a->top->cont.i: %d\n", ps->a->top->cont.i);
	if (elem->cont.size > 0)
		tmp = ft_strjoin(elem->cont.arr, " ");
	else
		tmp = ft_strjoin(elem->cont.arr, "");
	free(elem->cont.arr);
	elem->cont.arr = tmp;
	tmp = ft_strjoin(elem->cont.arr, conv);
	free(elem->cont.arr);
	elem->cont.arr = tmp;
	elem->cont.size++;
	free(conv);
}

void	print_chunks(t_ps *ps)
{
	t_stack_elem	*elem;
	t_stack			*stack;

	ft_putstr_fd("Chunks:\n", 1);
	stack = ps->chunks;
	if (stack->size > 0)
	{
		if (!stack)
			return ;
		elem = stack->top;
		if (elem)
			ft_putstr_fd(elem->cont.arr, 1);
		while (elem->prev)
		{
			elem = elem->prev;
			ft_putstr_fd("\n", 1);
			ft_putstr_fd(elem->cont.arr, 1);
		}
	}
	else
		ft_putstr_fd("\tNo chunks\n", 1);
	ft_putstr_fd("\n\n", 1);
}
