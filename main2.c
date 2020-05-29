//#include <project.h>
#include <stdio.h>
#include <string.h>
#include "get_next_line.h"
int main(void)
{
	char 	*line;
	int		out;
	int		p[2];
	char 	*str;
	int		gnl_ret;

	str = (char *)malloc(1000 * 1000);
	*str = '\0';
	strcat(str, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur in leo dignissim, gravida leo id, imperdiet urna. Aliquam magna nunc, maximus quis eleifend et, scelerisque non dolor. Suspendisse augue augue, tempus");
	strcat(str, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur in leo dignissim, gravida leo id, imperdiet urna. Aliquam magna nunc, maximus quis eleifend et, scelerisque non dolor. Suspendisse augue augue, tempus");
	strcat(str, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur in leo dignissim, gravida leo id, imperdiet urna. Aliquam magna nunc, maximus quis eleifend et, scelerisque non dolor. Suspendisse augue augue, tempus");
	out = dup(1);
	pipe(p);
	dup2(p[1], 1);
	write(1, str, ft_len(str));
	close(p[1]);
	dup2(out, 1);
	gnl_ret = get_next_line(p[0], &line);
	printf("strcmp==%d\n", strcmp(line, str));
	printf("ret==%d", gnl_ret);
	//mt_assert(strcmp(line, str) == 0);
	//mt_assert(gnl_ret == 0 || gnl_ret == 1);
	free(line);
	free(str);
}
