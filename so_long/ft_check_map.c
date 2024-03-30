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
	int length;
	int	i;

	length = (int)ft_strlen(ptr[0]);
	i = 1;
	while (ptr[i])
	{
		if((int)ft_strlen(ptr[i]) != length)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_check_walls(char **map)
{
	int i;
	int j;
	int height;
	int width;

	i = 0;
	j = 0;
	height = 0;
	width = 0;

    while (map[height])
        height++;
    width = (int)ft_strlen(map[0]);
    while(map[i])
    {    
        if(map[0][j] != '1' || map[height - 1][j] != '1')
		    {
                printf("map mafihaxi hyot\n");
                exit(1);
            }
		if(map[i][0] != '1' || map[i][width - 1] != '1')
		    {
                printf("map mafihaxi jwanb");
                exit(1);
            }
        i++;
        j++;
    }
    return (1);
}
