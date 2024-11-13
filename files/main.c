/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorst <chorst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:29:54 by chorst            #+#    #+#             */
/*   Updated: 2024/04/16 13:02:43 by chorst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Exit the program as failure.
void	ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

// Function to convert the .ber file to char **map (map[x][y])
char	**map_read(char *map_file_path, char **map)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(map_file_path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map = malloc(sizeof(char *) * (map_line_count(fd) + 1));
	if (map == NULL)
		return (close(fd), NULL);
	close(fd);
	fd = open(map_file_path, O_RDONLY);
	map[i] = get_next_line(fd);
	while (map[i] != NULL)
	{
		i++;
		map[i] = get_next_line(fd);
	}
	close(fd);
	return (map);
}

// Main of course
int	main(int argc, char **argv)
{
	t_pics	*pic;
	t_pos	pos;

	pic = NULL;
	pic = malloc(sizeof(t_pics));
	if (!pic)
		return (0);
	if (argc == 2 && ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4))
	{
		ft_printf("%s\nWrong file type as input\n\n%s", R, D);
		return (0);
	}
	if (argc == 2)
	{
		pic->map = map_read(argv[1], pic->map);
		pos = get_map_positions(pic->map);
		if (map_validator(pic->map, pos))
			return (print_map(pic->map), free_the_map(pic->map), free(pic), 0);
		map_picture(pic);
		free_the_map(pic->map);
		ft_printf("%sEnd of Programm\n%s", B, D);
	}
	else
		return (printf("%sError!\nInvalid argument ammount.\n%s", R, D));
}

// Print the window width and height.
// static void ft_hook(void* param)
// {
// 	const mlx_t* mlx = param;
// 	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
// }

// atexit(check_leak);

// Helper function to check the leaks after the programm exits.
// void	check_leak(void)
// {
// 	system("leaks so_long");
// }
