/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_back_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhiar <oukhiar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:36:55 by oukhiar           #+#    #+#             */
/*   Updated: 2025/01/07 16:29:30 by oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_expected_max(t_stack *stack, int *arr, int index)
{
	while (stack)
	{
		if (stack->data == arr[index])
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	ft_get_bottom(t_stack *stack)
{
	int	bottom_value;

	if (!stack)
		return (0);
	bottom_value = 0;
	while (stack->next)
		stack = stack->next;
	bottom_value = stack->data;
	return (bottom_value);
}

void	execute_rb_pa(t_stack **stack_a, t_stack **stack_b, int index)
{
	while (index > 0)
	{
		(rotate_ab(stack_b), ft_putstr("rb\n"));
		index--;
	}
	(push_to_a(stack_a, stack_b), ft_putstr("pa\n"));
}

void	execute_rrb_pa(t_stack **stack_a, t_stack **stack_b, int size, int imax)
{
	int	count;

	count = size - imax;
	while (count > 0)
	{
		(rev_rotate_ab(stack_b), ft_putstr("rrb\n"));
		count--;
	}
	(push_to_a(stack_a, stack_b), ft_putstr("pa\n"));
}

int	ft_get_target_index(t_stack *stack_a, t_control ctls, int *sorted_arr)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		if (stack_a->data >= sorted_arr[ctls.start] && \
		stack_a->data <= sorted_arr[ctls.end])
			return (i);
		stack_a = stack_a->next;
		i++;
	}
	return (-1);
}
