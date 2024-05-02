/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mejd <ael-mejd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:35:56 by ael-mejd          #+#    #+#             */
/*   Updated: 2024/04/20 11:36:26 by ael-mejd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	checknewline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_rest(char *str)
{
	char	*rest;
	int		i;
	int		len;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	len = ft_strlen(str) + 1;
	rest = malloc(len * sizeof(char));
	if (!rest)
		return (NULL);
	ft_strlcpy(rest, str + i, len);
	free(str);
	return (rest);
}

char	*ft_return(char *line, char *buffer, ssize_t r)
{
	if (r == -1)
		return (free(line), free(buffer), NULL);
	else if (r == 0)
	{
		if (ft_strlen(line) > 0)
			return (free(buffer), line);
		else
			return (free(buffer), free(line), NULL);
	}
	return (NULL);
}

char	*ft_get_line(int fd, char *line, char *buffer, char **rest)
{
	ssize_t	r;

	if (*rest != NULL)
	{
		line = ft_strjoin(line, *rest);
		if (checknewline(line))
		{
			*rest = get_rest(*rest);
			if (ft_strlen(*rest) > 0)
				return (free(buffer), line);
			return (free(buffer), free(*rest), *rest = NULL, line);
		}
		free(*rest);
		*rest = NULL;
	}
	while (1)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r <= 0)
			return (ft_return(line, buffer, r));
		buffer[r] = '\0';
		line = ft_strjoin(line, buffer);
		if (checknewline(line))
			return (*rest = get_rest(buffer), line);
	}
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*rest;
	char		*line;

	if (fd < 0 || fd > 256 || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	buffer = malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!buffer)
		return (free(line), NULL);
	return (ft_get_line(fd, line, buffer, &rest));
}
