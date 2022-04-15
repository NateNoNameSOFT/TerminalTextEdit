#include <stdlib.h>
#include <stdio.h>
#include <file.h>
#include <signalhandler.h>

int main(int argc, char *argv[]){

    printf(CLEAR);

    signal(SIGINT, handle_exit);
    signal(SIGSEGV, handle_exit);

    if(argc == 1 || argc > 2){
        printf("Arguments Provided Are Wrong [USAGE: %s file]\n", argv[0]);

        return EXIT_FAILURE;
    }

    file_open(argv[1]);

    file_get_text(argv[1]);

    return 0;
}