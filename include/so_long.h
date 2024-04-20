/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraud <tbraud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:30:03 by tbraud            #+#    #+#             */
/*   Updated: 2024/04/20 05:53:46 by tbraud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../mlx/mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

//|----parsing----|
char	**ft_creat_map(char *argv[], size_t *size);
void	ft_check_duplicates(char **map);
int		ft_find_point(char **map, char to_find, int point[2]);

//|-----gnl------|
char	*get_next_line(int fd);

//|-----utils-----|
void	ft_bzero(char *s, size_t n);
char	*ft_strdup(char *s);
int		ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *arr);

//|-----error-----|
void	ft_free(char **map);
void	ft_error(char *erno, int choice, char **map);
void	ft_perror(void);

#endif /*SO_LONG_H */
