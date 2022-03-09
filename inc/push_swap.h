/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:58:41 by fporto            #+#    #+#             */
/*   Updated: 2022/03/09 20:41:31 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include "ft_stack.h"

# define PRINT_MOVES 1

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
int		get_cont_i(t_stack *stack, int n);
void	has_duplicates(t_ps *ps);
int		is_sorted(t_stack *arr, int asc);
void	destroy_ps(t_ps *ps);

void	new_chunk(t_ps *ps);
void	add_to_chunk(t_ps *ps);
void	subtract_from_chunk(t_ps *ps);
void	print_chunks(t_ps *ps);

int		*stack_to_array(t_stack *stack);
t_stack	*array_to_stack(int arr[], int size);
int		find_in_arr(int *arr, int size, int n);

t_ps	*parse_args(int argc, char *argv[]);
t_ps	*parse_string(const char *s);

void	quicksort(int arr[], int lower, int upper);
void	quicksort_stack(t_stack *stack, int lower, int upper);

void	midpoint(t_ps *ps);
void	sort_trio(t_ps *ps);
void	move_highest(t_ps *ps);

//TODO

void	print_ps(t_ps *ps);

#endif
