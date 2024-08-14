/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:33:46 by katakada          #+#    #+#             */
/*   Updated: 2024/08/14 21:39:55 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_getchar(int fd)
{
	static char	buf[BUFFER_SIZE];
	static char	*bufp;
	static int	n = 0;

	if (n == 0)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n < 0)
			return (EOF);
		bufp = buf;
	}
	if (--n >= 0)
		return ((unsigned char)*bufp++);
	return (EOF);
}

int	ft_putchar(t_string *str, char c)
{
	char	*new_str;

	if (!str->str)
	{
		str->capacity_size = BUFFER_SIZE;
		str->str = (char *)malloc(str->capacity_size);
		if (!str->str)
			return (0);
	}
	if (str->str_len + 1 >= str->capacity_size)
	{
		// TODO: log2(N)の場合の巨大値のエラーハンドリングする
		str->capacity_size *= 2;
		new_str = (char *)malloc(str->capacity_size);
		if (!new_str)
			return (0);
		ft_memcpy(new_str, str->str, str->str_len);
		free(str->str);
		str->str = new_str;
	}
	str->str[str->str_len++] = c;
	return (1);
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
