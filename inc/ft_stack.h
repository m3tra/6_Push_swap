/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:50:19 by fporto            #+#    #+#             */
/*   Updated: 2022/03/03 19:46:00 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

# include "libft.h"

typedef union u_content
{
	void	*ptr;
	int		i;
}				t_content;

typedef struct s_stack_elem
{
	t_content			cont;
	struct s_stack_elem	*prev;
}				t_stack_elem;

typedef struct s_stack
{
	size_t			size;
	t_stack_elem	*top;
}				t_stack;

typedef struct s_ps
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*as;
	t_stack	*bs;
}	t_ps;

void		ft_stackdestroy(t_stack *stack, void (*del)(t_content));
t_stack		*ft_stackdup(t_stack *o, t_content(*dup)(t_content));
t_stack		*ft_stacknew(void);
t_content	ft_stackpeek(t_stack *stack);
t_content	ft_stackpop(t_stack *stack);
void		ft_stackprint(t_stack *s, char *(*to_str)(t_content), char *delim);
void		ft_stackpush(t_stack *stack, t_content content);

#endif
