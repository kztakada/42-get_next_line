/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:33:46 by katakada          #+#    #+#             */
/*   Updated: 2024/08/15 16:46:31 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_getchar(int fd)
{
	static char	*buf;
	static char	*buf_ptr;
	static int	number_of_reads = 0;

	if (!buf)
	{
		buf = (char *)malloc(BUFFER_SIZE * sizeof(char));
		if (!buf)
			return (READ_ERROR);
	}
	if (number_of_reads == 0)
	{
		number_of_reads = read(fd, buf, BUFFER_SIZE);
		if (number_of_reads < 0)
			return (READ_ERROR);
		buf_ptr = buf;
	}
	if (--number_of_reads >= 0)
		return ((unsigned char)*buf_ptr++);
	return (EOF);
}

int	ft_putchar(t_string *oneline, char c)
{
	char	*new_str;

	if (!oneline->str)
	{
		oneline->capacity_size = BUFFER_SIZE;
		oneline->str = (char *)malloc(oneline->capacity_size);
		if (!oneline->str)
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

int	ft_putstr(t_string *oneline, int fd)
{
	char	c;

	while (1)
	{
		c = ft_getchar(fd);
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
