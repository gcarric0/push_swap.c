/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarrico <gcarrico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:52:28 by gcarrico          #+#    #+#             */
/*   Updated: 2024/12/10 14:54:20 by gcarrico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*nextlst;

	current = *lst;
	while (current != NULL)
	{
		nextlst = current->next;
		ft_lstdelone(current, del);
		current = nextlst;
	}
	*lst = NULL;
}
