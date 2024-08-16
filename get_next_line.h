/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:02:13 by katakada          #+#    #+#             */
/*   Updated: 2024/08/17 00:45:55 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# if BUFFER_SIZE > SIZE_MAX || BUFFER_SIZE < 1
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
#  error "BUFFER_SIZE must be between 1 and SIZE_MAX"
# endif

char	*get_next_line(int fd);
int		init_parm(int *num_of_reads, int *is_end, char **oneline,
			char **read_buf);
int		fd_read(int fd, char **remain, char **buf);
char	*get_next_str(char **buf, char **remain, int *flag);
int		put_oneline(char **result, char *str);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
