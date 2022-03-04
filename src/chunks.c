/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:54:40 by fporto            #+#    #+#             */
/*   Updated: 2022/03/04 18:05:25 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_stack.h"

// void	chunkdestroy(t_chunk *chunk)
// {
// 	t_chunk_elem	*elem;

// 	while (chunk->size)
// 	{
// 		elem = chunk->top;
// 		chunk->top = chunk->top->prev;
// 		chunk->size--;
// 		free(elem);
// 	}
// 	free(chunk);
// }

// static void	populate2(t_chunk_elem **dest, t_chunk_elem *src)
// {
// 	if (!src)
// 		return ;
// 	*dest = malloc(sizeof(t_chunk_elem));
// 	(*dest)->arr = src->arr;
// 	(*dest)->size = src->size;
// 	populate2(&((*dest)->prev), src->prev);
// }

// t_chunk	*chunkdup(t_chunk *chunks)
// {
// 	t_chunk	*ret;
// 	int		i;

// 	i = -1;
// 	if (!chunks)
// 		return (NULL);
// 	ret = malloc(sizeof(t_chunk));
// 	if(!ret)
// 		return (NULL);
// 	populate2(&(ret->top), chunks->top);
// 	ret->size = chunks->size;
// 	return(ret);
// }
