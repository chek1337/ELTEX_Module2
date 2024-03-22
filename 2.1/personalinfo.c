#include "personalinfo.h"

#define TABLESIZE 20
void ClientInterface()
{
	PersonalInformation dataBase[TABLESIZE];
	InitializingTable(&dataBase);
	int selectedOption;
	// memset(dataBase, ' ', sizeof(dataBase));
	for ( int statusExit = 0; statusExit == 0; )
	{
		printf("Select a menu option:\n");
		printf("\t1) Add a contact to the database.\n");
		printf("\t2) Redact a contact from the databsase.\n");
		printf("\t3) Delete a contact from the databsase.\n");
		printf("\t4) Output database.\n");
		
		scanf("%d", &selectedOption);
		switch(selectedOption)
		{
			case 1:
				PersonalInformation p;
				p = ReadingData();
				AddIntable(dataBase, p);
				break;
			case 2:
				RedactTable(dataBase);
				break;
			case 3:
				DeleteInTable(dataBase);
				break;
			case 4:
				OutputTable(dataBase);
				break;
			default:
				printf("Wrong action.\n");
		}
	}
}

void ClearContact(PersonalInformation *person)
{
    ClearAnthroponym(&person->anthroponym);
    ClearWork(&person->work);
    ClearSocialNetwork(&person->socialNetwork);
    memset(person->phoneNumber, ' ', 12);
    memset(person->workingEmail, ' ', 20); 
}

Anthroponym ReadAnthroponym()
{
	Anthroponym anthroponym;
	char buf[20];
	printf("Enter the first name.\n");
    scanf("%s", &buf);
	strncpy(anthroponym.firstName, buf, 20);

	printf("Enter the last name.\n");
    scanf("%s", &buf);
	strncpy(anthroponym.lastName, buf, 20);

	printf("Enter the patronymic name.\n");
    scanf("%s", &buf);
	strncpy(anthroponym.patronymic, buf, 20);
	return anthroponym;
}

void DeleteInTable(PersonalInformation *dataBase)
{
	Anthroponym anthroponym = ReadAnthroponym();
	char buf[256];
	int scanfRes, scanfOption;

	int posInTable = FindInTableByAnthroponym(dataBase, anthroponym);
	if(posInTable != -1)
	{
		ClearContact(&dataBase[posInTable]);
		printf("Contact deleted!\n");
	}
	else
		printf("Unknown contact!\n");
}

int FindInTableByAnthroponym(PersonalInformation *dataBase, Anthroponym person)
{
	for (int i = 0; i < TABLESIZE; i++)
	{
		if(strncmp(person.firstName, dataBase[i].anthroponym.firstName, 20) == 0)
		{
			if(strncmp(person.patronymic, dataBase[i].anthroponym.patronymic, 20) == 0)
			{
				if(strncmp(person.patronymic, dataBase[i].anthroponym.patronymic, 20) == 0 )
				{
					return i;
				}		
			}
		}
	}
	return -1;
}

void RedactTable(PersonalInformation *dataBase)
{
	Anthroponym anthroponym = ReadAnthroponym();
	char buf[256];
	int scanfOption;

	int posInTable = FindInTableByAnthroponym(dataBase, anthroponym);
	if(posInTable != -1)
	{
		printf("What do you want to change?\n");
		printf("1) Phone Number\n"); 
		scanf("%d", &scanfOption);
		switch (scanfOption)
		{
		case 1:
			printf("Enter a new phone number.\n");
			scanf("%s", &buf);
			strncpy(dataBase[posInTable].phoneNumber, buf, 11);
			break;

		default:
			printf("Wrong action!\n");
			break;
		}
	}
	else
		printf("Unknown contact!\n");
}
void OutputTable(PersonalInformation dataBase[])
{
	for (int i = 0; i < TABLESIZE; i++)
	{
		if(dataBase[i].anthroponym.firstName[0] != ' ')
		{
			printf("| %s %s %s |", dataBase[i].anthroponym.firstName, dataBase[i].anthroponym.patronymic);
			printf(" %s |\n", dataBase[i].phoneNumber);
		}	
	}
}

void InitializingTable(PersonalInformation *dataBase)
{
	for (int i = 0; i < TABLESIZE; i++)
	{
		ClearContact(&dataBase[i]);
	}
}

void AddIntable(PersonalInformation *dataBase, PersonalInformation personalInf)
{
	int statusExit = -1;
	for (int i = 0; i < TABLESIZE && statusExit == -1; i++)
	{
		if(dataBase[i].anthroponym.firstName[0] == ' ')
		{
			printf("Место в таблице %d\n", i);
			strncpy(dataBase[i].anthroponym.firstName, personalInf.anthroponym.firstName, 20);
			strncpy(dataBase[i].anthroponym.lastName, personalInf.anthroponym.lastName, 20); 
			strncpy(dataBase[i].anthroponym.patronymic, personalInf.anthroponym.patronymic, 20); 
			strncpy(dataBase[i].phoneNumber, personalInf.phoneNumber, 12); 
			strncpy(dataBase[i].workingEmail, personalInf.workingEmail, 20); 
			strncpy(dataBase[i].work.workName, personalInf.work.workName, 20); 
			strncpy(dataBase[i].work.workingPosition, personalInf.work.workingPosition, 20);
			strncpy(dataBase[i].socialNetwork.VKlink, personalInf.socialNetwork.VKlink, 20);
			strncpy(dataBase[i].socialNetwork.TGlink, personalInf.socialNetwork.TGlink, 20);
			statusExit = 1;
			printf("The contact has been added to the table.\n");
		}
	}
	if(statusExit == -1)
		printf("There is no place for a new contact in the table.\n");
}

struct PersonalInformation ReadingData()
{
	PersonalInformation p;
	char buf[256];
	int scanfRes;

	printf("Enter the first name.\n");
    scanf("%s", &buf);
	strncpy(p.anthroponym.firstName, buf, 20);

	printf("Enter the last name.\n");
    scanf("%s", &buf);
	strncpy(p.anthroponym.lastName, buf, 20);

	printf("Enter the patronymic name.\n");
    scanf("%s", &buf);
	strncpy(p.anthroponym.patronymic, buf, 20);

	printf("Enter the contact's phone number.\n");
	scanf("%s", &buf);
	strncpy(p.phoneNumber, buf, 11);

	printf("Do you want to enter additional data? (y/n)\n");
	scanf("%s", &buf);
	if( buf[0] == 'y' )
	{
		printf("Enter the contact's work email.\n");
		scanf("%s", &buf);
		strncpy(p.workingEmail, buf, 20);

		printf("Enter your place of work.\n");
		scanf("%s", &buf);
		strncpy(p.work.workName, buf, 20);

		printf("Enter a position at work.\n");
		scanf("%s", &buf);
		strncpy(p.work.workingPosition, buf, 20);

		printf("Enter the link to the VK profile at work.\n");
		scanf("%s", &buf);
		strncpy(p.socialNetwork.VKlink, buf, 20);

		printf("Enter the link to the telegram profile at work.\n");
		scanf("%s", &buf);
		strncpy(p.socialNetwork.TGlink, buf, 20);
	}
	return p;
}