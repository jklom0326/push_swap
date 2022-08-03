/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shan <shan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 01:50:23 by shan              #+#    #+#             */
/*   Updated: 2022/07/17 01:50:23 by shan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_index	*fill_array(int ac, t_index *array, int i, int j)
{
	int		minor;
	int		major;

	major = INT_MIN;
	while (j < ac - 1)
	{
		minor = INT_MAX;
		while (++i < ac - 1)
		{
			if (array[i].value <= minor && array[i].value > major)
			{
				minor = array[i].value;
				array[i].index = j;
			}
		}
		j++;
		major = minor;
		i = -1;
	}
	return (array);
}

int	*index_it(int ac, char *av[])
{
	int		i;
	int		j;
	int		*return_it;
	t_index	*array;

	array = (t_index *)malloc(sizeof(t_index) * (ac - 1));
	if (!(array))
		return (NULL);
	return_it = (int *)malloc(sizeof(int) * (ac - 1));
	if (!(return_it))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < ac - 1)
		array[i].value = atoi(av[i + 1]);
	i = -1;
	array = fill_array(ac, array, i, j);
	while (++i < ac - 1)
		return_it[i] = array[i].index;
	free(array);
	return (return_it);
}
