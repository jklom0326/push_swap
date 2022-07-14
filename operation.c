/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shan <shan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 01:12:29 by shan              #+#    #+#             */
/*   Updated: 2022/07/15 01:12:29 by shan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"push_swap.h"

int	*push(t_p1 *stack, int val)
{
	if (stack->top == (int)(stack->capacity - 1))
		return (0);
	stack->arry[++stack->top] = val;
	return (&stack->arry[stack->top]);
}

int	*pop(t_p1 *stack)
{
	if (stack->top == -1)
		return (0);
	return (&stack->arry[stack->top--]);
}
