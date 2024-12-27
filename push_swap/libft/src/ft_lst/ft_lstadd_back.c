/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarrico <gcarrico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:46:40 by gcarrico          #+#    #+#             */
/*   Updated: 2024/05/06 13:26:28 by gcarrico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **head, t_list *new)
{
	t_list	*temp;

	if (!new)
		return ;
	if (!*head)
	{
		*head = new;
		return ;
	}
	temp = ft_lstlast(*head);
	temp->next = new;
}
