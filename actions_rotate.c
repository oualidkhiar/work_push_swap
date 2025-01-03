/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhiar <oukhiar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 14:45:01 by oukhiar           #+#    #+#             */
/*   Updated: 2024/12/28 14:46:34 by oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_ab(t_stack **stack)
{
	t_stack *tmp;

	if (ft_is_empty(*stack) == 1)
		return ;
	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	if (tmp == *stack)
		return ;
	tmp->next = *stack;
	*stack = (*stack)->next;
	tmp->next->next = NULL;
}

void	rotate_rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate_ab(stack_a);
	rotate_ab(stack_b);
}

void	rev_rotate_ab(t_stack **stack)
{
	t_stack *last;
	t_stack *befor_last;

	if (ft_is_empty(*stack) == 1 || (*stack)->next == NULL)
		return ;
	befor_last = *stack;
	while (befor_last->next->next != NULL)
		befor_last = befor_last->next;
	last = befor_last->next;
	last->next = *stack;
	*stack = last;
	befor_last->next = NULL;
}

void	rev_rotate_rrr(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate_ab(stack_a);
	rev_rotate_ab(stack_b);
}
