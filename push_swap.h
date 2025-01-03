/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhiar <oukhiar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 11:13:21 by oukhiar           #+#    #+#             */
/*   Updated: 2024/12/30 21:33:45 by oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_stack {
   int data;
   struct s_stack *next; 
} t_stack;

void stack_push(t_stack **stack, int element); 
t_stack *stack_new(int value);
int stack_pop(t_stack **stack);
int ft_stack_fill(int ac, char **av, t_stack **stack);

void	swap_ab(t_stack **stack);
void	swap_ss(t_stack **stack_a, t_stack **stack_b);
void	push_to_a(t_stack **stack_a, t_stack **stack_b);
void	push_to_b(t_stack **stack_a, t_stack **stack_b);
void	rotate_ab(t_stack **stack);
void	rotate_rr(t_stack **stack_a, t_stack **stack_b);
void	rev_rotate_ab(t_stack **stack);
void	rev_rotate_rrr(t_stack **stack_a, t_stack **stack_b);
char **filter(int ac, char **av);

void ft_printstack(t_stack *stack_a);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
int ft_is_empty(t_stack *stack);
int	check_value(t_stack *stack, int value);
int   ft_atoi(const char *str);
int	ft_is_digits(char *str);
void ft_simple_sort(t_stack **stack_a, t_stack **stack_b);
void	ft_putstr(char *s);
int ft_is_sorted(t_stack *stack);
int ft_peek(t_stack *stack);
int ft_find_index_min(t_stack *stack);
int ft_find_index_max(t_stack *stack);
int ft_size_of_stack(t_stack *stack);
void sort_three_arguments(t_stack **stack_a);
#endif