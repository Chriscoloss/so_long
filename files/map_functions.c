/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorst <chorst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:47:11 by chorst            #+#    #+#             */
/*   Updated: 2024/04/16 09:40:36 by chorst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//
void	keybinding(mlx_key_data_t keydata, void *param);
void	check_for_img(t_pics *pic, int dx, int dy);
bool	check_for_tree(t_pics *pic, int x, int y);
void	check_for_collect(t_pics *pic);
void	check_for_exit(t_pics *pic);

//
void	keybinding(mlx_key_data_t keydata, void *param)
{
	t_pics	*pic;

	pic = (t_pics *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(pic->mlx);
	else
	{
		if ((keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
			&& keydata.action == MLX_PRESS)
			check_for_img(pic, 0, -48);
		else if ((keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
			&& keydata.action == MLX_PRESS)
			check_for_img(pic, -48, 0);
		else if ((keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
			&& keydata.action == MLX_PRESS)
			check_for_img(pic, 48, 0);
		else if ((keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
			&& keydata.action == MLX_PRESS)
			check_for_img(pic, 0, 48);
	}
}

//
void	check_for_img(t_pics *pic, int dx, int dy)
{
	static int	count = 0;

	if (count == 0)
		count = 1;
	if (check_for_tree(pic, pic->player_img->instances[0].x + dx,
			pic->player_img->instances[0].y + dy))
	{
		pic->player_img->instances[0].x += dx;
		pic->player_img->instances[0].y += dy;
		ft_printf("Moves needed: %i\n", count++);
		check_for_collect(pic);
		check_for_exit(pic);
	}
}

//
void	check_for_exit(t_pics *pic)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (i < pic->collect_img->count)
	{
		if (pic->player_img->instances[0].y == pic->exit_img->instances[0].y
			&& pic->player_img->instances[0].x == pic->exit_img->instances[0].x
			&& pic->exit_img->instances[0].enabled != false)
		{
			while (i < pic->collect_img->count)
				if (pic->collect_img->instances[i++].enabled == false)
					count++;
			if (count == pic->collect_img->count)
			{
				pic->exit_img->instances[0].enabled = false;
				ft_printf("\n%sCongrats, you finished the game!%s\n\n", G, D);
				exit(0);
			}
		}
		i++;
	}
}

//
bool	check_for_tree(t_pics *pic, int x, int y)
{
	size_t	i;
	int		current_x;
	int		current_y;

	i = 0;
	while (i < pic->tree_img->count)
	{
		current_x = pic->tree_img->instances[i].x;
		current_y = pic->tree_img->instances[i].y;
		if (current_x == x && current_y == y)
			return (false);
		i++;
	}
	return (true);
}

//
void	check_for_collect(t_pics *pic)
{
	size_t		i;
	int			player_x;
	int			player_y;
	static int	count;

	i = 0;
	if (count == 0)
		count = 1;
	player_x = pic->player_img->instances[0].x;
	player_y = pic->player_img->instances[0].y;
	while (i < pic->collect_img->count)
	{
		if (player_y == pic->collect_img->instances[i].y - 8
			&& player_x == pic->collect_img->instances[i].x - 8
			&& pic->collect_img->instances[i].enabled != false)
		{
			pic->collect_img->instances[i].enabled = false;
			ft_printf("%sFound collectables: %i\n%s", G, count++, D);
		}
		i++;
	}
}
