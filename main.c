#include "get_next_line.h"
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q a.out");
// }

// valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./a.out

int	main(void)
{
	char	*result;
	int		fd;

	fd = open("test1.txt", O_RDONLY);
	for (int i = 0; i < 10; i++)
	{
		result = get_next_line(fd);
		printf("%s", result);
		if (!result)
			break ;
		free(result);
	}
	free(result);
	close(fd);
}

/* for stdin test */
// int	main(void)
// {
// 	char *result;
// 	int fd;

// 	fd = STDIN_FILENO;
// 	for (int i = 0; i < 2; i++)
// 	{
// 		result = get_next_line(fd);
// 		printf("%s", result);
// 		if (!result)
// 			break ;
// 		free(result);
// 	}
// }