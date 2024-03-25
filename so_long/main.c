
#include "get_next_line.h"
#include <stdio.h>

// int	main(int argc, char **argv)
// {
// 	if (!argv[1] || !check_ber(argv[1]))
// 	{
// 		printf("Wrong map!!");
// 		return (0);
// 	}	
// 	char *tab;
// 	tab = ft_read_map(argc, argv);
// 	printf("%s", tab);
// 	printf("\nmap apres split : \n");
// 	char **map;
// 	map = (char **)malloc(sizeof(char *));
// 	map = ft_split(tab, '\n');
// 	int i = 0, j = 0;
// 	for (i = 0; map[i] != NULL; i++)
// 	{
// 		for (j = 0; map[i][j] != '\0'; j++)
// 			printf("%c", map[i][j]);
// 		printf("\n\n");
// 	}
// 	if(ft_check_length(map))
// 		printf("lenth makhedamx");
// 	// if (ft_check_walls(map))
// 	// 	printf("kolxi hyout");
// 	return (0);
// }