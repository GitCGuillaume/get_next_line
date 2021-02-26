#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int		ft_open_fd(char *path)
{
	int fd;
	fd = open(path, O_RDONLY);
	printf("fd=%d\n", fd);
	if (fd == -1)
	{
		printf("L'ouverture n'a pu se faire, vérifiez si fichier existe ou les droits");
	}
	return (fd);
}

int		ft_close_fd(int fd)
{
	if (close(fd) == -1)
	{
		printf("La fermeture a raté.");
	}
	return (fd);
}

int	main(void)
{
	int res;
	int fd[3];
	char *line;

	fd[0] = ft_open_fd("42");
	fd[1] = ft_open_fd("43");
	fd[2] = ft_open_fd("44");
	
	res = get_next_line(fd[0], &line);
	printf("res=%d line=%s\n", res, line);
	free(line);
	res = get_next_line(fd[1], &line);
	printf("res=%d line=%s\n", res, line);
	free(line);
	res = get_next_line(fd[2], &line);
	printf("res=%d line=%s\n", res, line);
	free(line);
	
	res = get_next_line(fd[0], &line);
	printf("res=%d line=%s\n", res, line);
	free(line);
	res = get_next_line(fd[1], &line);
	printf("res=%d line=%s\n", res, line);
	free(line);
	res = get_next_line(fd[2], &line);
	printf("res=%d line=%s\n", res, line);
	free(line);
	res = get_next_line(fd[1], &line);
	printf("res=%d line=%s\n", res, line);
	free(line);


	ft_close_fd(fd[0]);
	ft_close_fd(fd[1]);
	ft_close_fd(fd[2]);
	return (0);
}
