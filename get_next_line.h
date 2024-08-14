/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:02:13 by katakada          #+#    #+#             */
/*   Updated: 2024/08/14 21:12:28 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define EOF -1

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# if BUFFER_SIZE > 125000 || BUFFER_SIZE < 1
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
#  error "BUFFER_SIZE must be between 1 and 125000"
# endif

typedef struct s_string
{
	char	*str;
	size_t	str_len;
	size_t	capacity_size;
}			t_string;

char		*get_next_line(int fd);
int			ft_getchar(int fd);
int			ft_putchar(t_string *str, char c);
void		*ft_memcpy(void *target_dest, const void *target_src,
				size_t copy_bytes);

#endif
