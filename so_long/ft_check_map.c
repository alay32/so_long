#include "get_next_line.h"

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

int	check_ber(char *argument)
{
	while (*argument)
	{
		if (*argument == '.')
		{
			if (find_ber(argument, ".ber"))
			{
				return (1);
			}
		}
		argument++;
	}
	return (0);
}

int	ft_check_length(char **ptr)
{
	size_t length;
	int	i;

	length = ft_strlen(ptr[0]);
	i = 1;
	while (ptr[i])
	{
		if(ft_strlen(ptr[i]) != length)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

// int	ft_check_walls(char **map)
// {
// 	int i;
// 	int j;
// 	int height;
// 	int weight;

// 	i = 0;
// 	j = 0;
// 	height = 0;
// 	weight = 0;
// 	while(map[i++][j++])
// 	{
// 		if(map[i][j] == '\n')
// 			height++;
// 		if(map[i][j] != '\0')
// 			weight++;
// 	}
// 	while(map[i++][j++])
// 	{
// 		if(map[0][j] != '1' || map[height - 1][j] != '1')
// 			return (0);
// 		if(map[i][0] != '1' || map[i][weight - 1] != '1')
// 			return (0);
// 	}
// 	return (1);
// }


