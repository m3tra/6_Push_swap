/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:50:15 by fporto            #+#    #+#             */
/*   Updated: 2022/03/03 16:50:15 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

# include "../stack/ft_stack.h"

typedef struct s_ps
{
	t_stack	*as;
	t_stack	*bs;
	t_stack	*a;
	t_stack	*b;
}	t_ps;

void	pa(t_ps *ps);
void	pb(t_ps *ps);
void	ra(t_ps *ps);
void	rb(t_ps *ps);
void	rr(t_ps *ps);
void	rra(t_ps *ps);
void	rrb(t_ps *ps);
void	rrr(t_ps *ps);
void	sa(t_ps *ps);
void	sb(t_ps *ps);
void	ss(t_ps *ps);

void	print_pa(t_ps *ps);
void	print_pb(t_ps *ps);
void	print_ra(t_ps *ps);
void	print_rb(t_ps *ps);
void	print_rr(t_ps *ps);
void	print_rra(t_ps *ps);
void	print_rrb(t_ps *ps);
void	print_rrr(t_ps *ps);
void	print_sa(t_ps *ps);
void	print_sb(t_ps *ps);
void	print_ss(t_ps *ps);

#endif
