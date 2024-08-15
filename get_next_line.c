/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:33:25 by katakada          #+#    #+#             */
/*   Updated: 2024/08/16 00:27:28 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*buf_ptr = NULL;
	t_string	oneline;

	if (BUFFER_SIZE < 1)
		return (NULL);
	if (fd < 0)
		return (NULL);
	if (!buf_ptr)
	{
		if (!init_buf(&buf_ptr))
			return (NULL);
	}
	oneline.str = NULL;
	oneline.str_len = 0;
	oneline.capacity_size = 0;
	if (!ft_putstr(&buf_ptr, &oneline, fd))
		return (free(buf_ptr), free(oneline.str), NULL);
	if (oneline.str_len == 0)
		return (NULL);
	if (oneline.str_len > 0)
	{
		if (!ft_putchar(&oneline, '\0'))
			return (free(buf_ptr), free(oneline.str), NULL);
	}
	return (oneline.str);
}

char	*init_buf(char **buf)
{
	*buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!*buf)
		return (NULL);
	(*buf)[0] = '\0';
	return (*buf);
}

int	ft_putstr(char **buf_ptr, t_string *oneline, int fd)
{
	char	c;

	while (1)
	{
		c = ft_getchar(buf_ptr, fd);
		if (c == READ_ERROR)
			return (FAILURE);
		if (c == EOF)
			break ;
		if (!ft_putchar(oneline, c))
			return (FAILURE);
		if (c == '\n')
			break ;
	}
	return (SUCCESS);
}
