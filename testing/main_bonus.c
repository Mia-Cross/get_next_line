#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
//#include "get_next_line.h"
#include "get_next_line.h"
//#include "gnltestsansbonus.h"
//#include "bonus_iter_gnl.h"

int        main()
{
    int        fd1;
    int        fd2;
    int        fd3;
    int        fd4;
    int        fd5;
    char    *line;
    int ret;

    //fd = 0;
    fd1 = open("test-files/test_file", O_RDONLY);
    fd2 = open("test-files/shorter_testfile", O_RDONLY);
    fd3 = open("test-files/super_short_file_with_nl", O_RDONLY);
    fd4 = open("test-files/super_short_file", O_RDONLY);
    fd5 = open("test-files/file_without_nl", O_RDONLY);

    ret = get_next_line(fd1, &line);
    printf("\n\n = = > GNL : test_file 1 -> line = |%s|\n", line);
    printf(" = = > GNL : test_file -> ret = %d\n\n\n", ret);
    free(line);
    
    ret = get_next_line(fd2, &line);
    printf("\n\n = = > GNL : test_file 2 -> line = |%s|\n", line);
    printf(" = = > GNL : test_file -> ret = %d\n\n\n", ret);
    free(line);
    
    ret = get_next_line(fd3, &line);
    printf("\n\n = = > GNL : test_file 3 -> line = |%s|\n", line);
    printf(" = = > GNL : test_file -> ret = %d\n\n\n", ret);
    free(line);
    
    ret = get_next_line(fd4, &line);
    printf("\n\n = = > GNL : test_file 4 -> line = |%s|\n", line);
    printf(" = = > GNL : test_file -> ret = %d\n\n\n", ret);
    free(line);
    
    ret = get_next_line(fd5, &line);
    printf("\n\n = = > GNL : test_file 5 -> line = |%s|\n", line);
    printf(" = = > GNL : test_file -> ret = %d\n\n\n", ret);
    free(line);
    
    ret = get_next_line(fd1, &line);
    printf("\n\n = = > GNL : test_file 6 -> line = |%s|\n", line);
    printf(" = = > GNL : test_file -> ret = %d\n\n\n", ret);
    free(line);
    
    ret = get_next_line(fd2, &line);
    printf("\n\n = = > GNL : test_file 7 -> line = |%s|\n", line);
    printf(" = = > GNL : test_file -> ret = %d\n\n\n", ret);
    free(line);
    
    ret = get_next_line(fd3, &line);
    printf("\n\n = = > GNL : test_file 8 -> line = |%s|\n", line);
    printf(" = = > GNL : test_file -> ret = %d\n\n\n", ret);
    printf("on essaie de free line = |%s|\n", line);
    free(line);
    
    ret = get_next_line(fd4, &line);
    printf("\n\n = = > GNL : test_file 9 -> line = |%s|\n", line);
    printf(" = = > GNL : test_file -> ret = %d\n\n\n", ret);
//    printf("on essaie de free line = |%s|\n", line);
    free(line);
    
    ret = get_next_line(fd5, &line);
    printf("\n\n = = > GNL : test_file 10 -> line = |%s|\n", line);
    printf(" = = > GNL : test_file -> ret = %d\n\n\n", ret);
    free(line);

    ret = get_next_line(fd1, &line);
    printf("\n\n = = > GNL : test_file 11 -> line = |%s|\n", line);
    printf(" = = > GNL : test_file -> ret = %d\n\n\n", ret);
    free(line);
    ret = get_next_line(fd1, &line);
    printf("\n\n = = > GNL : test_file 12 -> line = |%s|\n", line);
    printf(" = = > GNL : test_file -> ret = %d\n\n\n", ret);
    free(line);
    ret = get_next_line(fd1, &line);
    printf("\n\n = = > GNL : test_file 13 -> line = |%s|\n", line);
    printf(" = = > GNL : test_file -> ret = %d\n\n\n", ret);
    free(line);
    ret = get_next_line(fd1, &line);
    printf("\n\n = = > GNL : test_file 14 -> line = |%s|\n", line);
    printf(" = = > GNL : test_file -> ret = %d\n\n\n", ret);
    free(line);
    ret = get_next_line(fd1, &line);
    printf("\n\n = = > GNL : test_file 15 -> line = |%s|\n", line);
    printf(" = = > GNL : test_file -> ret = %d\n\n\n", ret);
    free(line);
    ret = get_next_line(fd1, &line);
    printf("\n\n = = > GNL : test_file 16 -> line = |%s|\n", line);
    printf(" = = > GNL : test_file -> ret = %d\n\n\n", ret);
    free(line);
    ret = get_next_line(fd1, &line);
    printf("\n\n = = > GNL : test_file 17 -> line = |%s|\n", line);
    printf(" = = > GNL : test_file -> ret = %d\n\n\n", ret);
    free(line);
    ret = get_next_line(fd1, &line);
    printf("\n\n = = > GNL : test_file 18 -> line = |%s|\n", line);
    printf(" = = > GNL : test_file -> ret = %d\n\n\n", ret);
    free(line);
    
    system("leaks a.out");
    return (0);
}
