/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhiar <oukhiar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:20:26 by oukhiar           #+#    #+#             */
/*   Updated: 2025/01/07 17:38:56 by oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;
    char **new_av;
    int new_ac;

    new_ac = 0;
	stack_b = NULL;
	stack_a = NULL;
    new_av = filter(ac, av);
    while (new_av[new_ac])
	    new_ac++;
	if (new_ac < 1)
	{
		write (2, "Invalid arguments !!\n", 21);
		return (1);
	}
	if (ft_stack_fill(new_ac, new_av, &stack_a) == 0)
	{
		write (2,"Error\n", 6);
		return (1);
	}
	if (ft_is_sorted(stack_a) == 1)
	{
		ft_putstr("The stack is already sorted.\n");
		return (0);
	}
	// ft_printstack(stack_a);
	ft_simple_sort(&stack_a, &stack_b);
	// ft_printstack(stack_a);
	// printf("here is stack B \n");
	// ft_printstack(stack_b);
	// printf("here is stack A after sorting \n");
	// ft_printstack(stack_a);
	// printf("\n");
	// ft_large_sort(&stack_a, &stack_b);
	// ft_printstack(stack_b);
	// ft_printstack(stack_a);
	// if (ft_is_sorted(stack_a) == 1)
	// 	printf("sussecfull");
	return (0);
}