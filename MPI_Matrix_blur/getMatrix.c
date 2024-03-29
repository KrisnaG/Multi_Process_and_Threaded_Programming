/* getMatrix.c  written march 15th  by ian a. mason @ une        */
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "matrix.h"

#define PERMS 0666

int main(int argc, char *argv[]){
    int fd, matrix_size, row, col, slot;
  
    if ((argc != 3) || 
      ((fd = open(argv[1], O_RDONLY)) == -1) ||
      ((matrix_size = atoi(argv[2])) <= 0)) {
        fprintf(stderr,"Usage: %s matrix_file dimension\n", argv[0]);
        exit(1); 
    }
    
    for (row = 1; row <= matrix_size; row++)
        for (col = 1; col <= matrix_size; col++) {
            if (get_slot(fd,matrix_size,row,col,&slot) == -1) {
                fprintf(stderr,"get_slot failed at [%d][%d]\n", row, col);
                exit(-1); 
            };
            fprintf(stdout, "%s[%d][%d] = %d\n", argv[1], row,  col, slot);
        }
   
    fprintf (stdout, "Finished reading  %s\n", argv[1]);
    return 0;
}
