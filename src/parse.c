/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:47:22 by fporto            #+#    #+#             */
/*   Updated: 2022/03/04 18:09:55 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps	*dup_ps(t_ps *ps)
{
	t_ps	*ret;

	ret = malloc(sizeof(t_ps));
	if (!ret)
		return (NULL);
	ret->a = ft_stackdup(ps->a, NULL);
	ret->b = ft_stackdup(ps->b, NULL);
	ret->chunks = ft_stackdup(ps->chunks, NULL);
	return (ret);
}

void	destroy_ps(t_ps *ps)
{
	if (ps->a)
		ft_stackdestroy(ps->a, NULL);
	if (ps->b)
		ft_stackdestroy(ps->b, NULL);
	if (ps->chunks)
		ft_stackdestroy(ps->chunks, NULL);
	free(ps);
}

static int	check_int(const char *n)
{
	int	count;

	count = -1;
	if (*n == '-')
		count++;
	while (n[++count])
		if (!ft_isdigit(*(n + count)))
			return (0);
	if (count == 1 && n[0] == '-')
		return (0);
	if (n[0] == '-' && (ft_strlen(n) > 11 || (ft_strlen(n) == 11
				&& ft_memcmp(n, "-2147483648", 11) > 0)))
		return (0);
	if (n[0] != '-' && ((ft_strlen(n) == 10
				&& ft_memcmp(n, "2147483647", 11) > 0) || ft_strlen(n) > 10))
		return (0);
	return (1);
}

t_ps	*parse_args(int argc, char *argv[])
{
	t_ps		*ret;
	t_content	tmp;

	ret = malloc(sizeof(t_ps));
	if (!ret)
		return (NULL);
	ret->a = ft_stacknew();
	ret->b = ft_stacknew();
	ret->chunks = NULL;
	while (argc--)
	{
		if (!check_int(argv[argc]))
			destroy_ps(ret);
		if (!check_int(argv[argc]))
			return (NULL);
		tmp.i = ft_atoi(argv[argc]);
		ft_stackpush(ret->a, tmp);
	}
	if (has_duplicates(ret->a))
	{
		err_exit("Has duplicates");
		destroy_ps(ret);
		return (NULL);
	}
	return (ret);
}

t_ps	*parse_string(char *s)
{
	t_ps	*ret;
	char	**nums;
	int		count;

	nums = ft_split(s, ' ');
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
