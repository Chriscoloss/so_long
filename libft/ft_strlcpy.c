/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorst <chorst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:54:48 by chorst            #+#    #+#             */
/*   Updated: 2023/11/23 13:20:40 by chorst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	c;
	size_t	srcl;

	c = 0;
	srcl = ft_strlen(src);
	if (!dstsize)
		return (srcl);
	while (src[c] && c < dstsize - 1)
	{
		dst[c] = src[c];
		c++;
	}
	dst[c] = '\0';
	return (srcl);
}
