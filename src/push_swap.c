/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:47:30 by fporto            #+#    #+#             */
/*   Updated: 2022/03/06 23:21:21 by fporto           ###   ########.fr       */
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

	// printf("Stack A:\nSize: %ld\n", ps->a->size);
	// ft_stackprint(ps->a, NULL, "\n");
	// printf("\nStack B:\nSize: %ld\n", ps->b->size);
	// ft_stackprint(ps->b, NULL, "\n");

	ps->chunks = ft_stacknew();
	midpoint(ps);
	sort_trio(ps);
	while (ps->b->size > 0)
		move_highest(ps);

	// printf("\n**************AFTER**************\n\n");
	// print_chunks(ps);

	printf("is A sorted: %d\n", is_sorted(ps->a, 1));

	// printf("Stack A:\n");
	// printf("Size: %ld\n", ps->a->size);
	// ft_stackprint(ps->a, NULL, "\n");

	destroy_ps(ps);
	return (0);
}
