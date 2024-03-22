#ifndef WORK_H
#define WORK_H
#include <string.h>
typedef struct Work {
	char workName[20];
	char workingPosition[20];
} Work;

void ClearWork(Work *work_arg);
#endif
