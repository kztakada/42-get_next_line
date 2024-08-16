/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:33:46 by katakada          #+#    #+#             */
/*   Updated: 2024/08/17 00:46:49 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strdup(const char *str_src)
{
	char	*duplicated_new_str;
	size_t	str_len;

	str_len = ft_strlen(str_src);
	duplicated_new_str = (char *)malloc(sizeof(char) * (str_len + 1));
	if (!duplicated_new_str)
		return (NULL);
	ft_memcpy(duplicated_new_str, str_src, (str_len + 1));
	return (duplicated_new_str);
}

char	*ft_substr(char const *main_str_src, unsigned int start_index,
		size_t request_substr_len)
{
	size_t	main_str_len;
	size_t	substr_len;
	char	*substr;

	if (!main_str_src)
		return (NULL);
	main_str_len = ft_strlen(main_str_src);
	substr_len = request_substr_len;
	if (main_str_len <= start_index)
		return (ft_strdup(""));
	if (main_str_len < (start_index + request_substr_len))
		substr_len = main_str_len - start_index;
	substr = (char *)malloc(sizeof(char) * (substr_len + 1));
	if (!substr)
		return (NULL);
	ft_memcpy(substr, (main_str_src + start_index), substr_len);
	substr[substr_len] = '\0';
	return (substr);
}

char	*ft_strjoin(char const *str_src_1, char const *str_src_2)
{
	char	*join;
	size_t	len_str1;
	size_t	len_str2;

	if (!str_src_1 || !str_src_2)
		return (NULL);
	len_str1 = ft_strlen(str_src_1);
	len_str2 = ft_strlen(str_src_2);
	join = (char *)malloc(sizeof(char) * (len_str1 + len_str2 + 1));
	if (!join)
		return (NULL);
	ft_memcpy(join, str_src_1, len_str1);
	ft_memcpy(join + len_str1, str_src_2, len_str2 + 1);
	return (join);
}
