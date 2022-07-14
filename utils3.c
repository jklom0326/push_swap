/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shan <shan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 21:59:40 by shan              #+#    #+#             */
/*   Updated: 2022/07/14 21:59:40 by shan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	is_get_min(t_p1 *a)
{
	int	min;
	int	i;

	min = a->arry[0];
	i = 0;
	while (i <= a->top)
	{
		if (a->arry[i] < min)
			min = a->arry[i];
		i++;
	}
	return (min);
}

int	get_min_index(int *arr, int size)
{
	int	index;
	int	min;
	int	i;

	index = 0;
	min = arr[index];
	i = 0;
	while (i < size)
	{
		if (arr[i] <= min)
		{
			index = i;
			min = arr[index];
		}
		i++;
	}
	return (index);
}

int	get_next_nb(t_p1 *a, int nb)
{
	int	i;
	int	j;

	i = 0;
	while (i <= a->top)
	{
		j = t_circle(&a, i);
		if (a->arry[i] < nb && a->arry[j] > nb)
			return (a->arry[j]);
		i++;
	}
	return (is_get_min(a));
}
