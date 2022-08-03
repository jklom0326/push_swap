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

	tab = push_in_t_stack(ac, av, &i);
	errors_handler(i, tab);
	stack_a = init_stack();
	stack_b = init_stack();
	populate(stack_a, i, tab, index_it(i, tab));
	sort(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
}