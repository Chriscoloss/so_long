/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorst <chorst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 08:54:04 by chorst            #+#    #+#             */
/*   Updated: 2023/11/23 13:15:14 by chorst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		length;
	int		i;
	int		b;

	i = 0;
	b = 0;
	length = ft_strlen(s1) + ft_strlen(s2);
	result = malloc(sizeof(char) * length + 1);
	if (!result)
		return (NULL);
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[b])
	{
		result[i + b] = s2[b];
		b++;
	}
	result[i + b] = '\0';
	return (result);
}
