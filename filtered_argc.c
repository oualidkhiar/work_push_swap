/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filtered_argc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhiar <oukhiar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 14:36:01 by oukhiar           #+#    #+#             */
/*   Updated: 2024/12/29 20:57:54 by oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int check_space(char *str)
{
    while (*str)
    {
        if (*str == ' ')
            return (1);
        str++;
    }
    return (0);
}

static int count_sub_numbers(char *str) {
	int j = 0;
	int count = 0;
	int state;

	state = 0;
	while (str[j])
	{
		if (str[j] == ' ')
			state = 0;
		else if (state == 0)
		{
			count++;
			state = 1;
		}
		j++;
	}
	return (count); 
}

static int ft_count_elements(int ac, char **av)
{
	int i;
	int elements;

	i = 0;
	elements = 0;
	while (i < ac)
	{
		if (check_space(av[i]) == 1)
			elements += count_sub_numbers(av[i]);
		else
			elements++;
		i++;
	}
	return (elements);
}

static int	add_words(char **filtered, char **words) {
	int i;

	i = 0;
	while (words[i]) {
		filtered[i] = words[i];
		i++;
	}
	return (i);
}

char **filter(int ac, char **av)
{
	int		i;
	int		index;
	char	**words;
	char	**filter_av;

	index = 0;
	i = 0;
	filter_av = malloc((ft_count_elements(ac, av) + 1) * sizeof(char *));
	if (!filter_av)
		return (NULL);
	while (++i < ac)
	{
		if (check_space(av[i]) == 1)
		{
			words = ft_split(av[i], ' ');
			if (!words)
				return (NULL);
			index += add_words(filter_av + index, words);
			free (words);
		}
		else
			filter_av[index++] = ft_strdup(av[i]);
	}
	filter_av[index] = NULL;
	return (filter_av);
}
