/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mejd <ael-mejd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:54:28 by ael-mejd          #+#    #+#             */
/*   Updated: 2024/04/22 23:47:46 by ael-mejd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_wall(t_data *data, char element, int i, int j)
{
	if (element == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->wall, j * 30, i
			* 30);
}

void	put_apple(t_data *data, char element, int i, int j)
{
	if (element == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->apple, j * 30, i
			* 30);
}

void	put_player(t_data *data, char element, int i, int j)
{
	if (element == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->player, j * 30, i
			* 30);
}

void	put_exit(t_data *data, char element, int i, int j)
{
	if (element == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->exit, j * 30, i
			* 30);
}

void	draw_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			mlx_put_image_to_window(data->mlx, data->win, data->ground, j * 30,
				i * 30);
			put_wall(data, data->map[i][j], i, j);
			put_apple(data, data->map[i][j], i, j);
			put_player(data, data->map[i][j], i, j);
			put_exit(data, data->map[i][j], i, j);
			j++;
		}
		i++;
	}
}
