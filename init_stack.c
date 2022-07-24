/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shan <shan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:57:29 by shan              #+#    #+#             */
/*   Updated: 2022/07/16 16:57:29 by shan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_node	*init_stack(void)
{
	t_node	*stack;

	stack = (t_node *)malloc(sizeof(t_node));
	stack->next = NULL;
	stack->previous = NULL;
	return (stack);
}

void	populate(t_node *stack, int size, char *argv[], int *indexator)
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
		if (!(stack))
			return ;
		stack->next->previous = stack;
		stack->value = atoi(argv[i + 1]);
		stack->index = indexator[i];
		stack = stack->next;
		i++;
	}
	stack->value = atoi(argv[i + 1]);
	stack->index = indexator[i];
	stack->next = NULL;
	free(indexator);
}

void	free_stack(t_node *stack)
{
	while (stack->next)
		stack = stack->next;
	while (stack->previous)
	{
		stack = stack->previous;
		free(stack->next);
	}
	free(stack);
}
