/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mejd <ael-mejd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:44:13 by ael-mejd          #+#    #+#             */
/*   Updated: 2024/04/22 16:28:18 by ael-mejd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_map_lines(char *av, t_data *data)
{
	char	*lines;
	char	*line;
	int		fd;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		print_error("file not open!\n");
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
	if (lines[0] == '\0')
	{
		free(lines);
		print_error("empty map\n");
	}
	data->map = ft_split(lines, '\n');
	free(lines);
}

void	initialize_game(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return ;
	data->win = mlx_new_window(data->mlx, data->width * 30, data->height * 30,
			"so_long");
	if (!data->win)
		return ;
	load_images(data);
	draw_map(data);
	data->c_number = calc_num_of_element(data->map, 'C');
	mlx_hook(data->win, 2, 0, handle_keys, data);
	mlx_hook(data->win, 17, 0, exit_game, data);
	mlx_loop(data->mlx);
}

int	main(int argc, char **av)
{
	t_data	data;

	if (argc != 2)
		print_error("There is no map\n");
	check_ber(av[1]);
	get_map_lines(av[1], &data);
	ft_check_length(&data);
	ft_check_walls(&data);
	ft_check_collectibles(data.map);
	ft_check_elements(data.map);
	check_path(&data);
	initialize_game(&data);
	free_map(data.map);
	return (0);
}
