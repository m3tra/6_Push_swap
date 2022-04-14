/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 23:07:13 by fporto            #+#    #+#             */
/*   Updated: 2022/04/14 01:00:09 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_size(t_stack *a)
{
	t_stack_elem	*tmp;
	int				count;

	tmp = a->top;
	count = 0;
	while (tmp)
	{
		count++;
		tmp = tmp->prev;
	}
	return (count);
}

int	is_empty(struct s_stack *stack)
{
	if (!stack->top)
		return (1);
	return (0);
}

void	print_move_list(t_mvs_lst *list)
{
	t_move	*elem;

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

void	compare_two(t_mvs_lst *list, t_move *tmp, t_move *next)
{
	if ((!ft_strcmp(tmp->move, "ra") && !ft_strcmp(next->move, "rra"))
		|| (!ft_strcmp(tmp->move, "rra") && !ft_strcmp(next->move, "ra"))
		|| (!ft_strcmp(tmp->move, "rr") && !ft_strcmp(next->move, "rrr"))
		|| (!ft_strcmp(tmp->move, "rrr") && !ft_strcmp(next->move, "rr"))
		|| (!ft_strcmp(tmp->move, "pa") && !ft_strcmp(next->move, "pb"))
		|| (!ft_strcmp(tmp->move, "pb") && !ft_strcmp(next->move, "pa")))
	{
		moves_list_pop(list, next);
		moves_list_pop(list, tmp);
		tmp = list->first;
	}
	else if ((!ft_strcmp(tmp->move, "rra") && !ft_strcmp(next->move, "rrb"))
		|| (!ft_strcmp(tmp->move, "rrb") && !ft_strcmp(next->move, "rra")))
	{
		moves_list_pop(list, next);
		tmp->move = "rrr";
		tmp = list->first;
	}
	else if (!ft_strcmp(tmp->move, "ra") && !ft_strcmp(next->move, "rb"))
	{
		moves_list_pop(list, next);
		tmp->move = "rr";
		tmp = list->first;
	}
}

void	optimize(t_ps *ps)
{
	t_move	*tmp;
	t_move	*next;

	tmp = ps->moves->first;
	while (tmp->next->next)
	{
		next = tmp->next;
		compare_two(ps->moves, tmp, next);
		if (!ft_strcmp(tmp->move, "pa") && !ft_strcmp(next->move, "rrb")
			&& !ft_strcmp(next->next->move, "pb"))
		{
			moves_list_pop(ps->moves, next->next);
			tmp->move = "rrb";
			next->move = "sb";
			tmp = ps->moves->first;
		}
		else if (!ft_strcmp(tmp->move, "pb") && !ft_strcmp(next->move, "rra")
			&& !ft_strcmp(next->next->move, "pa"))
		{
			moves_list_pop(ps->moves, next->next);
			tmp->move = "rra";
			next->move = "sa";
			tmp = ps->moves->first;
		}
	}
}
