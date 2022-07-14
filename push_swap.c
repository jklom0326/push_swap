/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shan <shan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 01:11:34 by shan              #+#    #+#             */
/*   Updated: 2022/07/15 01:11:34 by shan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static	void	ft_free(t_p1 *a, t_p1 *b)
{
	free(b->arry);
	free(b);
	free(a->arry);
	free(a);
}

int	main(int ac, char **av)
{
	int		i;
	char	**tab;
	int		count;
	t_p1	*a;
	t_p1	*b;

	tab = push_in_t_stack(ac, av, &i);
	count = i;
	a = creat_stack(i);
	b = creat_stack(i);
	i = i - 1;
	while (i >= 0)
		push(a, ft_atoi(tab[i--]));
	if (count == 1)
		exit (2);
	else if (count == 2)
		sort_2(a);
	else if (count == 3)
		sort3(a);
	else if (count == 5)
		sort5(a, b);
	else
		push_from_a_to_b(&a, &b);
	sort_b_to_a(a, b);
	ft_free(a, b);
}