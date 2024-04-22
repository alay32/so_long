/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mejd <ael-mejd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 00:58:13 by ael-mejd          #+#    #+#             */
/*   Updated: 2024/04/22 03:08:15 by ael-mejd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

# define UP_W 1
# define DOWN_S 13
# define RIGHT_D 2
# define LEFT_A 0
# define UP 125
# define DOWN 126
# define RIGHT 124
# define LEFT 123

typedef struct s_data
{
	int		i;
	int		j;
	int		p_y;
	int		p_x;
	int		dx;
	int		dy;
	int		c_number;
	int		num_of_moves;
	void	*mlx;
	void	*win;
	char	**map;
	int		width;
	int		height;
	void	*ground;
	void	*wall;
	void	*apple;
	void	*player;
	void	*exit;
}			t_data;

char		*ft_read_map(int argc, char **argv);
char		**ft_split(char *s, char c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		get_map_lines(char *av, t_data *data);
void		check_ber(char *argument);
void		ft_check_length(t_data *data);
void		ft_check_walls(t_data *data);
void		print_error(char *str);
void		draw_map(t_data *data);
char		*ft_strdup(const char *s1);
void		free_map(char **map);
int			calc_num_of_element(char **map, char element);
void		ft_putnbr_fd(int n, int fd);
void		ft_check_elements(char **map);
void		ft_check_collectibles(char **map);
/* flood fill functions*/
void		check_path(t_data *data);
int			exit_game(t_data *data);
void		change_player_position(t_data *data);
int			handle_keys(int keycode, t_data *data);
void		draw_map(t_data *data);
void		load_images(t_data *data);
#endif