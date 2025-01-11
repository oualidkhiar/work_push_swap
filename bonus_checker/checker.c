/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhiar <oukhiar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:10:54 by oukhiar           #+#    #+#             */
/*   Updated: 2025/01/11 13:49:18 by oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../push_swap.h"

static int	ft_strcheck(char *line, char *str1)
{
	while (*line || *str1)
	{
		if (*line != *str1)
			return (0);
		line++;
		str1++;
	}
	return (1);
}

static void	ft_execute_actions(char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcheck(line, "sa\n"))
		swap_ab(stack_a);
	else if (ft_strcheck(line, "sb\n"))
		swap_ab(stack_b);
	else if (ft_strcheck(line, "ss\n"))
		swap_ss(stack_a, stack_b);
	else if (ft_strcheck(line, "ra\n"))
		rotate_ab(stack_a);
	else if (ft_strcheck(line, "rb\n"))
		rotate_ab(stack_b);
	else if (ft_strcheck(line, "rr\n"))
		rotate_rr(stack_a, stack_b);
	else if (ft_strcheck(line, "rra\n"))
		rev_rotate_ab(stack_a);
	else if (ft_strcheck(line, "rrb\n"))
		rev_rotate_ab(stack_b);
	else if (ft_strcheck(line, "rrr\n"))
		rev_rotate_rrr(stack_a, stack_b);
	else if (ft_strcheck(line, "pb\n"))
		push_to_b(stack_a, stack_b);
	else if (ft_strcheck(line, "pa\n"))
		push_to_a(stack_a, stack_b);
}

static int	ft_check_actions(char *line)
{
	size_t	i;
	char	*hystack[2];
	char	*fin_hay;
	int		j;

	i = 0;
	j = 0;
	fin_hay = NULL;
	hystack[0] = "sasbssrarbrrpapb";
	hystack[1] = "rrarrbrrr";
	i = ft_strlen(line) - 1;
	if (!(i != 2 || i != 3))
		return (0);
	fin_hay = hystack[(i == 3)];
	while (fin_hay[j])
	{
		if (ft_strncmp(fin_hay, line, i) == 0)
			return (1);
		fin_hay += i;
		j++;
	}
	return (0);
}

static void	ft_helper(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	line = NULL;
	while (1)
	{
		line = get_next_line(0);
		if (!line || !ft_strlen(line))
		{
			free(line);
			break ;
		}
		if (ft_check_actions(line) == 0)
		{
			write (2, "Error\n", 6);
			ft_free(*stack_a);
			ft_free(*stack_b);
			free (line);
			exit (1);
		}
		ft_execute_actions(line, stack_a, stack_b);
		free (line);
	}
}

int	main(int ac, char **av)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	char		**new_av;
	int			new_ac;

	stack_a = NULL;
	stack_b = NULL;
	new_ac = 0;
	new_av = filter(ac, av);
	while (new_av[new_ac])
		new_ac++;
	if (!ft_stack_fill(new_ac, new_av, &stack_a))
	{
		write (1, "Error\n", 6);
		ft_free(stack_a);
		ft_free_filtered_input(new_av);
		exit (1);
	}
	ft_helper(&stack_a, &stack_b);
	if (ft_is_sorted(stack_a) == 1 && ft_is_empty(stack_b) == 1)
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	ft_free(stack_a);
	ft_free(stack_b);
}
