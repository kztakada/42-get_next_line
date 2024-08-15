/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:02:13 by katakada          #+#    #+#             */
/*   Updated: 2024/08/15 16:50:13 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

# define EOF -1
# define READ_ERROR -2
# define FAILURE 0
# define SUCCESS 1

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# if BUFFER_SIZE > SIZE_MAX || BUFFER_SIZE < 1
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
#  error "BUFFER_SIZE must be between 1 and 2143272832"
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
int			ft_putstr(t_string *str, int fd);
void		*ft_memcpy(void *target_dest, const void *target_src,
				size_t copy_bytes);

#endif
