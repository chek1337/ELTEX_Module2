#ifndef SUBTASK3_H_
#define SUBTASK3_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int add(int fileMask, int ugoRwxMask);
int sub(int fileMask, int ugoRwxMask);
int eq(int fileMask, int ugoRwxMask);
int UgoParse(char *inputString,  int filemask);
int NumParse(char *inputString,  int filemask);
int Subtask3(int filemask);

#endif