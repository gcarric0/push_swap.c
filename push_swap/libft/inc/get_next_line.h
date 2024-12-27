/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarrico <gcarrico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:55:00 by gcarrico          #+#    #+#             */
/*   Updated: 2024/09/09 15:00:48 by gcarrico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

# include <stdlib.h>
# include <unistd.h>

int		ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*get_line(char *buffer);
char	*save_remainder(char *buffer);
char	*read_and_store(int fd, char *buffer);
char	*get_next_line(int fd);

#endif
