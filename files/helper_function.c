/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorst <chorst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:15:37 by chorst            #+#    #+#             */
/*   Updated: 2024/04/16 09:41:03 by chorst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Function the frees the whole map
void	free_the_map(char **map)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
	return ;
}

int	map_line_count(int fd)
{
	int		count;
	char	*line;

	count = 0;
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (count);
}

// Function to display the map on the output
void	print_map(char **map)
{
	int	a;
	int	x;

	a = 0;
	x = 0;
	while (map[a])
	{
		x = 0;
		ft_printf("[%i]	", a);
		while (map[a][x])
		{
			if (map[a][x] == '0')
				ft_printf("%s%c%s", R, map[a][x], D);
			else if (map[a][x] == 'C')
				ft_printf("%s%c%s", G, map[a][x], D);
			else if (map[a][x] == '1')
				ft_printf("%s%c%s", B, map[a][x], D);
			else
				ft_printf("%c", map[a][x]);
			x++;
		}
		a++;
	}
	ft_printf("\n");
	return ;
}

// Function to display the player into the window
void	show_player(t_pics *pic)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (pic->map[i])
	{
		x = 0;
		while (pic->map[i][x])
		{
			if (pic->map[i][x] == 'P')
			{
				if (mlx_image_to_window(pic->mlx, pic->player_img, (x * 48), (i
							* 48)) < 0)
					break ;
			}
			x++;
		}
		i++;
	}
}
