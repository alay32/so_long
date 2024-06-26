/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mejd <ael-mejd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:34:09 by ael-mejd          #+#    #+#             */
/*   Updated: 2024/04/24 00:41:43 by ael-mejd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	find_ber(char *str, char *to_find)
{
	int	i;

	i = 0;
	while (to_find[i])
	{
		if (to_find[i] != str[i])
			return (0);
		i++;
	}
	if (str[i] == '\0')
		return (1);
	return (0);
}

void	check_ber(char *argument)
{
	int	i;

	if (ft_strlen(argument) < 5)
		print_error("The map must be ending by .ber\n");
	i = 0;
	while (argument[i])
	{
		if (argument[i] == '.')
		{
			if (find_ber(argument + i, ".ber"))
			{
				if (argument[ft_strlen(argument) - 5] != '/')
					return ;
			}
		}
		i++;
	}
	print_error("The map must be ending by .ber\n");
}

void	ft_check_length(t_data *data)
{
	data->width = ft_strlen(data->map[0]);
	data->height = 0;
	while (data->map[data->height])
	{
		if ((int)ft_strlen(data->map[data->height]) != data->width)
		{
			print_error("The map must be rectungulaire\n");
			free_map(data->map);
		}
		data->height++;
	}
}

void	ft_check_walls(t_data *data)
{
	int	i;
	int	j;

	data->height = 0;
	i = 0;
	while (data->map[data->height])
		data->height++;
	data->width = (int)ft_strlen(data->map[0]);
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][0] != '1' || data->map[i][data->width - 1] != '1')
				print_error("Abscence de 1 verticale\n");
			if (data->map[0][j] != '1' || data->map[data->height - 1][j] != '1')
				print_error("Abscence de 1 horizontal\n");
			j++;
		}
		i++;
	}
}
