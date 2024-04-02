#include "so_long.h"

static int find_ber(char *str, char *to_find)
{
	int i;

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

int check_ber(char *argument)
{
	while (*argument)
	{
		if (*argument == '.')
		{
			if (find_ber(argument, ".ber"))
			{
				return (0);
			}
		}
		argument++;
	}
	print_error("The map must be ending by .ber\n");
	return (1);
}

int ft_check_length(char **ptr)
{
	int length;
	int i;

	length = (int)ft_strlen(ptr[0]);
	i = 1;
	while (ptr[i])
	{
		if ((int)ft_strlen(ptr[i]) != length)
		{
			print_error("The map must be rectungulaire\n");
		}
		i++;
	}
	return (1);
}

int ft_check_walls(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (data->map[data->height])
		data->height++;
	printf("height ==> %d\n", data->height);
	data->width = (int)ft_strlen(data->map[0]);
	printf("width ==> %d\n", data->width);
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
	printf("i ==> %d\n", i);
	printf("j ==> %d\n", j);
	return (1);
}
