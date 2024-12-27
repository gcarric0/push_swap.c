/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarrico <gcarrico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:21:53 by gcarrico          #+#    #+#             */
/*   Updated: 2024/12/11 15:49:41 by gcarrico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	count_substr(char *str, char d)
{
	int		count;
	bool	check_sub;

	count = 0;
	while (*str)
	{
		check_sub = false;
		while (*str == d)
			++str;
		while (*str != d && *str)
		{
			if (!check_sub)
			{
				++count;
				check_sub = true;
			}
			++str;
		}
	}
	return (count);
}

static char	*get_next_sub(char *str, char d)
{
	static int	marker;
	char		*next_sub;
	int			i;
	int			len;

	len = 0;
	i = 0;
	while (str[marker] == d)
		marker++;
	while ((str[marker + len] != d) && str[marker + len])
		len++;
	next_sub = malloc((size_t)len * sizeof(char) + 1);
	if (!next_sub)
		return (NULL);
	while ((str[marker] != d) && str[marker])
		next_sub[i++] = str[marker++];
	next_sub[i] = '\0';
	return (next_sub);
}

char	**split(char *str, char d)
{
	int		total_counter;
	char	**final_array;
	int		i;

	i = 0;
	total_counter = count_substr(str, d);
	if (!total_counter)
		exit(1);
	final_array = malloc(sizeof(char *) * (total_counter + 2));
	if (!final_array)
		return (NULL);
	while (total_counter-- > 0)
	{
		if (i == d)
		{
			final_array[i] = malloc(sizeof(char));
			if (!final_array)
				return (NULL);
			final_array[i++][0] = '\0';
		}
		final_array[i++] = get_next_sub(str, d);
	}
	final_array[i] = '\0';
	return (final_array);
}

/* #include <stdio.h>

int	main(void)
{
	char	str[] = "Hello, how are you?";
	char	delimiter;
	char	**substrings;

	delimiter = ' ';
	substrings = split(str, delimiter);
	if (substrings != NULL)
	{
		for (int i = 0; substrings[i] != NULL; i++)
		{
			printf("Substring %d: %s\n", i, substrings[i]);
			free(substrings[i]);
		}
		free(substrings);
	}
	else
	{
		printf("No substrings found or error.\n");
	}
	printf("Number of substrings is: %d\n", count_substr(str, delimiter));
	return (0);
} */
