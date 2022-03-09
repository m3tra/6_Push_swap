/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:47:30 by fporto            #+#    #+#             */
/*   Updated: 2022/03/09 20:58:38 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_ps	*ps;

	if (argc < 2)
		err_exit("Missing arguments");
	if (argc == 2)
		ps = parse_string(argv[1]);
	else
		ps = parse_args(argc - 1, &(argv[1]));
	if (!ps)
		err_exit("Failed parsing");
	if (ps->a->size <= 2)
	{
		if (ps->a->size == 2 && ps->a->top->cont.i > ps->a->top->prev->cont.i)
			sa(ps);
		destroy_ps(ps);
		return (0);
	}

	// printf("1\n");

	if (is_sorted(ps->a, 1))
	{
		destroy_ps(ps);
		return(0);
	}
	ps->chunks = ft_stacknew();
	midpoint(ps);

	// printf("2\n");

	// print_ps(ps);

	// print_ps(ps);

	while (ps->b->size > 0)
		move_highest(ps);

	// printf("\n**************AFTER**************\n\n");
	// print_chunks(ps);

	// print_ps(ps);
	// printf("is A sorted: %d\n", is_sorted(ps->a, 1));

	destroy_ps(ps);
	return (0);
}
