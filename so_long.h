/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorst <chorst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:29:45 by chorst            #+#    #+#             */
/*   Updated: 2024/04/16 11:14:48 by chorst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./MLX42/include/MLX42/MLX42.h"
# include "gnl/get_next_line.h"
# include "./libft/libft.h"
# include "printf/ft_printf.h"
# include <memory.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define WIDTH 48
# define HEIGHT 48

// Farbdefinitionen
# define R "\033[0;31m"
# define G "\033[0;32m"
# define B "\033[0;34m"
# define Y "\033[0;93m"
# define D "\033[0m"

typedef struct s_grid
{
	int				row;
	int				col;
}					t_grid;

typedef struct s_chars
{
	t_grid			p;
}					t_chars;

typedef struct s_count
{
	int				p;
	int				e;
	int				c;
}					t_count;

typedef struct s_pos
{
	t_count			count;
	t_chars			character;
	int				start_row;
	int				start_col;
	int				end_row;
	int				end_col;
}					t_pos;

typedef struct s_pics
{
	char			**map;
	mlx_t			*mlx;
	mlx_texture_t	*tree_tex;
	mlx_texture_t	*path_tex;
	mlx_texture_t	*collect_tex;
	mlx_texture_t	*player_tex;
	mlx_texture_t	*exit_tex;
	mlx_image_t		*tree_img;
	mlx_image_t		*grass_img;
	mlx_image_t		*collect_img;
	mlx_image_t		*player_img;
	mlx_image_t		*exit_img;
}					t_pics;

// main.c
char				**map_read(char *map_file_path, char **map);
void				ft_error(void);
void				check_leak(void);

// helper_function.c
int					map_line_count(int fd);
void				free_the_map(char **map);
void				print_map(char **map);
void				show_player(t_pics *pic);

// map_form_check.c
int					map_form_check(char **map, t_pos pos);
int					map_char_check(char **map);
int					map_size_and_pec_check(t_pos pos);
int					map_rectangle_check(char **map, t_pos pos);
int					map_surrounded_by_1_check(char **map, t_pos pos);

// get_map_positions.c
t_pos				get_map_positions(char **map);
t_grid				get_p_position(char **map);
int					count_char(char **map, char c);

// map_path_check.c
int					map_path_check(char **map, t_pos pos);
int					path_p_to_e_check(char **map, t_grid start);
int					path_p_to_c_check(char **map, t_grid start, int *count);
int					map_lines(char **map);
char				**copy_map(char **map);

// map_validator.c
int					map_validator(char **map, t_pos positions);

// map_pictures.c
void				map_picture(t_pics *pic);
void				*get_map_pictures(t_pics *pic);
void				show_map_pictures(t_pics *pic);
void				show_player(t_pics *pic);
void				chose_img(t_pics *pic, int i, int x);
void				delete_map_pictures(t_pics *pic);

// map_functions.c
void				keybinding(mlx_key_data_t keydata, void *param);
void				check_for_img(t_pics *pic, int dx, int dy);
bool				check_for_tree(t_pics *pic, int x, int y);
void				check_for_collect(t_pics *pic);
void				check_for_exit(t_pics *pic);

#endif
