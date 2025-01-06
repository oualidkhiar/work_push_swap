/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhiar <oukhiar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:05:44 by oukhiar           #+#    #+#             */
/*   Updated: 2025/01/06 19:08:06 by oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_printstack(t_stack *stack_a)
{
	if (stack_a == NULL)
		return ;
	printf("%d ", stack_a->data);
	ft_printstack(stack_a->next);
}

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	while (*s)
	{
		write(1 , s, 1);
		s++;
	}
}


size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*base_s2;
	size_t	s_len;
	char	*s2;

	s_len = ft_strlen(s1);
	s2 = (char *)malloc(s_len * sizeof(char) + 1);
	if (!s2)
		return (NULL);
	base_s2 = s2;
	while (*s1)
		*s2++ = *s1++;
	*s2 = '\0';
	return (base_s2);
}


char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	char	*base_sub;

	if (!s)
		return (0);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start > (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	sub_str = (char *)malloc(sizeof(char) * len + 1);
	if (sub_str == NULL)
		return (NULL);
	base_sub = sub_str;
	s += start;
	while (len > 0)
	{
		*sub_str++ = *s++;
		len--;
	}
	*sub_str = '\0';
	return (base_sub);
}
