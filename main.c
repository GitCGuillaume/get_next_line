#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int		ft_open_fd(void)
{
	int fd;
	fd = open("42", O_RDONLY | S_IRUSR);
	if (fd == -1)
	{
		printf("L'ouverture n'a pu se faire, vérifier si fichier existe ou les droits");
		return (1);
	}
	return (fd);
}

int		ft_close_fd(int fd)
{
	if (close(fd) == -1)
	{
		printf("La fermeture a raté.");
		return (1);
	}
	return (fd);
}

int main(void)
{
	//placer macro dans get_next_line.h
	//static int buffer = BUFFER_SIZE;
	char **line;
	int fd;

	if (!(line = malloc(sizeof(char *) * BUFFER_SIZE + 1)))
		return (0);
	fd = ft_open_fd();
	get_next_line(fd, line);
	free(line);
	return (0);
}
