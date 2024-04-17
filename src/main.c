/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraud <tbraud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:19:33 by tbraud            #+#    #+#             */
/*   Updated: 2024/04/17 21:15:42 by tbraud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_first_tab(char *argv[])
{
	int		fd;
	int		j;
	char	**map;
	char	*tmp;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_perror();
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		j++;
		free(tmp);
	}
	if (j < 3)// taille minimum pour une map
		ft_perror();
	map = malloc(sizeof(char *) * j + 1);
	if (!map)
		ft_perror();
	return (map); // initialisation ??? 
}

char	**ft_creat_map(char *argv[])
{
	char	**map;
	int		fd;

	map = ft_first_map(argv); // determine la taille du tableau de pointeur
	ft_put_map(argv, map);    // remplie le tableau de pointeur avec gnl
	ft_test_map(map);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_perror(); // erreur d'ouverture (pas le droit a access)
}

int	main(int argc, char *argv[])
{
	char **tab;
	// void	*mlx;

	if (argc == 0 || !argv[1]) // erreur ou pas pour le second cas ?
		return (0);
	tab = ft_creat_map(argv);
}