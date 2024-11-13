/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_positions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorst <chorst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:19:52 by chorst            #+#    #+#             */
/*   Updated: 2024/04/16 09:40:02 by chorst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Function to read the positions out of the map
t_pos	get_map_positions(char **map)
{
	t_pos	pos;

	pos.start_col = 0;
	pos.end_col = 0;
	pos.start_row = 0;
	pos.end_row = 0;
	while (map[pos.end_col + 1])
		pos.end_col++;
	while (map[pos.end_col][pos.end_row + 2])
		pos.end_row++;
	pos.character.p = get_p_position(map);
	pos.count.p = count_char(map, 'P');
	pos.count.e = count_char(map, 'E');
	pos.count.c = count_char(map, 'C');
	return (pos);
}

// Function to get the location of P
t_grid	get_p_position(char **map)
{
	t_grid	pos;
	int		row;
	int		col;

	row = 0;
	col = 0;
	pos.row = 0;
	pos.col = 0;
	while (map[col])
	{
		row = 0;
		while (map[col][row])
		{
			if (map[col][row] == 'P')
			{
				pos.col = col;
				pos.row = row;
				return (pos);
			}
			row++;
		}
		col++;
	}
	return (pos);
}

// Function to count the ammound of specific char c(P, E or C) inside the Map
int	count_char(char **map, char c)
{
	int	count;
	int	row;
	int	col;

	count = 0;
	col = 0;
	while (map[col])
	{
		row = 0;
		while (map[col][row])
		{
			if (map[col][row] == c)
				count++;
			row++;
		}
		col++;
	}
	return (count);
}
