/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorst <chorst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:29:47 by chorst            #+#    #+#             */
/*   Updated: 2024/04/02 11:29:36 by chorst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Function to check if the map has a valid path to 'E' and every 'C'
int	map_path_check(char **map, t_pos pos)
{
	char	**map_copy;
	int		result_of_c;
	int		*amount;

	result_of_c = 0;
	map_copy = (copy_map(map));
	if (map_copy == NULL)
		return (0);
	if (path_p_to_e_check(map_copy, pos.character.p))
		return (ft_printf("%sERROR! No path to reach exit('E')!\n%s", R, D));
	free_the_map(map_copy);
	amount = malloc(sizeof(int) * 1);
	if (amount == NULL)
		return (0);
	*amount = pos.count.c;
	map_copy = (copy_map(map));
	if (map_copy == NULL)
		return (0);
	result_of_c = path_p_to_c_check(map_copy, pos.character.p, amount);
	free(amount);
	if ((result_of_c != 0))
		return (ft_printf("%s\nERROR! No path to all 'C'!\n%s", R, D));
	free_the_map(map_copy);
	return (0);
}

// Function to check if P can reach E
int	path_p_to_e_check(char **map, t_grid P)
{
	int	result;

	result = -1;
	if (map[P.col][P.row] == 'E')
		return (0);
	if (map[P.col][P.row] == '1' || map[P.col][P.row] == 'V')
		return (-1);
	else
		map[P.col][P.row] = 'V';
	if (result == -1)
		result = path_p_to_e_check(map, (t_grid){P.row - 1, P.col});
	if (result == -1)
		result = path_p_to_e_check(map, (t_grid){P.row + 1, P.col});
	if (result == -1)
		result = path_p_to_e_check(map, (t_grid){P.row, P.col - 1});
	if (result == -1)
		result = path_p_to_e_check(map, (t_grid){P.row, P.col + 1});
	return (result);
}

// Function to check if P can reach every C
int	path_p_to_c_check(char **map, t_grid P, int *count)
{
	if (*count == 0)
		return (0);
	if (map[P.col][P.row] == 'C')
		(*count)--;
	if (map[P.col][P.row] == '1' || map[P.col][P.row] == 'V')
		return (-1);
	else
		map[P.col][P.row] = 'V';
	path_p_to_c_check(map, (t_grid){P.row - 1, P.col}, count);
	path_p_to_c_check(map, (t_grid){P.row + 1, P.col}, count);
	path_p_to_c_check(map, (t_grid){P.row, P.col - 1}, count);
	path_p_to_c_check(map, (t_grid){P.row, P.col + 1}, count);
	return (*count);
}

// Function to count the line of the map
int	map_lines(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

// Function to make a copy of the map
char	**copy_map(char **map)
{
	char	**map_copy;
	int		i;

	i = 0;
	map_copy = malloc(sizeof(char *) * (map_lines(map) + 1));
	if (map_copy == NULL)
		return (NULL);
	while (map[i])
	{
		map_copy[i] = ft_strdup(map[i]);
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}
