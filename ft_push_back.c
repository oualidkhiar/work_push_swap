/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhiar <oukhiar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:24:30 by oukhiar           #+#    #+#             */
/*   Updated: 2025/01/07 17:08:13 by oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push_rotate(t_stack **stack_a, t_stack **stack_b)
{
	int	counter;

	counter = 0;
	(push_to_a(stack_a, stack_b), rotate_ab(stack_a), ft_putstr("pa\nra\n"));
	counter++;
	return (counter);
}

static int	reduce(t_stack **stack_a, t_stack **stack_b,
							int index_max_arr, int *arr)
{
	int	index_max;
	int	size;
	int	counter;

	counter = 0;
	index_max = ft_find_index_max(*stack_b);
	if (ft_expected_max(*stack_b, arr, index_max_arr) == 1)
	{
		if ((ft_size_of_stack(*stack_b) / 2) >= index_max)
			execute_rb_pa(stack_a, stack_b, index_max);
		else
		{
			size = ft_size_of_stack(*stack_b);
			execute_rrb_pa(stack_a, stack_b, size, index_max);
		}
	}
	else
	{
		(rev_rotate_ab(stack_a), ft_putstr("rra\n"));
		counter--;
	}
	return (counter);
}

void	ft_push_back(t_stack **stack_a, t_stack **stack_b, int *arr)
{
	int	counter;
	int	index_max_arr;

	counter = 0;
	index_max_arr = ft_size_of_stack(*stack_b) - 1;
	while (!ft_is_empty(*stack_b))
	{
		if (counter == 0 && ft_find_index_max(*stack_b) != 0)
		{
			counter += push_rotate(stack_a, stack_b);
			continue ;
		}
		if (ft_peek(*stack_b) > ft_get_bottom(*stack_a) && \
						ft_find_index_max(*stack_b) != 0)
		{
			counter += push_rotate(stack_a, stack_b);
			continue ;
		}
		counter += reduce(stack_a, stack_b, index_max_arr, arr);
		index_max_arr--;
	}
	while (counter-- > 0)
		(rev_rotate_ab(stack_a), ft_putstr("rra\n"));
}
