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
		    printf("map mafihaxi hyot");
		if(map[i][0] != '1' || map[i][width - 1] != '1')
		    printf("map mafihaxi jwanb");
        i++;
        j++;
    }
    return (1);
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
        lines = ft_strjoin(lines, line);
        line = get_next_line(fd);
    }
    printf("%s\n", lines);
    char **map;
    map = ft_split(lines, '\n');
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
    return (0);
}
