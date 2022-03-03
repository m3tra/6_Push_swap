/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackpush.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 01:03:41 by mgueifao          #+#    #+#             */
/*   Updated: 2022/02/10 06:03:21 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stackpush(t_stack *stack, t_content content)
{
	t_stack_elem	*new;

	new = malloc(sizeof(t_stack_elem));
	new->cont = content;
	new->prev = stack->top;
	stack->top = new;
	stack->size++;
}
