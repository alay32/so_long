/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mejd <ael-mejd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 01:27:32 by ael-mejd          #+#    #+#             */
/*   Updated: 2024/03/24 22:44:05 by ael-mejd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_walls(char **map)
{
	int i;
	int j;
	int height;
	int width;

	i = 0;
	j = 0;
	height = 0;
	width = 0;

    while (map[height])
        height++;
    width = (int)ft_strlen(map[0]);
    printf("height => %d\n",height);
    printf("width => %d\n",width);
    while (map[i])
    {
        if ((int)ft_strlen(map[i++]) != width)
        {
            printf("Error, MAP KHASHA TKON MRB3A !!");
            exit(0);
        }
    }
    i = 0;
    while(map[i])
    {    
        if(map[0][j] != '1' || map[height - 1][j] != '1')
		    {
                printf("map mafihaxi hyot\n");
                exit(1);
            }
		if(map[i][0] != '1' || map[i][width - 1] != '1')
		    {
                printf("map mafihaxi jwanb");
                exit(1);
            }
        i++;
        j++;
    }
    return (1);
}

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
    char *lines = NULL;
    char *line;
    int fd;

    fd = open(av[1],O_RDONLY);
    printf("fd ==> %d\n", fd);
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
    printf("%s\n", lines);
    char **map;
    map = ft_split(lines, '\n');
    free(lines);
    int i = 0;
    printf("khawa dyali \n");
    while(map[i])
    {
        printf("%s\n", map[i]);
        i++;
    }
    printf("khawa dyali \n");
    data->map = map;
    return (*data->map);
}

int main(int argc, char **av)
{
    t_data data;
    if (argc == 2)
    {
        get_map_lines(av, &data);
    }
    ft_check_walls(data.map);
    ft_check_collectibles(data.map);
	ft_check_elements(data.map);
    int i = 0;
    while (data.map[i])
        free(data.map[i++]);
    free(data.map);
    return (0);
}
