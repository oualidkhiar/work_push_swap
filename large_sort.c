/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhiar <oukhiar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:44:31 by oukhiar           #+#    #+#             */
/*   Updated: 2025/01/05 21:11:08 by oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *ft_create_fill_arr(t_stack *stack_a, int size)
{
    int *arr;
	int i = 0;

    arr = (int *)malloc(size * sizeof(int));
		if (!arr)
			return (NULL);
    while (i < size)
    {
        arr[i] = stack_a->data;
        stack_a = stack_a->next;
        i++;
    }
	quicksort(arr, 0, size - 1);
    return (arr);
}

int ft_get_target_index(t_stack *stack_a, int start, int end,int *sorted_arr)
{
	int i;

	i = 0;
	while (stack_a)
	{
		if (stack_a->data >= sorted_arr[start] && stack_a->data <= sorted_arr[end])
			return (i);
		stack_a = stack_a->next;
		i++;
	}
	return (-1);
}

void ft_push_chunks(t_stack **stack_a, t_stack **stack_b, int mid, int start, int end, int *sorted_arr)
{
	int target_index;
	int size;

	target_index = ft_get_target_index(*stack_a, start, end, sorted_arr);
	size = ft_size_of_stack(*stack_a);
	while (target_index >= 0)
	{
		if ((size / 2) >= target_index)
			execute_ra_pb(stack_a, stack_b, target_index);
		else
			execute_rra_pb(stack_a, stack_b, size, target_index);
		size--;
		if (ft_size_of_stack(*stack_b) >= 2)
		{
			if (ft_peek(*stack_b) <= sorted_arr[mid])
				(rotate_ab(stack_b), ft_putstr("rb\n"));
		}
		target_index = ft_get_target_index(*stack_a, start, end, sorted_arr);
	}
}

void ft_update_chunks_limit(int *start, int *end,int offset, int size)
{
	if (*start - offset < 0)
		*start = 0;
	else
		*start -= offset;
	if (*end + offset > size)
		*end = size - 1;
	else
		*end += offset;
}

void ft_large_sort(t_stack **stack_a, t_stack **stack_b)
{
	int size = ft_size_of_stack(*stack_a);
	int *sorted_arr = ft_create_fill_arr(*stack_a, size);
	int arr_size = size;
	if (!sorted_arr)
	{
		write (2 ,"unable to allocate memory.!", 27);
		exit (1);
	}
	int mid = size / 2;
	int offset = size / 18;
	int start = mid - offset;
	int end = mid + offset;
	while (!ft_is_empty(*stack_a))
	{
		ft_push_chunks(stack_a, stack_b, mid, start, end, sorted_arr);
		ft_update_chunks_limit(&start, &end, offset, arr_size);
	}
	ft_push_back(stack_a, stack_b, sorted_arr);
	free (sorted_arr);
}
