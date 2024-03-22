#include "work.h"

void ClearWork(Work *work_arg)
{
    memset(work_arg->workName, ' ', 20); 
	memset(work_arg->workingPosition, ' ', 20);
}
