/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorst <chorst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:35:22 by chorst            #+#    #+#             */
/*   Updated: 2023/11/23 12:47:21 by chorst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*cdst;
	const char	*ccsrc;

	cdst = (char *)dst;
	ccsrc = (const char *)src;
	if ((!cdst && !ccsrc) || !n)
		return (dst);
	while (n-- > 0)
	{
		*cdst = *ccsrc;
		cdst++;
		ccsrc++;
	}
	return (dst);
}
