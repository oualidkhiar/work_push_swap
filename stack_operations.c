/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhiar <oukhiar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:46:56 by oukhiar           #+#    #+#             */
/*   Updated: 2024/12/29 20:37:30 by oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_find_index_min(t_stack *stack)
{
    int min;
    int i;
	t_stack *tmp;
	int j;

	i = 0;
	j = 0;
	tmp = stack;
	if (ft_is_empty(stack))
		return (-1);
	min = ft_peek(stack);
    while (tmp->next != NULL)
    {
        if (min > tmp->data)
		{
        	min = tmp->data;
			i = j;
		}
	j++;
    tmp = tmp->next;
    }
	if (tmp->data < min)
		return (j);
    return (i);
}

int ft_find_index_max(t_stack *stack)
{
    int max;
    int i;
	t_stack *tmp;
	int j;

	i = 0;
	j = 0;
	tmp = stack;
	if (ft_is_empty(stack))
		return (-1);
	max = ft_peek(stack);
    while (tmp->next != NULL)
    {
        if (max < tmp->data)
		{
        	max = tmp->data;
			i = j;
		}
	j++;
    tmp = tmp->next;
    }
	if (tmp->data > max)
		return (j);
    return (i);
}

int ft_size_of_stack(t_stack *stack)
{
	int size;
	t_stack *tmp;

	tmp = stack;
	size = 0;
	while (tmp->next != NULL)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}
