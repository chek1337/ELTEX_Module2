#include "work.h"
#include <string.h>

void ClearWork(Work* work_arg)
{
	memset(work_arg->workName, '\0', 20);
	memset(work_arg->workingPosition, '\0', 20);
}

