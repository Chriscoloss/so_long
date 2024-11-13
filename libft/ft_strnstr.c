/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorst <chorst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:57:10 by chorst            #+#    #+#             */
/*   Updated: 2023/11/24 13:10:46 by chorst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	c;

	i = 0;
	if (!needle[0])
		return ((char *)(haystack));
	while (haystack[i] && len > i)
	{
		c = 0;
		if (haystack[i] == needle[c])
		{
			while (needle[c] && haystack[i + c] == needle[c] && len > i + c)
				c++;
			if (!needle[c])
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (0);
}
