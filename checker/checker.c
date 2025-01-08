/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhiar <oukhiar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:10:54 by oukhiar           #+#    #+#             */
/*   Updated: 2025/01/08 09:20:46 by oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../push_swap.h"


int ft_strcheck(char *line, char *str1)
{
	while (line || str1)
	{
		if (*line != *str1)
			return (0);
		line++;
		str1++;	
	}
	return (1);
}

void ft_check_actions(char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcheck(line, "sa") == 1)
		swap_ab(stack_a);
	else if (ft_strcheck(line, "sb") == 1)
		swap_ab(stack_b);
	else if (ft_strcheck(line, "ss") == 1)
		swap_ss(stack_a, stack_b);
	else if (ft_strcheck(line, "ra") == 1)
		rotate_ab(stack_a);
	else if (ft_strcheck(line, "rb") == 1)
		rotate_ab(stack_b);
	else if (ft_strcheck(line, "rr") == 1)
		rotate_rr(stack_a, stack_b);
	else if (ft_strcheck(line, "rra") == 1)
		rev_rotate_ab(stack_a);
	else if (ft_strcheck(line, "rrb") == 1)
		rev_rotate_ab(stack_b);
	else if (ft_strcheck(line, "rrr") == 1)
		rev_rotate_rrr(stack_a, stack_b);
	else if (ft_strcheck(line, "pb") == 1)
		push_to_b(stack_a, stack_b);
	else if (ft_strcheck(line, "pa") == 1)
		push_to_a(stack_a, stack_b);
}

int main (int ac, char **av)
{
    t_stack *stack_a;
	t_stack *stack_b;
	char	*line;

	stack_a = NULL;
	stack_b = NULL;
	line = NULL;
	ac -= 1;
	ft_stack_fill(ac, av, &stack_a);
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		ft_check_actions(line, &stack_a, &stack_b);
		free (line);
	}
	if (ft_is_sorted(stack_a) == 1)
		write (1, "OK\n", 3);
	write (2, "KO\n", 3);
	return (0);
}