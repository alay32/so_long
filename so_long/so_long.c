/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mejd <ael-mejd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 01:27:32 by ael-mejd          #+#    #+#             */
/*   Updated: 2024/04/02 06:00:38 by ael-mejd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_check_element(char a)
{
	if (a == '0' || a == '1' || a == 'C' || a == 'E' || a == 'P')
		return (1);
	return (0);
}

void ft_check_elements(char **map)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_check_element(map[i][j]) == 0)
				print_error("map contains invalid element\n");
			j++;
		}
		i++;
	}
}

int calc_num_of_element(char **map, char element)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == element)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int ft_check_collectibles(char **map)
{
	int p_counter;
	int e_counter;
	int c_counter;

	p_counter = calc_num_of_element(map, 'P');
	e_counter = calc_num_of_element(map, 'E');
	c_counter = calc_num_of_element(map, 'C');
	if (p_counter > 1)
		print_error("map contain more than one player\n");
	if (p_counter < 1)
		print_error("There is no Player in the map\n");
	if (e_counter < 1)
		print_error("There is no exit in the map 3anebqaw 7aslin hna wla\n");
	if (e_counter > 1)
		print_error("There is more than exit\n");
	if (c_counter < 1)
		print_error("There is no COIN you should have at least one\n");
	return (0);
}

char *get_map_lines(char **av, t_data *data)
{
	char *lines;
	char *line;
	int fd;
	char **map;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (NULL);
	lines = malloc(sizeof(char));
	lines[0] = '\0';
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == '\n')
			print_error("Empty line\n");
		lines = ft_strjoin(lines, line);
		free(line);
		line = get_next_line(fd);
	}
	printf("map dyali :  \n%s\n", lines);
	map = ft_split(lines, '\n');
	free(lines);
	data->map = map;
	int i = 0;
	while (data->map[i])
		i++;
	printf("HEIGHT => %d\n", i);
	printf("WIDTH => %d\n", (int)ft_strlen(data->map[0]));

	return (*data->map);
}

void print_error(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	exit(1);
}

int exit_game(t_data *data)
{
	(void)data;
	exit(1);
}

int handle_keys(int keycode, t_data *data)
{
	if (keycode == 13)
	{
		data->i = -1;
		data->j = 0;
	}
	// khesni necriyiha change_position_in_map(data);
	// check wach kmlti lapples flmap kamlinn ila kmtihom had lvariable void *exit = mlx_xp..(exit_open)
	// call a function that changes tswira dlplayer 3la 7sab i and j
	draw_map(data);
	return (0);
}

void load_images(t_data *data)
{
	int width;
	int height;

	data->ground = mlx_xpm_file_to_image(data->mlx, "./textures/ground.xpm", &width, &height);
	data->wall = mlx_xpm_file_to_image(data->mlx, "./textures/wall.xpm", &width, &height);
}

void draw_map(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			mlx_put_image_to_window(data->mlx, data->win, data->ground, j * 30, i * 30);
			if (data->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->wall, j * 30, i * 30);
			else if (data->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->win, data->apple, j * 30, i * 30);
			else if (data->map[i][j] == 'P')
				mlx_put_image_to_window(data->mlx, data->win, data->player, j * 30, i * 30);
			else if (data->map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->win, data->exit, j * 30, i * 30);
			j++;
		}
		i++;
	}
}

void initialize_game(t_data *data)
{
	data->mlx = mlx_init();
	0 data->win = mlx_new_window(data->mlx, data->width * 30, data->height * 30, "so_long");
	mlx_hook(data->win, 2, 1L << 1, handle_keys, &data);
	mlx_hook(data->win, 17, 0, exit_game, &data);
	load_images(data);
	draw_map(data);
	mlx_loop(data->mlx);
}

int main(int argc, char **av)
{
	t_data data;
	int i;

	if (argc != 2)
		print_error("There is no map\n");
	check_ber(av[1]);
	get_map_lines(av, &data);
	ft_check_length(data.map);
	ft_check_walls(&data);
	ft_check_collectibles(data.map);
	ft_check_elements(data.map);
	initialize_game(&data);
	i = 0;
	while (data.map[i])
		free(data.map[i++]);
	free(data.map);
	return (0);
}
