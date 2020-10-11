#include <string.h>
#include <stdlib.h>

int		clear_memory(char **str, char **str_two, int type)
{
	size_t i;

	i = 0;
	if (str && type == 1)
	{
		free(*str);
		*str = NULL;
	}
	while (str_two != 0 && 10241 > i)
	{
		if (str && type == 0)
		{
			free(str[i]);
			str[i] = NULL;
		}
		if (str_two)
		{
			free(str_two[i]);
			str_two[i] = NULL;
		}
		i++;
	}
	return (-1);
}
#include <stdio.h>
int	main(void)
{
	int	i;
	char	*tab[10241];

	i = 0;
	while (10241 > i)
	{
		printf("i=%d\n", i);
		tab[i] = strdup("1");
		i++;
	}
	clear_memory(0, tab, 1);
	return (0);
}
