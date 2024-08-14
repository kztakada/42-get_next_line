/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:33:25 by katakada          #+#    #+#             */
/*   Updated: 2024/08/14 21:23:33 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	t_string	ret;
	char		c;

	if (BUFFER_SIZE < 1)
		return (NULL);
	ret.str = NULL;
	ret.str_len = 0;
	ret.capacity_size = 0;
	while (1)
	{
		c = ft_getchar(fd);
		if (c == EOF)
			break ;
		if (!ft_putchar(&ret, c))
			return (NULL);
		if (c == '\n')
			break ;
	}
	if (ret.str_len == 0)
		return (NULL);
	if (ret.str_len > 0)
	{
		if (!ft_putchar(&ret, '\0'))
			return (NULL);
	}
	return (ret.str);
}
