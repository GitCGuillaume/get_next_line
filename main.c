#include <fcntl.h>
#include <stdio.h>
int		ft_open_fd(void)
{
	int fd;
	fd = open("42", O_RDONLY || S_IRUSR);
	if (fd == -1)
	{
		printf("L'ouverture n'a pu se faire, vérifier si fichier existe ou les droits");
		return (fd);
	}
}

int		ft_close_fd(int fd)
{
	if (close(fd) == -1)
	{
		printf("La fermeture a raté.");
		return (1);
	}
}

int main()
