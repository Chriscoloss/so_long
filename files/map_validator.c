/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorst <chorst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:29:04 by chorst            #+#    #+#             */
/*   Updated: 2024/04/16 09:40:47 by chorst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Main validation function to make the final map-vali-check.
int	map_validator(char **map, t_pos pos)
{
	if (!map_form_check(map, pos))
		if (!map_path_check(map, pos))
			return (0);
	return (-1);
}
