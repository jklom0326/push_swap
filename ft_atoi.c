/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shan <shan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 22:58:50 by shan              #+#    #+#             */
/*   Updated: 2022/07/16 22:58:50 by shan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_isdigit_int(int argument)
{
	if (argument >= 48 && argument <= 57)
		return (1);
	return (0);
}

size_t	ft_strlen_int(const char *pointer)
{
	size_t	counter;

	counter = 0;
	while (pointer[counter] != '\0')
		counter++;
	return (counter);
}

static int	ft_isspace(int chr)
{
	if (chr == '\n' || chr == '\t' || chr == '\v'
		|| chr == '\r' || chr == '\f' || chr == ' ')
		return (1);
	else
		return (0);
}

static int	calc_atoi(const char *str, int len, int counter)
{
	int	result;

	result = 0;
	while (counter < len)
	{
		if (ft_isdigit_int(str[counter]))
		{
			result = (result * 10) + (str[counter] - '0');
			counter++;
		}
		else
			return (result);
	}
	return (result);
}

int	ft_atoi(const char *str)
{
	int		len;
	int		final_result;
	int		counter;

	counter = 0;
	len = ft_strlen_int(str);
	while (ft_isspace(str[counter]))
		counter++;
	if (str[counter] == '+')
		final_result = calc_atoi(str, len, counter + 1);
	else if (str[counter] == '-')
		final_result = calc_atoi(str, len, counter + 1) * -1;
	else
		final_result = calc_atoi(str, len, counter);
	return (final_result);
}
