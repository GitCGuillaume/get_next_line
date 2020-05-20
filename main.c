#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int		ft_open_fd(void)
{
	int fd;
	fd = open("42", O_RDONLY | S_IRUSR);
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
#include <string.h>
int main(void)
{
	//placer macro dans get_next_line.h
	//static int buffer = BUFFER_SIZE;
	char **line;
	int fd;

	if (!(line = malloc(sizeof(char *) * BUFFER_SIZE + 1)))
		return (0);
	fd = ft_open_fd();
	//while (get_next_line(fd, line))
	//	printf("%s", *line);
	printf("\nfd == %d", fd);
	get_next_line(fd, line);
	get_next_line(fd, line);
	get_next_line(fd, line);
	get_next_line(fd, line);
	if (fd != -1)
		printf("ft_strcmp == %d", strcmp(*line, "hi"));
	ft_close_fd(fd);
	free(line);
	return (0);
}
