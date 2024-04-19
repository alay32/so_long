/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mejd <ael-mejd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 00:58:13 by ael-mejd          #+#    #+#             */
/*   Updated: 2024/04/19 03:28:35 by ael-mejd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "./includes/get_next_line/get_next_line.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mlx.h>


#define UP 126
#define DOWN 125
#define RIGHT 124
#define LEFT 123

typedef struct s_data
{
	int i;
	int j;
	int p_y;
	int	p_x;
	void *mlx;
	void *win;
	char **map;
	int width;
	int height;
	void *ground;
	void *wall;
	void *apple;
	void *player;
	void *exit;
} t_data;

char *ft_read_map(int argc, char **argv);
char **ft_split(char *s, char c);
char *ft_substr(char const *s, unsigned int start, size_t len);
void get_map_lines(char *av, t_data *data);
void check_ber(char *argument);
void  ft_check_length(char **ptr);
void ft_check_walls(t_data *data);
void print_error(char *str);
void draw_map(t_data *data);
char *ft_strdup(const char *s1);
void free_map(char **map);
/* flood fill functions*/
void	check_path(t_data *data);

#endif