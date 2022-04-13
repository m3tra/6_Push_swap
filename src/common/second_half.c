/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_half.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 23:07:13 by fporto            #+#    #+#             */
/*   Updated: 2022/04/13 17:31:22 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_highest(t_ps *ps)
{
	int				biggest;
	int				index;
	t_stack_elem	*elem;
	size_t			i;

	elem = ps->b->top;
	biggest = elem->cont.i;
	if (ps->b->size == 1)
		return (biggest);
	index = 0;
	i = 0;
	while (i < ps->chunks->top->cont.size - 1)
	{
		elem = elem->prev;
		i++;
		if (elem->cont.i > biggest)
		{
			biggest = elem->cont.i;
			index = i;
		}
	}
	return (index);
}

void	move_highest(t_ps *ps)
{
	size_t	i;
	size_t	j;

	if (ps->chunks->top->cont.size == 1)
	{
		pa(ps);
		free(ps->chunks->top->cont.arr);
		ft_stackpop(ps->chunks);
		return ;
	}
	i = find_highest(ps);
	j = i;
	i++;
	while (--i > 0)
		rb(ps);
	pa(ps);
	ps->chunks->top->cont.size--;
	i--;
	while (++i < j)
		rrb(ps);
	move_highest(ps);
}

void	print_move_list(t_moves_list *list)
{
	t_move	*elem;

	printf("move list:\n");
	if (list)
	{
		elem = list->first;
		while (elem->next)
		{
			printf("%s\n", elem->move);
			elem = elem->next;
		}
		printf("%s\n", elem->move);
	}
}

void	optimize(t_ps *ps)
{
	t_moves_list *list;
	t_move	*temp;

	list = ps->moves;
	print_move_list(list);
	temp = list->first;
	while (temp->next)
	{
		if ((ft_strcmp(temp->move, "ra") && ft_strcmp(temp->next->move, "rra"))
			|| (ft_strcmp(temp->move, "rra") && ft_strcmp(temp->next->move, "ra"))
			|| (ft_strcmp(temp->move, "rr") && ft_strcmp(temp->next->move, "rrr"))
			|| (ft_strcmp(temp->move, "rrr") && ft_strcmp(temp->next->move, "rr"))
			|| (ft_strcmp(temp->move, "pa") && ft_strcmp(temp->next->move, "pb"))
			|| (ft_strcmp(temp->move, "pb") && ft_strcmp(temp->next->move, "pa")))
		{
			moves_list_pop(list, temp->next);
			moves_list_pop(list, temp);
		}
		else if (ft_strcmp(temp->move, "pa") && ft_strcmp(temp->next->move, "rrb")
			&& ft_strcmp(temp->next->next->move, "pb"))
		{
			moves_list_pop(list, temp->next->next);
			temp->move = "rrb";
			temp->next->move = "sb";
		}
		else if (ft_strcmp(temp->move, "pb") && ft_strcmp(temp->next->move, "rra")
			&& ft_strcmp(temp->next->next->move, "pa"))
		{
			moves_list_pop(list, temp->next->next);
			temp->move = "rra";
			temp->next->move = "sa";
		}
		else if ((ft_strcmp(temp->move, "rra") && ft_strcmp(temp->next->move, "rrb"))
			|| (ft_strcmp(temp->move, "rrb") && ft_strcmp(temp->next->move, "rra")))
		{
			moves_list_pop(list, temp->next);
			temp->move = "rrr";
		}
		else if (ft_strcmp(temp->move, "ra") && ft_strcmp(temp->next->move, "rb"))
		{
			moves_list_pop(list, temp->next);
			temp->move = "rr";
		}
		temp = temp->next;
	}
	print_move_list(list);
}
