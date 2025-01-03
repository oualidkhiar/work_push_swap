/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhiar <oukhiar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 14:47:52 by oukhiar           #+#    #+#             */
/*   Updated: 2024/12/29 20:46:44 by oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *stack_new(int value)
{
    t_stack *new;

    new = (t_stack *)malloc(sizeof(t_stack));
        if (!new)
			return (NULL);
	new->data = value;
	new->next = NULL;
	return (new);
}

void stack_push(t_stack **stack, int element)
{
	t_stack *new_node;

	new_node = stack_new(element);
	new_node->next = *stack;
	*stack = new_node;
}

int ft_stack_fill(int ac, char **av, t_stack **stack)
{
	int	i;
	int value;

	i = 0;
	while (i < ac)
	{
		if(ft_is_digits(av[i]) == 0)
			return (0);
		value = ft_atoi(av[i]);
		if (check_value(*stack, value) == 0)
			return (0);
		stack_push(stack, value);
		i++;
	}
	return (1);
}

int stack_pop(t_stack **stack)
{
	int value;
	t_stack *tmp;

	if (ft_is_empty(*stack) == 1)
		return (0);
	 value = (*stack)->data;
	 tmp = *stack;
	 *stack = (*stack)->next;
	 free(tmp);
	 return (value);
}

int ft_peek(t_stack *stack)
{
    int top;

    top = stack->data;
    return (top);
}
