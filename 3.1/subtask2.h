#ifndef SUBTASK2_H_
#define SUBTASK2_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define bit_read 0b100
#define bit_write 0b010
#define bit_execute 0b001

void UgoRights(int ugoMode);
int OutputAccessRights(unsigned int mode);
int Subtask2();

#endif