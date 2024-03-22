#include "anthroponym.h"

void ClearAnthroponym(Anthroponym *anthroponymArg)
{
	memset(anthroponymArg->firstName, ' ', 20);
	memset(anthroponymArg->lastName, ' ', 20);
    memset(anthroponymArg->patronymic, ' ', 20);
}