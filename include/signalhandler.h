#ifndef SIGNALHANDLER_H_
#define SIGNALHANDLER_H_

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <termios.h>
#include <file.h>

extern struct termios oldt;

void handle_exit(int signum);

#endif