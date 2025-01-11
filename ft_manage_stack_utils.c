/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_stack_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhiar <oukhiar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 14:51:09 by oukhiar           #+#    #+#             */
/*   Updated: 2025/01/10 16:37:37 by oukhiar          ###   ########.fr       */
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

static int	ft_reduce_atoi(const char **str, int sign)
{
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	return (sign);
}

int	ft_atoi(const char *str)
{
	int				res;
	int				sign;
	long long		tmp;

	res = 0;
	tmp = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	sign = ft_reduce_atoi(&str, sign);
	while (*str && *str >= 48 && *str <= 57)
	{
		tmp = tmp * 10 + *str - 48;
		if ((tmp >= INT_MIN && sign > 0) || (tmp > INT_MIN && sign < 0))
		{
			write (2, "Error\n", 6);
			exit (1);
		}
		res = tmp;
		str++;
	}
	return (res * sign);
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
