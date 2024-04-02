/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mejd <ael-mejd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 01:12:46 by ael-mejd          #+#    #+#             */
/*   Updated: 2024/04/02 01:33:32 by ael-mejd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "so_long.h"

// void flood_fill(t_data *data, int i, int j)
// {
//     if (i < 0 || j < 0 || i > data->height )
// }
// void *ptr;
// void *win;
// mlx_init();
// mlx_new_window();
// mlx_

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