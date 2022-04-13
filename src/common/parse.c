/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:47:22 by fporto            #+#    #+#             */
/*   Updated: 2022/04/13 16:38:33 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	destroy_ps(t_ps *ps)
{
	if (ps->a)
		ft_stackdestroy(ps->a, NULL);
	if (ps->b)
		ft_stackdestroy(ps->b, NULL);
	if (ps->chunks)
		ft_stackdestroy(ps->chunks, free);
	if (ps->moves)
		moves_list_destroy(ps->moves);
	free(ps);
}

static int	check_int(const char *arg)
{
	int	count;

	count = -1;
	if (*arg == '-')
		count++;
	while (arg[++count])
		if (!ft_isdigit(*(arg + count)))
			return (0);
	if (count == 1 && arg[0] == '-')
		return (0);
	if (arg[0] == '-' && (ft_strlen(arg) > 11 || (ft_strlen(arg) == 11 \
		&& ft_memcmp(arg, "-2147483648", 11) > 0)))
		return (0);
	if (arg[0] != '-' && ((ft_strlen(arg) == 10 \
		&& ft_memcmp(arg, "2147483647", 11) > 0) || ft_strlen(arg) > 10))
		return (0);
	return (1);
}

t_ps	*parse_args(int argc, char *argv[])
{
	t_ps		*ret;
	t_content	cont;

	ret = malloc(sizeof(t_ps));
	if (!ret)
		return (NULL);
	ret->a = ft_stacknew();
	ret->b = ft_stacknew();
	ret->chunks = ft_stacknew();
	ret->moves = moves_list_new();
	while (argc--)
	{
		if (!check_int(argv[argc]))
			destroy_ps(ret);
		if (!check_int(argv[argc]))
			return (NULL);
		cont.i = ft_atoi(argv[argc]);
		cont.arr = NULL;
		cont.size = 0;
		ft_stackpush(ret->a, cont);
	}
	has_duplicates(ret);
	return (ret);
}

t_ps	*parse_string(const char *arg)
{
	t_ps	*ret;
	char	**nums;
	int		count;

	nums = ft_split(arg, ' ');
	count = 0;
	while (nums[count])
		count++;
	ret = parse_args(count, (char **)nums);
	count = 0;
	while (nums[count])
		free(nums[count++]);
	free(nums);
	return (ret);
}
