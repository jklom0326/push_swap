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
#include <stdio.h>

void	errors_handler(int ac, char *av[])
{
	error_isonearg(ac);
	error_isnumber(ac, av);
	error_isbigger(ac, av);
	error_isduplic(ac, av);
}

int	main(int ac, char *av[])
{
	int		i;
	char	**tab;
	t_node	*stack_a;
	t_node	*stack_b;

	errors_handler(ac, av);
	tab = push_in_t_stack(ac, av, &i);
	i -= 1;
	stack_a = init_stack();
	stack_b = init_stack();
	if (ac == 2)
		populate(stack_a, i, tab, index_it(i, tab));
	populate(stack_a, ac, av, index_it(ac, av));
	sort(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
}