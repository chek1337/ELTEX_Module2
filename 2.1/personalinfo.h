#ifndef PERSONALINFO_H
#define PERSONALINFO_H

#include "work.h"
#include "anthroponym.h"
#include "socialnet.h"
#include <stdio.h>

typedef struct PersonalInformation {
	Anthroponym anthroponym;
	Work work;
	SocialNetwork socialNetwork;
	char workingEmail[20];
	char phoneNumber[12];
} PersonalInformation;

void ClientInterface();
PersonalInformation ReadingData();
void AddIntable(PersonalInformation *dataBase, PersonalInformation person);
void InitializingTable(PersonalInformation *dataBase);
void OutputTable(PersonalInformation *dataBase);
int FindInTableByAnthroponym(PersonalInformation *dataBase, Anthroponym person);
void RedactTable(PersonalInformation *dataBase);
void DeleteInTable(PersonalInformation *dataBase);
void ClearContact(PersonalInformation *person);
Anthroponym ReadAnthroponym();
#endif