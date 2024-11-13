/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorst <chorst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 08:56:51 by chorst            #+#    #+#             */
/*   Updated: 2023/11/23 12:53:19 by chorst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	length(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		return (i + 10);
	}
	if (!n)
	{
		return (i + 1);
	}
	if (n < 0)
	{
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nbr)
{
	char	*str;
	int		i;
	long	n;

	n = nbr;
	if (!n)
		return (ft_strdup("0"));
	i = length(n);
	str = ft_calloc(sizeof(char), (i + 1) + (n < 0));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
		i++;
	}
	while (n > 0)
	{
		str[--i] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}
