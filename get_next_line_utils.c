/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:33:46 by katakada          #+#    #+#             */
/*   Updated: 2024/08/16 00:25:37 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	ft_getchar(char **buf_ptr, int fd)
{
	int	number_of_reads;
	int	c;

	number_of_reads = ft_strlen(*buf_ptr);
	if (number_of_reads == 0)
	{
		number_of_reads = read(fd, *buf_ptr, BUFFER_SIZE);
		if (number_of_reads < 0)
			return (READ_ERROR);
		(*buf_ptr)[number_of_reads] = '\0';
	}
	if (--number_of_reads >= 0)
	{
		c = (unsigned char)**buf_ptr;
		(*buf_ptr)++;
		return (c);
	}
	return (EOF);
}

size_t	ft_strlen(const char *str_src)
{
	size_t	str_len;

	if (!str_src)
		return (0);
	str_len = 0;
	while (str_src[str_len])
		str_len++;
	return (str_len);
}

int	ft_putchar(t_string *oneline, char c)
{
	char	*new_str;

	if (!oneline->str)
	{
		if (!init_oneline(oneline))
			return (FAILURE);
	}
	if (oneline->str_len + 1 >= oneline->capacity_size)
	{
		if (oneline->capacity_size > SIZE_MAX)
			return (FAILURE);
		if (oneline->capacity_size * 2 > SIZE_MAX)
			oneline->capacity_size = SIZE_MAX;
		else
			oneline->capacity_size *= 2;
		new_str = (char *)malloc(oneline->capacity_size);
		if (!new_str)
			return (FAILURE);
		ft_memcpy(new_str, oneline->str, oneline->str_len);
		free(oneline->str);
		oneline->str = new_str;
	}
	oneline->str[oneline->str_len++] = c;
	return (SUCCESS);
}

int	init_oneline(t_string *oneline)
{
	oneline->capacity_size = BUFFER_SIZE;
	oneline->str = (char *)malloc(oneline->capacity_size);
	if (!oneline->str)
		return (FAILURE);
	return (SUCCESS);
}

void	*ft_memcpy(void *target_dest, const void *target_src, size_t copy_bytes)
{
	unsigned char	*copy_dest;
	unsigned char	*copy_src;
	size_t			target_index;

	if (!target_dest || !target_src)
		return (target_dest);
	copy_dest = (unsigned char *)target_dest;
	copy_src = (unsigned char *)target_src;
	target_index = 0;
	if (target_dest != target_src)
	{
		while (copy_bytes > target_index++)
			*copy_dest++ = *copy_src++;
	}
	return (target_dest);
}
