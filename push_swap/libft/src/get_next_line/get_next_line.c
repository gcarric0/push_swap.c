/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarrico <gcarrico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:55:10 by gcarrico          #+#    #+#             */
/*   Updated: 2024/12/11 16:02:17 by gcarrico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_and_store(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_line(buffer);
	buffer = save_remainder(buffer);
	return (line);
}
