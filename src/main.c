/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraud <tbraud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:19:33 by tbraud            #+#    #+#             */
/*   Updated: 2024/04/20 17:46:02 by tbraud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pri(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}
void	*ft_choose_img(char block, void *mlx)
{
	int	i[2];

	if (block == '1')
		return (mlx_xpm_file_to_image(mlx, "./sprite/first_sprite.xpm", &i[0],
				&i[1]));
	else if (block == 'o')
		return (mlx_xpm_file_to_image(mlx, "./sprite/pixil-frame-0.xpm", &i[0],
				&i[1]));
	else if (block == 'c')
		return (mlx_xpm_file_to_image(mlx, "./sprite/pixil-frame-1.xpm", &i[0],
				&i[1]));
	else if (block == 'P')
		return (mlx_xpm_file_to_image(mlx, "./sprite/pixil-frame-1.xpm", &i[0],
				&i[1]));
	else if (block == 'e')
		return (mlx_xpm_file_to_image(mlx, "./sprite/pixil-frame-1.xpm", &i[0],
				&i[1]));
	return (0);
}

void	ft_insert_map(char **map, void *mlx, void *mlx_win)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			mlx_put_image_to_window(mlx, mlx_win, ft_choose_img(map[y][x], mlx),
				x * 32, y * 32);
			x++;
		}
		y++;
	}
}
/*a chaque pas juste tu test les x et y et tu ecrase l'autre image,
	et tu met l'image du 0 derriere sauf si on est sur E*/
/*comprendre les evenements*/
int	main(int argc, char *argv[])
{
	char **map;
	size_t size_map;
	void *mlx;
	void *mlx_win;
	int i[2];

	if (argc == 0 || !argv[1])
		ft_error("wrong input\n", 0, 0);
	map = ft_creat_map(argv, &size_map);
	pri(map);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, (ft_strlen(map[0])) * 32, size_map * 32,
			"so_long<3");
	ft_insert_map(map, mlx, mlx_win);
	mlx_loop(mlx);
	ft_free(map);
}