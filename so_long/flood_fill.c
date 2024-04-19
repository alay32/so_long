/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mejd <ael-mejd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 01:12:46 by ael-mejd          #+#    #+#             */
/*   Updated: 2024/04/19 03:09:43 by ael-mejd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    flood_fill(char **map, int i, int j)
{
    if (map[i][j] == '1')
        return ;
    map[i][j] = '1';
    flood_fill(map, i + 1, j);
    flood_fill(map, i - 1, j);
    flood_fill(map, i, j + 1);
    flood_fill(map, i, j - 1);
}

void	check_flood_fill(char **ptr)
{
	int	i;
	int j;

	i = 0;
	while(ptr[i])
	{
		j = 0;
		while(ptr[i][j])
		{
			if (ptr[i][j] == 'C' || ptr[i][j] == 'E')
			{
				free_map(ptr);
				print_error("Invalid path to a necessary element\n");
			}
			j++;
		}
		i++;
	}
	free_map(ptr);
}
char    **copy_map(t_data *data)
{
    char **mapcopy;
	int idx;

	idx = 0;
    mapcopy = malloc(sizeof(char *) * (data->height + 1));
    if (!mapcopy)
        return (NULL);
	while(data->map[idx])
	{
		mapcopy[idx] = ft_strdup(data->map[idx]);
		idx++;
	}
	mapcopy[idx] = NULL;
	return (mapcopy);
}

void	check_path(t_data *data)
{
	char	**ptr;
	int i;
	int j;

	ptr = copy_map(data);
	if (ptr == NULL)
		exit(1);
	i = 0;
	while(data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				data->p_y = i;
				data->p_x = j;
			}
			j++;
		}
		i++;
	}
	flood_fill(ptr, data->p_y, data->p_x);
	check_flood_fill(ptr);
}
