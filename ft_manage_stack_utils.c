/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_stack_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhiar <oukhiar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 14:51:09 by oukhiar           #+#    #+#             */
/*   Updated: 2025/01/07 16:20:02 by oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_empty(t_stack *stack)
{
	if (stack == NULL)
		return (1);
	return (0);
}

int	check_value(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->data == value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int		res;
	int		sign;

	res = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		res = res * 10 + *str - 48;
		str++;
	}
	return (res * sign);
}

int	ft_is_digits(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!(str[i] >= 48 && str[i] <= 57))
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_sorted(t_stack *stack)
{
	if (ft_is_empty(stack) == 1)
		return (1);
	while (stack->next != NULL)
	{
		if (stack->data < stack->next->data)
		{
			stack = stack->next;
			continue ;
		}
		return (0);
	}
	return (1);
}
