/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 01:28:11 by fporto            #+#    #+#             */
/*   Updated: 2022/03/15 20:46:48 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	exec_move(t_ps *ps, char *move)
{
	if (!ft_strcmp(move, "pa"))
		pa(ps);
	else if (!ft_strcmp(move, "pb"))
		pb(ps);
	else if (!ft_strcmp(move, "ra"))
		ra(ps);
	else if (!ft_strcmp(move, "rb"))
		rb(ps);
	else if (!ft_strcmp(move, "rr"))
		rr(ps);
	else if (!ft_strcmp(move, "rra"))
		rra(ps);
	else if (!ft_strcmp(move, "rrb"))
		rrb(ps);
	else if (!ft_strcmp(move, "rrr"))
		rrr(ps);
	else if (!ft_strcmp(move, "sa"))
		sa(ps);
	else if (!ft_strcmp(move, "sb"))
		sb(ps);
	else if (!ft_strcmp(move, "ss"))
		ss(ps);
	else
		return (0);
	return (1);
}

static void	checker(t_ps *ps)
{
	char	*line;
	int		*arr;
	t_stack	*stack;

	while (get_next_line(STDIN_FILENO, &line))
	{
		if (!exec_move(ps, line))
			break ;
		free(line);
	}
	arr = stack_to_array(ps->a);
	quicksort(arr, 0, ps->a->size - 1);
	stack = array_to_stack(arr, ps->a->size);
	if (is_sorted(stack, 1) && ps->b->size == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	if (line)
		free(line);
	free(arr);
	ft_stackdestroy(stack, NULL);
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
	checker(ps);
	ft_stackprint(ps->a, NULL, "\n");
	destroy_ps(ps);
	return (0);
}
