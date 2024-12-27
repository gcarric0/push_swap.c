/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarrico <gcarrico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:54:35 by gcarrico          #+#    #+#             */
/*   Updated: 2024/12/10 14:54:29 by gcarrico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *head, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*elements;

	if (head == NULL)
		return (NULL);
	newlst = NULL;
	while (head != NULL)
	{
		elements = ft_lstnew((*f)(head->content));
		if (elements == NULL)
			ft_lstclear(&elements, (*del));
		else
			ft_lstadd_back(&newlst, elements);
		head = head->next;
	}
	return (newlst);
}
