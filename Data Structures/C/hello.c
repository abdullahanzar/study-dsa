#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv) {
    printf("Hello Wordld - %d \n", argc);

     char* a[] = {"hvbjh"};
        printf("%X\n", a);
        printf("%X", &a);

    for(int i=0; i<=argc; i++) {
        // atoi - ascii to int 
        // atof - ascii to float
        //printf("arg %d - %s\n", i, argv[i]);
        //printf("arg %d - %s, %i, %f\n", i, argv[i], atoi(argv[i]), atof(argv[i]));
        //system("pause");

       
    }
}