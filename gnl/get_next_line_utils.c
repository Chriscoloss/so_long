/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorst <chorst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 08:43:03 by chorst            #+#    #+#             */
/*   Updated: 2024/01/26 13:11:58 by chorst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	str_alloc_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	char			*x;
	static size_t	i;

	i = 0;
	x = malloc(count * size);
	if (x == NULL)
		return (NULL);
	while (i < count * size)
		x[i++] = '\0';
	return ((void *)x);
}

void	str_after_n(char *str)
{
	int	i;
	int	b;

	i = 0;
	b = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		i++;
	while (str[i])
		str[b++] = str[i++];
	str[b] = '\0';
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*temp_dst;
	const char	*temp_src;

	temp_dst = (char *)dst;
	temp_src = (const char *)src;
	if ((!temp_dst || !temp_src))
		return (dst);
	if (temp_dst < temp_src)
		while (len--)
			*temp_dst++ = *temp_src++;
	else
	{
		temp_dst = temp_dst + len - 1;
		temp_src = temp_src + len - 1;
		while (len-- > 0)
			*temp_dst-- = *temp_src--;
	}
	return (dst);
}

void	*ft_realloc(void *ptr, size_t new_size, int n)
{
	void	*new_bigger_ptr;

	if (ptr == NULL)
		ptr = ft_calloc(sizeof(char), new_size);
	new_bigger_ptr = ft_calloc(sizeof(char), new_size);
	if (new_bigger_ptr == NULL || ptr == NULL)
		return (free(new_bigger_ptr), free(ptr), NULL);
	ft_memmove(new_bigger_ptr, ptr, n);
	free(ptr);
	return (new_bigger_ptr);
}
