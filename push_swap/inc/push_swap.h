/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarrico <gcarrico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:48:58 by gcarrico          #+#    #+#             */
/*   Updated: 2024/12/11 12:35:48 by gcarrico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/inc/ft_printf.h"
# include "../libft/inc/libft.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					cost;
	bool				cheapest;
	bool				average;

	struct s_stack_node	*next;
	struct s_stack_node	*prev;
	struct s_stack_node	*target;
}						t_stack_node;

t_stack_node			*find_last(t_stack_node *stack);
int						stack_len(t_stack_node *stack);
int						check_duplicates(t_stack_node *stack, int n);
int						check_syntax(char *stack_n);
void					free_stack(t_stack_node **stack);
void					free_errors(t_stack_node **stack);

#endif
