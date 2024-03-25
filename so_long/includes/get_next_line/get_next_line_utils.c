/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mejd <ael-mejd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 01:14:14 by ael-mejd          #+#    #+#             */
/*   Updated: 2024/03/22 02:22:54 by ael-mejd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0 && dst && src)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dst;
	size_t	size;
	int		i;
	size_t	dstlen;

	i = 0;
	dstlen = ft_strlen(s1);
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	size = dstlen + ft_strlen(s2);
	dst = (char *)malloc(sizeof(char) * (size + 1));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s1, (size + 1));
	while (s2[i] && s2[i] != '\n')
		dst[dstlen++] = s2[i++];
	if (s2[i] == '\n')
		dst[dstlen++] = '\n';
	dst[dstlen] = '\0';
	return (free(s1), dst);
}


