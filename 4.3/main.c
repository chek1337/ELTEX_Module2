#include "persinfo.h"
#include "btree.h"

void Interface()
{
    Btree* head = NULL;
    Btree* tmpHead = NULL;
    int selectedOption;
    PersonalInformation p;
    for (int statusExit = 0; statusExit == 0; )
    {
        printf("Select a menu option:\n");
        printf("\t1) Add a contact to the database.\n");
        printf("\t2) Delete a contact from the databsase.\n");
        printf("\t3) Output database.\n");
        printf("\t4) Exit.\n");

        scanf("%d", &selectedOption);
        switch (selectedOption)
        {
        case 1:
            p = ReadingData();
            head = AddInBtree(head, p);
            printf("Contact is added!\n");
            break;
        case 2:
            p = ReadAnthroponym();
            tmpHead = DeleteInBtree(head, p);
            if (tmpHead != NULL)
            {
                head = tmpHead;
                printf("Contact is deleted!\n");
            }
            else
                printf("Contact not found!\n");
            break;
        case 3:
            PrintBtree(head);
            break;
        case 4:
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

// int main()
// {
//     Btree* head = NULL;
//     PersonalInformation Loych;
//     strncpy(Loych.anthroponym.firstName, "Danila", 20);
//     strncpy(Loych.anthroponym.lastName, "8", 20);
//     strncpy(Loych.anthroponym.patronymic, "Ser", 20);
//     strncpy(Loych.phoneNumber, "279175297", 12);
//     head = AddInBtree(head, Loych);

//     PersonalInformation Ovch;
//     strncpy(Ovch.anthroponym.firstName, "Ivan", 20);
//     strncpy(Ovch.anthroponym.lastName, "3", 20);
//     strncpy(Ovch.anthroponym.patronymic, "Rom", 20);
//     strncpy(Ovch.phoneNumber, "30i61936", 12);
//     head = AddInBtree(head, Ovch);

//     PersonalInformation Kazanshi;
//     strncpy(Kazanshi.anthroponym.firstName, "Zlata", 20);
//     strncpy(Kazanshi.anthroponym.lastName, "9", 20);
//     strncpy(Kazanshi.anthroponym.patronymic, "Dmit", 20);
//     strncpy(Kazanshi.phoneNumber, "692072313", 12);
//     head = AddInBtree(head, Kazanshi);

//     PersonalInformation Kusakin;
//     strncpy(Kusakin.anthroponym.firstName, "Alex", 20);
//     strncpy(Kusakin.anthroponym.lastName, "1", 20);
//     strncpy(Kusakin.anthroponym.patronymic, "Oleg", 20);
//     strncpy(Kusakin.phoneNumber, "963109713", 12);
//     head = AddInBtree(head, Kusakin);

//     PersonalInformation Danilov;
//     strncpy(Danilov.anthroponym.firstName, "Yur", 20);
//     strncpy(Danilov.anthroponym.lastName, "6", 20);
//     strncpy(Danilov.anthroponym.patronymic, "Pavlov", 20);
//     strncpy(Danilov.phoneNumber, "583862896", 12);
//     head = AddInBtree(head, Danilov);

//     PrintBtree(head);
//     Btree* test = NULL;
//     // test = FindRootToNode(head, Danilov);
//     test = DeleteInBtree(head, Ovch);
//     printf("\n");
//     PrintBtree(test);
// }
