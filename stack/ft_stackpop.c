/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackpop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 01:14:57 by mgueifao          #+#    #+#             */
/*   Updated: 2021/08/01 16:32:55 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

t_content	ft_stackpop(t_stack *stack)
{
	t_content		ret;
	t_stack_elem	*tmp;

	tmp = stack->top;
	stack->top = stack->top->prev;
	stack->size--;
	ret = tmp->cont;
	free(tmp);
	return (ret);
}
