/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:47:22 by fporto            #+#    #+#             */
/*   Updated: 2022/03/03 18:20:27 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_ps	*parseArgs(int argc, char *argv[])
// {
// 	t_ps	*ret;
// 	int		tmp;
// 	int		i;

// 	ret = malloc(sizeof(t_ps));
// 	if (!ret)
// 		return (NULL);
// 	ret->a = ft_stacknew();
// 	ret->b = ft_stacknew();
// 	while (argc--)
// 	{
// 		i = -1;
// 		while (argv[argc][++i])
// 			if (argv[argc][i] != ft_isspace(' ') && ft_isdigit(argv[argc][i]))
// 				return (NULL);
// 		tmp = ft_atoi(argv[argc]);
// 		ft_stackpush(ret->a, (t_content)tmp);
// 	}
// 	return (ret);
// }

// t_ps	*parseString(char *s)
// {
// 	t_ps	*ret;
// 	char	**nums;
// 	int		i;

// 	i = -1;
// 	while (s[++i])
// 		if (s[i] != ' ' && !ft_isdigit(s[i]))
// 			return (NULL);
// 	nums = ft_split(s, ' ');
// 	i = 0;
// 	while (nums[i])
// 		i++;
// 	ret = parseArgs(i, (char **)nums);
// 	i = 0;
// 	while (nums[i])
// 		free(nums[i++]);
// 	free(nums);
// 	return (ret);
// }

t_ps	*dup_ps(t_ps *ps)
{
	t_ps	*ret;

	ret = malloc(sizeof(t_ps));
	if (!ret)
		return (NULL);
	ret->a = ft_stackdup(ps->a, NULL);
	ret->b = ft_stackdup(ps->b, NULL);
	ret->as = ft_stackdup(ps->as, NULL);
	ret->bs = ft_stackdup(ps->bs, NULL);
	return (ret);
}

void	destroy_ps(t_ps *ps)
{
	if (ps->a)
		ft_stackdestroy(ps->a, NULL);
	if (ps->b)
		ft_stackdestroy(ps->b, NULL);
	if (ps->as)
		ft_stackdestroy(ps->as, NULL);
	if (ps->bs)
		ft_stackdestroy(ps->bs, NULL);
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

// void	print_arr(int arr[])
// {
// 	int	i;

// 	i = 0;
// 	printf("Sorted array:\n");
// 	while(arr[i])
// 		printf("\t%d\n", arr[i++]);
// 	printf("\n\n");
// }

// static int	check_dups(t_ps *ps)
// {
// 	int	*arr;
// 	int	i;

// 	arr = stack_to_array(ps->a, ps->a->size);
// 	quicksort(arr, 0, ps->a->size - 1);
// 	// print_arr(arr);
// 	i = -1;
// 	while (++i < (int) ps->a->size - 1)
// 	{
// 		if (arr[i] == arr[i + 1])
// 		{
// 			i = -1;
// 			break ;
// 		}
// 	}
// 	free(arr);
// 	return (i != -1);
// }

t_ps	*parse_args(int argc, char *argv[])
{
	t_ps		*ret;
	t_content	tmp;

	ret = malloc(sizeof(t_ps));
	if (!ret)
		return (NULL);
	ret->a = ft_stacknew();
	ret->b = ft_stacknew();
	ret->bs = NULL;
	ret->as = NULL;
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
