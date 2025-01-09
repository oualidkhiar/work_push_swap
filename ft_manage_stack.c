/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhiar <oukhiar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 14:47:52 by oukhiar           #+#    #+#             */
/*   Updated: 2025/01/09 15:17:38 by oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(int value)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->data = value;
	new->next = NULL;
	return (new);
}

int	stack_push(t_stack **stack, int element)
{
	t_stack	*new_stack;

	new_stack = stack_new(element);
	if (!new_stack)
		return (0);
	new_stack->next = *stack;
	*stack = new_stack;
	return (1);
}

int	ft_stack_fill(int ac, char **av, t_stack **stack)
{
	int	value;

	ac -= 1;
	while (ac >= 0)
	{
		if (ft_is_digits(av[ac]) == 0)
			return (0);
		value = ft_atoi(av[ac]);
		if (check_value(*stack, value) == 0)
			return (0);
		if (stack_push(stack, value) == 0)
			return (0);
		ac--;
	}
	ft_free_filtered_input(av);
	return (1);
}

int	stack_pop(t_stack **stack)
{
	int		value;
	t_stack	*tmp;

	if (ft_is_empty(*stack) == 1)
		return (0);
	value = (*stack)->data;
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
	return (value);
}

int	ft_peek(t_stack *stack)
{
	int	top;

	top = stack->data;
	return (top);
}
