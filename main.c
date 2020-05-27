#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int		ft_open_fd(void)
{
	int fd;
	fd = open("42", O_APPEND | S_IRWXU);
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
	int ret;
	int fd;

	/*int out;
	int p[2];

	//ret = 1;
	out = dup(1);
	pipe(p);

	fd = 1;
	dup2(p[1], fd);
	write(fd, "efghijkl", 8);
	close(p[1]);
	dup2(out, fd);
	get_next_line(p[0], &line);
	printf("l == %s\n", line);
	printf("strcmp1 == %d\n", strcmp(line, "efghijkl"));
	//free(line);
	//ret = get_next_line(p[0], &line);
	free(line);
	*///printf("ret == %d\n", ret);
	ret = 1;
	if (!(line = malloc(sizeof(char *) * BUFFER_SIZE + 1)))
		return (0);
	fd = ft_open_fd();
	while (ret != 0)
	{
		ret = get_next_line(fd, line);
		printf("%s %d", *line, ret);
	}
	//get_next_line(fd, line);
	//get_next_line(fd, line);
	//get_next_line(fd, line);
//	get_next_line(fd, line);
//	get_next_line(fd, line);
//	get_next_line(fd, line);
	//if (fd != -1)
	ft_close_fd(fd);
	free(line);
	return (0);
}
