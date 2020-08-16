					#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
//#include "get_next_line.h"
//#include "iterative_gnl.h"
#include "get_next_line.h"
//#include "gnltestsansbonus.h"

//int        main(void)
int        main(int argc, char **argv)
{
    int        fd;
    char    *line;
    int        i;
    int ret;

    i = 0;
    //fd = 0;
    if (argc == 2)
        fd = open((argv[1]), O_RDONLY);
    else
        fd = 0;
    while ((ret = get_next_line(fd, &line)))
    {
        printf("\n\n = = = = = > GNL : line = |%s|\n", line);
        printf(" = = = = = > GNL : ret = %d\n\n\n", ret);
        free(line);
    }
    if (ret == 0)
    {
        printf("\n\n = = = = = > GNL : line = |%s|\n", line);
        printf(" = = = = = > GNL : ret = %d\n\n\n", ret);
        free(line);
    }
       system("leaks a.out");
    close(fd);
    return (0);
}
