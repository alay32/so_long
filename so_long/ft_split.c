/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mejd <ael-mejd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 01:14:19 by ael-mejd          #+#    #+#             */
/*   Updated: 2024/04/22 02:09:53 by ael-mejd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char *ft_strchr(const char *s, char *c)
{
	char *str;

	str = (char *)s;
	while (*str != *c)
	{
		if (*str == '\0')
		{
			return (NULL);
		}
		str++;
	}
	return (str);
}

static size_t ft_countword(char const *s, char c)
{
	size_t count;
	int i;

	i = 0;
	if (!s[i])
		return (0);
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static char **ft_free(char **arr)
{
	int i;

	i = 0;
	while (arr && arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

char **ft_split(char *s, char c)
{
	char **lst;
	size_t word_len;
	int i;

	lst = (char **)malloc((ft_countword(s, c) + 1) * sizeof(char *));
	if (!s || !lst)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, &c))
				word_len = ft_strlen(s);
			else
				word_len = ft_strchr(s, &c) - s;
			lst[i++] = ft_substr(s, 0, word_len);
			if (lst[i - 1] == NULL)
				return (ft_free(lst));
			s += word_len;
		}
	}
	return (lst[i] = NULL, lst);
}
