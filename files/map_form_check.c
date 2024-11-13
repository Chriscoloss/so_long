/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_form_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorst <chorst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:54:25 by chorst            #+#    #+#             */
/*   Updated: 2024/04/16 09:40:28 by chorst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Function to check if one of the form_checks fail
int	map_form_check(char **map, t_pos pos)
{
	if (map_char_check(map) || map_size_and_pec_check(pos)
		|| map_rectangle_check(map, pos) || map_surrounded_by_1_check(map, pos))
		return (-1);
	return (0);
}

// Function to check if there is nonsense inside the map
int	map_char_check(char **map)
{
	int	col;
	int	row;

	col = 0;
	row = 0;
	while (map[col])
	{
		row = 0;
		while (map[col][row])
		{
			if (map[col][row] != 'P' && map[col][row] != 'E'
				&& map[col][row] != 'C' && map[col][row] != '1'
				&& map[col][row] != '0' && map[col][row] != '\n')
				return (ft_printf("%sError!\nNonsense in the map\n\n%s", R, D));
			row++;
		}
		col++;
	}
	return (0);
}

// Function to check:
// 1. If the map's size is valid
// 2. If the map got the right ammount of P, E and C
int	map_size_and_pec_check(t_pos pos)
{
	if (pos.end_col < 2 || pos.end_row < 2 || (pos.end_col == 3
			&& pos.end_row < 3) || (pos.end_row == 3 && pos.end_col < 3)
		|| (pos.end_col == 2 && pos.end_row < 4) || (pos.end_row == 2
			&& pos.end_col < 4))
		return (ft_printf("%sError!\nMap is too small\n\n%s", R, D));
	if (pos.count.p != 1 || pos.count.e != 1 || pos.count.c < 1)
		return (ft_printf("%sError!\nInvalid ammount (P, E or C)\n\n%s", R, D));
	return (0);
}

// Function to check if the map is a rectangle
int	map_rectangle_check(char **map, t_pos pos)
{
	pos.start_col = 1;
	while (map[pos.start_col + 1])
	{
		pos.start_row = 0;
		while (map[pos.start_col][pos.start_row + 2])
			pos.start_row++;
		if (pos.start_row != pos.end_row)
			return (ft_printf("%sError!\nMap is not a rectangle\n\n%s", R, D));
		pos.start_col++;
	}
	return (0);
}

// Function to check if the map is surrounded by '1' (Walls)
int	map_surrounded_by_1_check(char **map, t_pos pos)
{
	while (map[0][pos.start_row + 1] == '1' && map[pos.end_col][pos.start_row
		+ 1] == '1')
		pos.start_row++;
	while (map[pos.start_col][0] == '1'
		&& map[pos.start_col][pos.end_row] == '1'
		&& pos.start_col < pos.end_col)
		pos.start_col++;
	if (pos.start_col != pos.end_col || pos.start_row != pos.end_row)
		return (ft_printf("%sError!\nMap not surrounded by Walls\n\n%s", R, D));
	return (0);
}
