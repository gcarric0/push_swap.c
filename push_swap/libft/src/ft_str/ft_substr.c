/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarrico <gcarrico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:50:43 by gcarrico          #+#    #+#             */
/*   Updated: 2024/12/11 16:03:09 by gcarrico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	lentotal;
	char	*substr;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	lentotal = ft_strlen(s + start);
	if (lentotal < len)
		len = lentotal;
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

/* #include <stdio.h>
#include "libft.h"
#include <stdlib.h>

int	main(void)
{
	char *str = "Hello, world!";
	unsigned int start = 7;
	size_t len = 5;

	char *substring = ft_substr(str, start, len);

	if (substring)
	{
		printf("Original string: %s\n", str);
		printf("Substring: %s\n", substring);
		free(substring);
	}
	else
	{
		printf("Substring is NULL\n");
	}

	return (0);
}*/
