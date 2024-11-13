/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorst <chorst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:54:35 by chorst            #+#    #+#             */
/*   Updated: 2023/11/24 11:20:48 by chorst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*cdst;
	const char	*ccsrc;

	cdst = (char *)dst;
	ccsrc = (const char *)src;
	if ((!cdst && !ccsrc))
		return (dst);
	if (cdst < ccsrc)
		while (len--)
			*cdst++ = *ccsrc++;
	else
	{
		cdst = cdst + len - 1;
		ccsrc = ccsrc + len - 1;
		while (len-- > 0)
			*cdst-- = *ccsrc--;
	}
	return (dst);
}
