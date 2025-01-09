/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhiar <oukhiar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:20:26 by oukhiar           #+#    #+#             */
/*   Updated: 2025/01/09 15:19:56 by oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_input(int ac, char **av, t_stack **stack_a)
{
	if (ac < 1)
	{
		write (2, "Invalid arguments !!\n", 21);
		return (1);
	}
	if (ft_stack_fill(ac, av, stack_a) == 0)
	{
		write (2, "Error\n", 6);
		return (1);
	}
	if (ft_is_sorted(*stack_a))
	{
		ft_free(*stack_a);
		exit (0);
	}
	return (0);
}

void	ft_free(t_stack *stack_a)
{
	t_stack	*tmp;

	while (stack_a)
	{
		tmp = stack_a->next;
		free (stack_a);
		stack_a = tmp;
	}
}

void	ft_free_filtered_input(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		free (av[i]);
		i++;
	}
	free (av);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**new_av;
	int		new_ac;

	new_ac = 0;
	stack_b = NULL;
	stack_a = NULL;
	new_av = filter(ac, av);
	while (new_av[new_ac])
		new_ac++;
	if (ft_check_input(new_ac, new_av, &stack_a))
	{
		ft_free_filtered_input(new_av);
		ft_free(stack_a);
		return (1);
	}
	if (new_ac <= 15)
		ft_simple_sort(&stack_a, &stack_b);
	else
		ft_large_sort(&stack_a, &stack_b);
	ft_free(stack_a);
	return (0);
}
