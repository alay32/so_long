/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mejd <ael-mejd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 00:58:13 by ael-mejd          #+#    #+#             */
/*   Updated: 2024/04/02 02:39:19 by ael-mejd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H
/// compilation with flags (-L -l -I)
#include "./includes/get_next_line/get_next_line.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mlx.h>

typedef struct s_data
{
	void *mlx;
	void *win;
	char **map;
	int width;
	int height;
	void *ground;
	void *wall;
} t_data;

char *ft_read_map(int argc, char **argv);
char **ft_split(char *s, char c);
char *ft_substr(char const *s, unsigned int start, size_t len);
char *get_map_lines(char **av, t_data *data);
int check_ber(char *argument);
int ft_check_length(char **ptr);
int ft_check_walls(t_data *data);
void print_error(char *str);

#endif