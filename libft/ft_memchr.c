/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorst <chorst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:56:46 by chorst            #+#    #+#             */
/*   Updated: 2023/11/24 11:06:14 by chorst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*h;
	unsigned char	x;

	x = (unsigned char)c;
	h = (unsigned char *)s;
	while (n-- > 0)
	{
		if (*h == x)
			return (h);
		h++;
	}
	return (0);
}
