/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarrico <gcarrico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:46:20 by gcarrico          #+#    #+#             */
/*   Updated: 2024/12/11 12:34:41 by gcarrico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	stack_len(t_stack_node *stack)
{
	int	len;

	len = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}

t_stack_node	*find_last(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}
