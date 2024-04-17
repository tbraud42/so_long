/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraud <tbraud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:37:39 by tbraud            #+#    #+#             */
/*   Updated: 2024/04/09 18:47:28 by tbraud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_perror()
{
	write(2, "Error\n", 7);
	ft_perror(errno);
}

void	ft_error(char *erno)
{
	write(2, "Error\n", 7);
	if (erno)
		write(2, erno, ft_strlen(erno));
	exit(EXIT_FAILURE);
}
