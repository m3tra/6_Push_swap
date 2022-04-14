/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:58:41 by fporto            #+#    #+#             */
/*   Updated: 2022/04/14 00:41:06 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include "ft_stack.h"

# define PRINT_MOVES 0

void	err_exit(void);
int		get_cont_i(t_stack *stack, int n);
int		*stack_to_array(t_stack *stack);
t_stack	*array_to_stack(int arr[], int size);
int		find_in_arr(int *arr, int size, int n);
int		is_sorted(t_stack *arr, int asc);
void	has_duplicates(t_ps *ps);
void	destroy_ps(t_ps *ps);

void	new_chunk(t_ps *ps);
void	add_to_chunk(t_ps *ps);
void	subtract_from_chunk(t_ps *ps);
void	print_chunks(t_ps *ps);

t_ps	*parse_args(int argc, char *argv[]);
t_ps	*parse_string(const char *s);

void	quicksort(int arr[], int lower, int upper);
void	quicksort_stack(t_stack *stack, int lower, int upper);

void	midpoint(t_ps *ps);
void	sort_trio(t_ps *ps);
void	move_highest(t_ps *ps);
void	sort(t_ps *ps);
void	optimize(t_ps *ps);

void	print_ps(t_ps *ps);

#endif
