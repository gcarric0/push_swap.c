/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarrico <gcarrico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:49:24 by gcarrico          #+#    #+#             */
/*   Updated: 2024/12/11 12:36:10 by gcarrico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	check_syntax(char *stack_n)
{
	if (!(*stack_n == '+' || *stack_n == '-' || (*stack_n >= '0'
				&& *stack_n <= '9')))
		return (1);
	if ((*stack_n == '+' || *stack_n == '-') && !(stack_n[1] >= '0'
			&& stack_n[1] <= '9'))
		return (1);
	while (*++stack_n)
	{
		if (!(*stack_n >= '0' && *stack_n <= '9'))
			return (1);
	}
	return (0);
}

int	check_duplicates(t_stack_node *stack, int n)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->nbr == n)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->nbr = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	free_errors(t_stack_node **stack)
{
	free_stack(stack);
	ft_printf("Error\n");
	exit(1);
}
