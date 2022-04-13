/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:50:19 by fporto            #+#    #+#             */
/*   Updated: 2022/04/13 17:21:19 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

# include "libft.h"

typedef struct u_content
{
	char	*arr;
	size_t	size;
	int		i;
}	t_content;

typedef struct s_stack_elem
{
	t_content			cont;
	struct s_stack_elem	*prev;
}	t_stack_elem;

typedef struct s_stack
{
	size_t			size;
	t_stack_elem	*top;
}	t_stack;

typedef struct s_move
{
	char			*move;
	struct s_move	*prev;
	struct s_move	*next;
}	t_move;

typedef struct s_moves_list
{
	size_t	size;
	t_move	*first;
}	t_moves_list;

typedef struct s_ps
{
	t_stack			*a;
	t_stack			*b;
	t_stack			*chunks;
	t_moves_list	*moves;
}	t_ps;

void		pa(t_ps *ps);
void		pb(t_ps *ps);
void		ra(t_ps *ps);
void		rb(t_ps *ps);
void		rr(t_ps *ps);
void		rra(t_ps *ps);
void		rrb(t_ps *ps);
void		rrr(t_ps *ps);
void		sa(t_ps *ps);
void		sb(t_ps *ps);
void		ss(t_ps *ps);

void		ft_stackdestroy(t_stack *stack, void (*del)(void *));
t_stack		*ft_stackdup(t_stack *o, t_content(*dup)(t_content));
t_stack		*ft_stacknew(void);
t_content	ft_stackpeek(t_stack *stack);
t_content	ft_stackpop(t_stack *stack);
void		ft_stackprint(t_stack *s, char *(*to_str)(t_content), char *delim);
void		ft_stackpush(t_stack *stack, t_content content);

t_move			*move_new(char *str);
t_moves_list	*moves_list_new(void);
t_move			*moves_lstlast(t_moves_list *list);
void			moves_list_cat(t_moves_list *lst, t_move *move);
void			moves_list_pop(t_moves_list *list, t_move *move);
void			moves_list_destroy(t_moves_list *moves);

#endif
