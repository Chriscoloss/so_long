/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pictures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorst <chorst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:01:49 by chorst            #+#    #+#             */
/*   Updated: 2024/04/16 09:40:44 by chorst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Function that print the png's to the window.
void	map_picture(t_pics *pic)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (pic->map[i])
	{
		x = 0;
		while (pic->map[i][x + 1])
			x++;
		i++;
	}
	pic->mlx = mlx_init(WIDTH * x, HEIGHT * i, "Walk of Knights", false);
	if (!pic->mlx)
		ft_error();
	get_map_pictures(pic);
	show_map_pictures(pic);
	mlx_key_hook(pic->mlx, keybinding, (void *)pic);
	mlx_loop(pic->mlx);
	delete_map_pictures(pic);
	free(pic);
	return ;
}

// Function to convert the png-path's into texture and then into img
void	*get_map_pictures(t_pics *pic)
{
	pic->tree_tex = mlx_load_png("./textures/TREE 1 - DAY.png");
	pic->path_tex = mlx_load_png("./textures/Grass.png");
	pic->collect_tex = mlx_load_png("./textures/meat.png");
	pic->player_tex = mlx_load_png("./textures/Warrior_Blue.png");
	pic->exit_tex = mlx_load_png("./textures/Tower_Blue.png");
	if (!pic->tree_tex || !pic->path_tex || !pic->collect_tex
		|| !pic->player_tex || !pic->exit_tex)
		ft_error();
	pic->tree_img = mlx_texture_to_image(pic->mlx, pic->tree_tex);
	pic->grass_img = mlx_texture_to_image(pic->mlx, pic->path_tex);
	pic->collect_img = mlx_texture_to_image(pic->mlx, pic->collect_tex);
	pic->player_img = mlx_texture_to_image(pic->mlx, pic->player_tex);
	pic->exit_img = mlx_texture_to_image(pic->mlx, pic->exit_tex);
	if (!pic->tree_img || !pic->grass_img || !pic->collect_img
		|| !pic->player_img || !pic->exit_img)
		ft_error();
	return (pic);
}

// Function to iterate trough the map to pass the param to chose_img()
void	show_map_pictures(t_pics *pic)
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
			if (pic->map[i][x])
				chose_img(pic, i, x);
			x++;
		}
		i++;
	}
	show_player(pic);
}

// Function to chose wich img needs to be printed to the window
void	chose_img(t_pics *pic, int i, int x)
{
	if (mlx_image_to_window(pic->mlx, pic->grass_img, (x * 48), (i * 48)) < 0)
		ft_error();
	if (pic->map[i][x] == '1')
		if (mlx_image_to_window(pic->mlx, pic->tree_img, (x * 48), (i
					* 48)) < 0)
			ft_error();
	if (pic->map[i][x] == 'C')
		if (mlx_image_to_window(pic->mlx, pic->collect_img, (x * 48 + 8), (i
					* 48 + 8)) < 0)
			ft_error();
	if (pic->map[i][x] == 'E')
		if (mlx_image_to_window(pic->mlx, pic->exit_img, (x * 48), (i
					* 48)) < 0)
			ft_error();
}

// Function to delete the img's
void	delete_map_pictures(t_pics *pic)
{
	mlx_delete_image(pic->mlx, pic->tree_img);
	mlx_delete_image(pic->mlx, pic->grass_img);
	mlx_delete_image(pic->mlx, pic->collect_img);
	mlx_delete_image(pic->mlx, pic->player_img);
	mlx_delete_image(pic->mlx, pic->exit_img);
	mlx_delete_texture(pic->tree_tex);
	mlx_delete_texture(pic->path_tex);
	mlx_delete_texture(pic->collect_tex);
	mlx_delete_texture(pic->player_tex);
	mlx_delete_texture(pic->exit_tex);
}
