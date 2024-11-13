/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorst <chorst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:40:20 by chorst            #+#    #+#             */
/*   Updated: 2023/11/24 09:40:11 by chorst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*x;
	size_t	i;

	x = malloc(count * size);
	i = 0;
	if (!x)
		return (NULL);
	while (i < count * size)
		x[i++] = '\0';
	return ((void *)x);
}
