/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mejd <ael-mejd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 01:27:32 by ael-mejd          #+#    #+#             */
/*   Updated: 2024/03/30 02:48:01 by ael-mejd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_check_element(char a)
{
    if (a == '0' || a == '1' || a == 'C' || a == 'E' || a == 'P')
        return(1);
    return (0);
}

void	ft_check_elements(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_check_element(map[i][j]) == 0)
			{
				write(2, "map contains invalid element\n", 29);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

int calc_num_of_element(char **map, char element)
{
    int i;
	int	j;
	int	count;

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
    if (p_counter != 1 || e_counter != 1 || c_counter < 1)
	{
		printf("chlla biban 3la walo");
		exit(1);
	}
    return (0);
}

char *get_map_lines(char **av, t_data *data)
{
    char *lines;
    char *line;
    int fd;

    fd = open(av[1], O_RDONLY);
    if (fd < 0)
        return (NULL);
    lines = malloc(sizeof(char));
    lines[0] = '\0';
    line = get_next_line(fd);
    while (line)
    {
		if (line[0] == '\n')
		{
			write(2, "empty line\n", 11);
			exit(EXIT_FAILURE);
		}
        lines = ft_strjoin(lines, line);
        free(line);
        line = get_next_line(fd);
    }
    printf("map dyali :  \n%s\n", lines);
    char **map;
    map = ft_split(lines, '\n');
    free(lines);
    data->map = map;
    return (*data->map);
}

int main(int argc, char **av)
{
    t_data data;
    if (argc != 2)
    {
        printf("makynaxi lmap");
        exit(1);
    }
    if(!ft_check_length(av))
	{
		write(2, "the map must be recunguaire\n", 28);
		exit(1);
	}
    get_map_lines(av, &data);
    ft_check_walls(data.map);
    ft_check_collectibles(data.map);
	ft_check_elements(data.map);
    int i = 0;
    while (data.map[i])
        free(data.map[i++]);
    free(data.map);
    return (0);
}
