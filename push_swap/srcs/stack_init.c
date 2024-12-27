/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarrico <gcarrico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:13:32 by gcarrico          #+#    #+#             */
/*   Updated: 2024/12/11 15:58:12 by gcarrico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static long	ft_strlong(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r'
		|| *str == '\f' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
		result = result * 10 + (*str++ - 48);
	return (result * sign);
}

static void	append_to_last(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	node->cheapest = 0;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	init_stack(t_stack_node **stack, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (check_syntax(argv[i]))
			free_errors(stack);
		n = ft_strlong(argv[i]);
		if (n < INT_MIN || n > INT_MAX)
			free_errors(stack);
		if (check_duplicates(*stack, (int)n))
			free_errors(stack);
		append_to_last(stack, (int)n);
		i++;
	}
}

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void	print_stack(t_stack_node *a)
{
	while (a)
	{
		printf("%d -> ", a->nbr);
		a = a->next;
	}
	printf("NULL\n");
}

int	main(int argc, char **argv)
{
	t_stack_node	*stack;

	stack = NULL;
	// If no arguments are passed, print an error message
	if (argc < 2)
	{
		printf("Please provide integers as arguments.\n");
		return (1);
	}
	init_stack(&stack, argv + 1);
	// If successful, print the stack
	print_stack(stack);
	// Clean up the stack after use
	free_errors(&stack); // Free stack memory
	return (0);
}