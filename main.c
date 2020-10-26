#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

void	ft_putstr_fd(char *s, int fd);

int		ft_open_fd(void)
{
	int fd;
	fd = open("42", O_RDONLY);
	printf("fd1=%d\n", fd);
	if (fd == -1)
	{
		printf("L'ouverture n'a pu se faire, vérifiez si fichier existe ou les droits");
	}
	return (fd);
}

int		ft_open_fd2(void)
{
	int fd;
	fd = open("43", O_RDONLY);
	printf("fd2=%d\n", fd);
	if (fd == -1)
	{
		printf("L'ouverture n'a pu se faire, vérifiez si fichier existe ou les droits");
	}
	return (fd);
}
int		ft_open_fd3(void)
{
	int fd;
	fd = open("bible2.txt", O_APPEND | O_WRONLY);
	if (fd == -1)
	{
		printf("L'ouverture n'a pu se faire, vérifiez si fichier existe ou les droits");
	}
	char end;

	end = '\0';
	write (fd, &end, 1);
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
	/*char 	*line;
	int		out;
	int		p[2];
	char 	*str;
	int		len = 50;
	str = (char *)malloc(1000 * 1000);
	*str = '\0';
	while (len--)
		strcat(str, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur in leo dignissim, gravida leo id, imperdiet urna. Aliquam magna nunc, maximus quis eleifend et, scelerisque non dolor. Suspendisse augue augue, tempus");
	out = dup(1);
	pipe(p);
	dup2(p[1], 1);
	if (str)
		write(1, str, strlen(str));
	close(p[1]);
	dup2(out, 1);
	get_next_line(p[0], &line);
	printf("%d", strcmp(line, str));
	free(line);
	free(str);*/
	//placer macro dans get_next_line.h
	//static int buffer = BUFFER_SIZE;
	char *line;
	int ret;
	//int fd;

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
	int test[200];
	int fd;
	int fd2;
	//int fd3;
	int ret2;
	//if (!(line = malloc(sizeof(char *) * BUFFER_SIZE + 1)))
	//	return (0);
	line = NULL;
	int j = 0;
	while (200 > j)
	{
		ret = 1;
		fd = ft_open_fd();
		test[j] = fd;
		if (test[j] != -1)
		{
			char n;
			n = '\n';
			while (ret != 0 && ret != -1)
			{
				ret = get_next_line(test[j], &line);
				printf("j=%d fd = %d ret = %d", j, test[j], ret);
				printf("%s", line);
				free(line);
				fd2 = ft_open_fd2();
				ret2 = 1;
				while (ret2 != 0 && ret2 != -1)
				{
					ret2 = get_next_line(fd2, &line);
					printf("ret2 = %d %s", ret2, line);
					free(line);
					if (ret2 == 1)
						printf("\n");
				}
				if (ret == 1)
					printf("\n");
				if (fd2 != -1)
					ft_close_fd(fd2);
			}
			j++;
		}
	}
	printf("\n");
	while (j != 0)
	{
		j--;
		if (test[j] != -1)
		{
				printf("will be close = %d ", test[j]);
				ft_close_fd(test[j]);
		}
	}	/*while (ret2 != 0 && ret2 != -1)
		{
			ret2 = get_next_line(fd2, &line);
			printf("%s", line);
			free(line);
			if (ret2 == 1)
				printf("\n");
		}*/
	

	//fd3 = ft_open_fd();
	//ft_open_fd3();
		//free(line);
//	printf("\n");
	//get_next_line(fd, line);
	//get_next_line(fd, line);
	//get_next_line(fd, line);
//	get_next_line(fd, line);
//	get_next_line(fd, line);
//	get_next_line(fd, line);
	/*while (j != 0)
	{
		if (fd != -1)
			ft_close_fd(fd);
	}*/
	return (0);
}
