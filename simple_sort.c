/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhiar <oukhiar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 18:13:37 by oukhiar           #+#    #+#             */
/*   Updated: 2025/01/07 17:27:42 by oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_arguments(t_stack **stack)
{
	int	index_min;
	int	index_max;

	index_min = ft_find_index_min(*stack);
	index_max = ft_find_index_max(*stack);
	if (index_min == 1 && index_max == 0)
		(rotate_ab(stack), ft_putstr("ra\n"));
	else if (index_min == 1 && index_max == 2)
		(swap_ab(stack), ft_putstr("sa\n"));
	else if (index_min == 2 && index_max == 1)
		(rev_rotate_ab(stack), ft_putstr("rra\n"));
	else if (index_min == 0 && index_max == 1)
		(rev_rotate_ab(stack), swap_ab(stack), ft_putstr("rra\nsa\n"));
	else if (index_min == 2 && index_max == 0)
		(swap_ab(stack), rev_rotate_ab(stack), ft_putstr("sa\nrra\n"));
}

void	execute_ra_pb(t_stack **stack_a, t_stack **stack_b, int index)
{
	while (index > 0)
	{
		(rotate_ab(stack_a), ft_putstr("ra\n"));
		index--;
	}
	(push_to_b(stack_a, stack_b), ft_putstr("pb\n"));
}

void	execute_rra_pb(t_stack **stack_a, t_stack **stack_b, int size,
															int index_min)
{
	int	count;

	count = size - index_min;
	while (count > 0)
	{
		(rev_rotate_ab(stack_a), ft_putstr("rra\n"));
		count--;
	}
	(push_to_b(stack_a, stack_b), ft_putstr("pb\n"));
}

static void	sort_two_arguments(t_stack **stack)
{
	(swap_ab(stack), ft_putstr("sa\n"));
	exit(0);
}

void	ft_simple_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	index_min;

	if (ft_size_of_stack(*stack_a) == 2)
		sort_two_arguments(stack_a);
	while (!ft_is_empty(*stack_a))
	{
		if (ft_size_of_stack(*stack_a) == 3)
		{
			sort_three_arguments(stack_a);
			break ;
		}
		index_min = ft_find_index_min(*stack_a);
		if ((ft_size_of_stack(*stack_a) / 2) >= index_min)
			execute_ra_pb(stack_a, stack_b, index_min);
		else
			execute_rra_pb(stack_a, stack_b,
				ft_size_of_stack(*stack_a), index_min);
	}
	while (!ft_is_empty(*stack_b))
		(push_to_a(stack_a, stack_b), ft_putstr("pa\n"));
}
