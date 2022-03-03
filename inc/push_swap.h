/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:58:41 by fporto            #+#    #+#             */
/*   Updated: 2022/03/03 17:06:58 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include "ft_stack.h"

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

void	err_exit(char *err);

int		is_sorted(t_stack *arr);

void	ft_copystack(int size, int arr[], int copy[]);

t_ps	*parse_args(int argc, char *argv[]);
t_ps	*parse_string(char *s);
void	pick(t_ps *ps);
void	execute_big(t_ps *ps);
void	execute_med(t_ps *ps);
void	execute_small(t_ps *ps);

void	quicksort(int arr[], int lower, int upper);
void	quicksort_stack(t_stack *stack, int lower, int upper);

int		has_duplicates(t_stack *stack);
int		get_cont_i(t_stack *stack, int n);

int		*stack_to_array(t_stack *s, int size);
t_stack	*array_to_stack(int arr[], int size);

#endif
