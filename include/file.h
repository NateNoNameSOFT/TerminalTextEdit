#ifndef FILE_H_
#define FILE_H_

#include <stdio.h>
#include <stdlib.h>
#include <signalhandler.h>
#include <stdbool.h>
#include <string.h>

extern FILE *fp;

void file_open(char *filename);

void file_get_text(char *filename);

void file_redraw();

void file_save(char *filename, char *buf);

void file_exit();

#endif