//#include <project.h>
#include <stdio.h>
#include "get_next_line.h"
int main(void)
{
	char 	*line;
	int	fd = 10000;
	int		out = dup(fd);
	int		p[2];
	int		gnl_ret;
	printf("open_max=%d\n", OPEN_MAX);
	pipe(p);
	dup2(p[1], fd);
	write(fd, "azsdfsfd\nskf\ndfert", 19);
	//write(1, NULL, 1);
	dup2(out, fd);
	close(p[1]);
	gnl_ret = 1;
	printf("\n------------\n");
	//if (!(line = malloc(sizeof(char) * 10)))
	//	return (0);
	//while (gnl_ret != 0 && gnl_ret != -1)
	/*while ((gnl_ret = get_next_line(p[0], &line)) > 0)
	{
		//gnl_ret = get_next_line(p[0], &line);
		printf("strcmp==%s", line);
		free(line);
		printf("ret==%d\n", gnl_ret);
	}
	printf("strcmp==%s", line);
	printf("ret==%d\n", gnl_ret);
	free(line);*/
	/*while (gnl_ret != 0 && gnl_ret != -1)
	{
		gnl_ret = get_next_line(p[0], &line);
		printf("strcmp==%s", line);
		free(line);
		printf("ret==%d\n", gnl_ret);
	}*/
	get_next_line(p[0], &line);
	//free(line);
	//printf("\n------------\n");
	//mt_assert(strcmp(line, str) == 0)
	//mt_assert(gnl_ret == 0 || gnl_ret == 1);
	return (0);
}
