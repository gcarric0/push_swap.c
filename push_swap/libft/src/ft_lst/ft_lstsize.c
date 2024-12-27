/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarrico <gcarrico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:41:42 by gcarrico          #+#    #+#             */
/*   Updated: 2024/12/10 14:54:42 by gcarrico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *head)
{
	size_t	count;

	count = 0;
	while (head != NULL)
	{
		head = head->next;
		count++;
	}
	return (count);
}
