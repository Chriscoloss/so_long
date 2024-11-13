/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorst <chorst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:53:53 by chorst            #+#    #+#             */
/*   Updated: 2023/11/24 11:23:23 by chorst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	f;
	unsigned char	*g;

	f = (unsigned char ) c;
	g = (unsigned char *) b;
	while (len-- > 0)
	{
		*g = f;
		g++;
	}
	return (b);
}
