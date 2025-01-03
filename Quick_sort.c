/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhiar <oukhiar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 11:42:12 by oukhiar           #+#    #+#             */
/*   Updated: 2025/01/01 20:47:38 by oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_swap_arr(int *arr, int first_index, int seconde_index)
{
	int tmp;

	tmp = arr[first_index];
	arr[first_index] = arr[seconde_index];
	arr[seconde_index] = tmp;
}

int ft_patition(int *arr, int start_index, int end_indix)
{
    int i;
	int j;
	int pivot_index;
	int pivot;

	i = start_index;
	j = start_index;
	pivot_index = end_indix;
	pivot = arr[pivot_index];
   	while (j < pivot_index)
    {
		if (arr[j] <= pivot)
		{
			ft_swap_arr(arr, i, j);
			i++;
		}
		j++;
    }
	ft_swap_arr(arr, i, pivot_index);
	return (i);
}


 void quicksort(int *arr, int start_index, int end_indix)
 {
	if (start_index < end_indix)
	{
    	int new_pivot_index = ft_patition(arr, start_index, end_indix);
		quicksort(arr, start_index, new_pivot_index - 1);
		quicksort(arr, new_pivot_index + 1, end_indix);
	}
 }

int main ()
{
	int i = 0;
	int arr[6] = {1,3,2,7,8,9};
	quicksort(arr, 0, 5);
	while (i < 6)
	{
		printf("%d ",arr[i]);
		i++;
	}
}
