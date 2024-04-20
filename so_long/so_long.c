/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mejd <ael-mejd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 01:27:32 by ael-mejd          #+#    #+#             */
/*   Updated: 2024/04/20 11:49:30 by ael-mejd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_element(char a)
{
	if (a == '0' || a == '1' || a == 'C' || a == 'E' || a == 'P')
		return (1);
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
				print_error("map contains invalid element\n");
			j++;
		}
		i++;
	}
}

int	calc_num_of_element(char **map, char element)
{
	int	i;
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

void	ft_check_collectibles(char **map)
{
	int	p_counter;
	int	e_counter;
	int	c_counter;

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
}

void	print_error(char *str)
{
	int	i;

	i = 0;
	write(2, "Error\n", 6);
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	exit(1);
}
