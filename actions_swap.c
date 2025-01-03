/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhiar <oukhiar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 14:42:55 by oukhiar           #+#    #+#             */
/*   Updated: 2024/12/28 14:44:12 by oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_ab(t_stack **stack)
{
	t_stack *tmp;

	if (ft_is_empty(*stack) == 1)
		return ;
	tmp = *stack;
	if ((*stack)->next == NULL)
		return ;
	*stack = (*stack)->next; 
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

void	swap_ss(t_stack **stack_a, t_stack **stack_b)
{
	swap_ab(stack_a);
	swap_ab(stack_b);
}

void	push_to_b(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_is_empty(*stack_a) == 1)
		return ;
	stack_push(stack_b, stack_pop(stack_a));
}

void	push_to_a(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_is_empty(*stack_b) == 1)
		return ;
	stack_push(stack_a, stack_pop(stack_b));
}