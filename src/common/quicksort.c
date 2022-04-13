/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:47:27 by fporto            #+#    #+#             */
/*   Updated: 2022/03/03 16:47:28 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swapqs(int *first, int *second)
{
	int	temp;

	temp = *first;
	*first = *second;
	*second = temp;
}

static int	partitionqs(int arr[], int lower, int upper)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[upper];
	i = lower - 1;
	j = lower - 1;
	while (++j < upper)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swapqs(&arr[i], &arr[j]);
		}
	}
	swapqs(&arr[i + 1], &arr[upper]);
	return (i + 1);
}

void	quicksort(int arr[], int lower, int upper)
{
	int	partition_index;

	if (upper > lower)
	{
		partition_index = partitionqs(arr, lower, upper);
		quicksort(arr, lower, partition_index - 1);
		quicksort(arr, partition_index + 1, upper);
	}
}
