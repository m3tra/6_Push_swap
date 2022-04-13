/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:47:30 by fporto            #+#    #+#             */
/*   Updated: 2022/04/13 16:02:13 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	execute(t_ps *ps)
{
	if (ps->a->size <= 2)
	{
		if (ps->a->size == 2 && ps->a->top->cont.i > ps->a->top->prev->cont.i)
			sa(ps);
		destroy_ps(ps);
		return ;
	}
	if (is_sorted(ps->a, 1))
	{
		destroy_ps(ps);
		return ;
	}
	midpoint(ps);
	while (ps->b->size > 0)
		move_highest(ps);
}

int	main(int argc, char **argv)
{
	t_ps	*ps;

	if (argc < 2)
		err_exit();
	if (argc == 2)
		ps = parse_string(argv[1]);
	else
		ps = parse_args(argc - 1, &(argv[1]));
	if (!ps)
		err_exit();
	execute(ps);
	optimize(ps);
	destroy_ps(ps);
	return (0);
}
