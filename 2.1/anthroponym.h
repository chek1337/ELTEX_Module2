#ifndef	ANTHROPONYM
#define ANTHROPONYM
#include <string.h>
typedef struct	Anthroponym {
	char firstName[20];
	char lastName[20];
	char patronymic[20];
} Anthroponym;

void ClearAnthroponym(Anthroponym *anthroponymArg);

#endif