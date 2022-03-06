/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:54:40 by fporto            #+#    #+#             */
/*   Updated: 2022/03/06 23:19:35 by fporto           ###   ########.fr       */
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
	if (elem->cont.size >= 1)
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

static	void	cut_number(t_ps *ps, int size)
{
	char		*ret;

	ret = ft_strdup(ps->chunks->top->cont.arr + size + 1);
	free (ps->chunks->top->cont.arr);
	ps->chunks->top->cont.arr = ret;
}

void	subtract_from_chunk(t_ps *ps)
{
	int		n;
	char	*conv;
	size_t	size;

	n = ps->b->top->cont.i;
	conv = ft_itoa(n);
	size = ft_strlen(ps->chunks->top->cont.arr) - ft_strlen(conv);
	cut_number(ps, size);
	ps->chunks->top->cont.size--;
	// printf("subtract: %d\n", n);
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
	ft_putstr_fd("\n\n", 1);
}
