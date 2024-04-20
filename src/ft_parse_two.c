/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraud <tbraud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 05:18:39 by tbraud            #+#    #+#             */
/*   Updated: 2024/04/20 05:38:28 by tbraud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_find_point(char **map, char to_find, int point[2])
{
	int	x;
	int	y;
	int	count;

	y = 0;
	count = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == to_find && count == 0)
			{
				point[0] = x;
				point[1] = y;
				count++;
			}
			else if (map[y][x] == to_find)
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

void	ft_check_duplicates(char **map)
{
	int	i;
	int	j;
	int	point_p;
	int	point_e;

	i = 0;
	point_e = 0;
	point_p = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				point_e++;
			else if (map[i][j] == 'P')
				point_p++;
			j++;
		}
		i++;
	}
	if (point_e != 1 || point_p != 1)
		ft_error("wrong map given\n", 1, map);
}
