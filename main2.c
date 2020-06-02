//#include <project.h>
#include <stdio.h>
#include <string.h>
#include "get_next_line.h"
int main(void)
{
	char 	*line;
	int		out;
	int		p[2];
	int		gnl_ret;

	out = dup(1);
	pipe(p);
	dup2(p[1], 1);
	write(1, "abcd\nfk\njk", 11);
	close(p[1]);
	dup2(out, 1);
	gnl_ret = -1;
	while (gnl_ret != 0)
	{
		gnl_ret = get_next_line(p[0], &line);
		printf("strcmp==%s\n", line);
		printf("ret==%d", gnl_ret);
	}
	//mt_assert(strcmp(line, str) == 0);
	//mt_assert(gnl_ret == 0 || gnl_ret == 1);
	free(line);
}
