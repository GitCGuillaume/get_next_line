#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void) {
	int fd = open("logo.txt", O_RDONLY);
	char *line = 0;

	for (int i = 0; i < 34; i++) {
		get_next_line(fd, &line);
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}
