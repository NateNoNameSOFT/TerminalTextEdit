#include <signalhandler.h>

struct termios oldt;

void handle_exit(int signum){
    if(signum == SIGINT)
        printf("Recived Ctrl+C, Saving and Exiting...\n");
    if(signum == SIGSEGV)
        printf("Recived Segmentation Fault, Saving and Exiting...\n");

    file_exit();
}