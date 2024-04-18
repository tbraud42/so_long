/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tao <tao@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:19:33 by tbraud            #+#    #+#             */
/*   Updated: 2024/04/18 03:56:31 by tao              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *arr)
{
	int	i;

	if (!arr)
		return (0);
	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	ft_free(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

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
	if (j > 3)// taille minimum pour une map
	{
		map = malloc(sizeof(char *) * j + 1);
		map[j] = NULL;// nan
		if (map)
			return (map);// initialisation ??? 
	}
	close(fd);
	ft_perror();
}

int	ft_put_map(char *argv[], char **map)
{
	int	fd;
	int	i;
	
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		free(map);
		ft_perror();
	}
	i = 0;
	while (tab[i])
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		tab[i] = tmp;
		i++;
		free(tmp);
	}
	return (i);
}

void	ft_test_rectangle(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(map[0])
	while (map[i] && ft_strlen(map[0]) == j)
		i++;
	if (!map[i])
		return ;
	ft_free(map);
	ft_error();
}

void	ft_test_block(char **map, int size)
{
	int	i;
	int	j;
	int x;

	i = 0;
	x = ft_strlen(map[0]);
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if ((i == 0 || i == size) && map[i][j] != '1')
				break ;
			if ((j == 0 || j == x - 1) && map[i][j] != '1')
				break ;
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C' && map[i][j] != 'E' && map[i][j] != 'P')
				break ; 
			j++;
		}
		i++;
	}
	if (i == size + 1)
		return ;
	ft_free(map);
	ft_error();
}

char	**ft_creat_map(char *argv[])
{
	char	**map;
	int		i;

	map = ft_first_map(argv);
	i = ft_put_map(argv, map);
	ft_test_rectangle(map);
	ft_test_block(map, i);
}

int	main(int argc, char *argv[])
{
	char **tab;
	// void	*mlx;

	if (argc == 0 || !argv[1]) // erreur ou pas pour le second cas ?
		return (0);
	tab = ft_creat_map(argv);
}