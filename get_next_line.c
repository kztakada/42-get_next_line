/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:33:25 by katakada          #+#    #+#             */
/*   Updated: 2024/08/15 17:08:30 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	t_string	oneline;

	if (BUFFER_SIZE < 1)
		return (NULL);
	if (fd < 0)
		return (NULL);
	oneline.str = NULL;
	oneline.str_len = 0;
	oneline.capacity_size = 0;
	if (!ft_putstr(&oneline, fd))
		return (free(oneline.str), NULL);
	if (oneline.str_len == 0)
		return (NULL);
	if (oneline.str_len > 0)
	{
		if (!ft_putchar(&oneline, '\0'))
			return (NULL);
	}
	return (oneline.str);
}
