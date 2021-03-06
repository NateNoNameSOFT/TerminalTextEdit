#ifndef FILE_H_
#define FILE_H_

#include <stdio.h>
#include <stdlib.h>
#include <signalhandler.h>
#include <stdbool.h>
#include <string.h>

#define CLEAR "\e[1;1H\e[2J"

#define KEY_ESC 27
#define KEY_BACKSPACE 127

extern FILE *fp;

void file_open(char *filename);

void file_get_text(char *filename);

void file_redraw();

void file_save(char *filename, char *buf);

void file_exit();

#endif