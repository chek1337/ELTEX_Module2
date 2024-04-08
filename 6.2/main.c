#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include"persinfo.h"
#include "list.h"


void Interface()
{
    PhoneList* head = NULL;
    PhoneList* tmpHead = NULL;
    int selectedOption;
    PersonalInformation p;
    for (int statusExit = 0; statusExit == 0; )
    {
        printf("Select a menu option:\n");
        printf("\t1) Add a contact to the database.\n");
        printf("\t2) Redact a contact from the databsase.\n");
        printf("\t3) Delete a contact from the databsase.\n");
        printf("\t4) Output database.\n");
        printf("\t5) Exit.\n");

        scanf("%d", &selectedOption);
        switch (selectedOption)
        {
        case 1:
            p = ReadingData();
            head = AddInList(head, p);
            printf("Contact is added!\n");
            break;
        case 2:
            p = ReadAnthroponym();
            tmpHead = RedactInList(head, p);
            if (tmpHead != NULL)
            {
                head = tmpHead;
                printf("Contact is redacted!\n");
            }
            else
                printf("Contact not found!\n");
               
            break;
        case 3:
            p = ReadAnthroponym();
            tmpHead = DeleteInList(head, p);
            if (tmpHead != NULL)
            {
                head = tmpHead;
                printf("Contact is deleted!\n");
            }
            else
                printf("Contact not found!\n");
            break;
        case 4:
            PrintList(head);
            break;
        case 5:
            statusExit = 1;
            break;
        default:
            printf("Wrong action.\n");
        }
    }
}

void main()
{
    Interface();
}