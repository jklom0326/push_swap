/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shan <shan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 02:53:27 by shan              #+#    #+#             */
/*   Updated: 2022/07/18 02:53:27 by shan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap_bonus.h"

void	ordered_checker(t_node *stack_a, t_node *stack_b)
{
	stack_a = stack_a->next;
	while (stack_a->next)
	{
		if (stack_a->value > stack_a->next->value)
		{
			printf("KO\n");
			return ;
		}
		stack_a = stack_a->next;
	}
	if (stack_length(stack_b) == 0)
		printf("OK\n");
	else
		printf("KO\n");
}

void	populate_checker(t_node *stack, int size, char *av[])
{
	int	i;

	i = 0;
	stack->next = (t_node *)malloc(sizeof(t_node));
	stack->next->previous = stack;
	stack->previous = NULL;
	stack = stack->next;
	while (i < size - 2)
	{
		stack->next = (t_node *)malloc(sizeof(t_node));
		stack->next->previous = stack;
		stack->value = atoi(av[i + 1]);
		stack = stack->next;
		i++;
	}
	stack->value = atoi(av[i + 1]);
	stack->next = NULL;
}

int	main(int ac, char *av[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**tab;
	// char	*line;
	int		i;

	tab = push_in_t_stack(ac, av, &i);
	errors_handler(i, tab);
	stack_a = init_stack();
	stack_b = init_stack();
	populate_checker(stack_a, i, tab);
	gnl_check_command(stack_a, stack_b)
	// while (j)
	// {
	// 	i = get_next_line(0, &line);
	// 	if (!i)
	// 	{
	// 		free(line);
	// 		break ;
	// 	}
	// 	exec_command(line, stack_a, stack_b);
	// 	free(line);
	// }
	ordered_checker(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
}
