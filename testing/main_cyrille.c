#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int			main()
{
	int         fd;
	int         rtn;
	int         fd2;
	int         rtn2;
	int         fd3;
	int         rtn3;
	int			i = 4;
	char        **line;
	if (!(line = malloc(sizeof(char*) * 10)))
		return (0);
	fd = open("test.txt", O_RDWR);
	fd2 = open("test2.txt", O_RDWR);
	fd3 = open("test3.txt", O_RDWR);
	if (fd == -1)
		return (0);
	if (fd2 == -1)
		return (0);
	if (fd3 == -1)
		return (0);
	rtn = 1;
	rtn2 = 1;
	rtn3 = 1;
	while (rtn != 0)
	{
		rtn = get_next_line(fd, line);
		printf("-%s\n", line[0]);
		while (rtn2 != 0)
		{
			rtn2 = get_next_line(fd2, line);
			printf("-%s\n", line[0]);
			while (i-- > 0)
			{
				rtn3 = get_next_line(fd3, line);
				printf("-%s\n", line[0]);
			}
		}
	}
	while (rtn3 != 0)
	{
		rtn3 = get_next_line(fd3, line);
		printf("-%s\n", line[0]);
	}
	return (0);
}
