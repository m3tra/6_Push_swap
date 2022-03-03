/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:47:30 by fporto            #+#    #+#             */
/*   Updated: 2022/03/03 19:30:30 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_copystack(int size, int arr[], int copy[])
{
	int	i;

	i = -1;
	while (++i < size)
		copy[i] = arr[i];
}

// void pick(t_ps *ps)
// {
// 	if (ps->a->size <= 10)
// 		execute_small(ps);
// 	else if (ps->a->size <= 100)
// 		execute_med(ps);
// 	else
// 		execute_big(ps);
// }

int	main(int argc, char *argv[])
{
	t_ps			*ps;

	if (argc < 2)
		err_exit("Missing arguments");
	if (argc == 2)
		ps = parse_string(argv[1]);
	else
		ps = parse_args(argc - 1, &(argv[1]));
	if (!ps)
		err_exit("Failed parsing");
	ps->as = ft_stacknew();
	ps->bs = ft_stacknew();
	if (!ps->as || !ps->bs)
		err_exit("Failed malloc of ps->as or ps->bs");
	// printf("Ptr: %p\n", (void *)ps->a);

	printf("Stack A:\n");
	printf("Size: %ld\n", ps->a->size);
	ft_stackprint(ps->a, NULL, "\n");

	printf("Stack B:\n");
	printf("Size: %ld\n", ps->b->size);
	ft_stackprint(ps->b, NULL, "\n");



	if (is_sorted(ps->a))
		printf("OK Array IS SORTED\n");
	else
		printf("[!] Array NOT SORTED\n");


	// ft_stackpush(ps->as, cont);
	// pick(ps);
	// ft_stackdestroy(ps->a, NULL);
	// ft_stackdestroy(ps->b, NULL);
	// ft_stackdestroy(ps->as, NULL);
	// ft_stackdestroy(ps->bs, NULL);
	free(ps);
	return (0);
}
