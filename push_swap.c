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
	// printf("1");
	error_isnumber(ac, av);
	// printf("2");
	error_isbigger(ac, av);
	// printf("3");
	error_isduplic(ac, av);
	// printf("4");
}

int	main(int ac, char *av[])
{
	int		i;
	char	**tab;
	int		j;
	t_node	*stack_a;
	t_node	*stack_b;

	j = 0;
	tab = push_in_t_stack(ac, av, &i);
	// printf("%s\n",tab[j]);
	// j++;
	// printf("%s\n",tab[j]);
	// j++;
	// printf("%s\n",tab[j]);
	// j++;
	// printf("%s\n",tab[j]);
	// j++;
	// printf("%s\n",tab[j]);
	// j++;
	// printf("%s\n",tab[j]);
	// printf("%i\n", ac);
	// printf("%i\n", i);
	
	errors_handler(i, tab);
	stack_a = init_stack();
	stack_b = init_stack();
	if (ac == 2)
		populate(stack_a, i, tab, index_it(i, tab));
	populate(stack_a, i, tab, index_it(i, tab));
	sort(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
}
