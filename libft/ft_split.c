/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorst <chorst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 08:56:12 by chorst            #+#    #+#             */
/*   Updated: 2024/03/18 11:22:48 by chorst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_it(char *s)
{
	while (*s)
	{
		free(s);
		s++;
	}
	free(s);
}

static int	word_counter(char const *s, char c)
{
	int	counter;

	counter = 0;
	while (*s)
	{
		if (s[0] != c)
		{
			counter++;
			while (*s && *s != c)
				s++;
			if (!*s)
				return (counter);
		}
		s++;
	}
	return (counter);
}

static char	*str_selector(const char *str, int word_nbr, char c)
{
	int				counter;
	int				i;
	size_t			length;
	unsigned int	start;

	counter = 0;
	i = 0;
	start = 0;
	length = 0;
	while (str[i])
	{
		if ((str[i] != c && str[i]) && word_nbr == counter)
		{
			start = i;
			while ((str[i] != c && str[i++]) && word_nbr == counter)
				length++;
			return (ft_substr(str, start, length));
		}
		if (str[i] != c && str[i + 1] == c)
			counter++;
		i++;
	}
	return (ft_substr(str, start, length));
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;

	i = 0;
	str = (char **)ft_calloc(sizeof(char *), (word_counter(s, c) + 1));
	if (!str)
		return (NULL);
	while (i < word_counter(s, c))
	{
		str[i] = str_selector(s, i, c);
		if (!str[i])
			free_it(str[i]);
		i++;
	}
	str[i] = NULL;
	return (str);
}
