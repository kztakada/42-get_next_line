#include "get_next_line.h"
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q a.out");
// }

// int	main(void)
// {
// 	long	open_max;

// 	open_max = sysconf(_SC_OPEN_MAX);
// 	if (open_max == -1)
// 	{
// 		perror("sysconf");
// 		return (1);
// 	}
// 	printf("OPEN_MAX: %ld\n", open_max);
// 	return (0);
// }

int	main(void)
{
	int	fd1;
	int	fd2;
	int	fd3;

	fd1 = open("test1.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	// fd2 = 42;
	fd3 = open("test3.txt", O_RDONLY);
	char *line1, *line2, *line3;
	for (int i = 0; i < 30; i++)
	{
		line1 = get_next_line(fd1);
		printf("File1: %s", line1);
		line2 = get_next_line(fd2);
		printf("File2: %s", line2);
		line3 = get_next_line(fd3);
		printf("File3: %s", line3);
		if (!line1 && !line2 && !line3)
			break ;
		free(line1);
		free(line2);
		free(line3);
	}
	free(line1);
	free(line2);
	free(line3);
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}

/* for stdin test */
// int	main(void)
// {
// 	char	*result;
// 	int		fd;

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