/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorst <chorst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 08:43:06 by chorst            #+#    #+#             */
/*   Updated: 2024/08/29 16:57:23 by chorst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

char	*read_better(int fd, char **str, char *newline, int n);
char	*get_next_line(int fd);
int		str_alloc_len(char *str);
void	*ft_calloc(size_t count, size_t size);
void	str_after_n(char *str);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_realloc(void *ptr, size_t new_size, int i);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
#endif
