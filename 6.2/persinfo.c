#include "persinfo.h"

PersonalInformation ReadAnthroponym()
{
    PersonalInformation person;
    char buf[20];

    printf("Enter the last name.\n");
    scanf("%s", &buf);
    strncpy(person.anthroponym.lastName, buf, 20);

    printf("Enter the first name.\n");
    scanf("%s", &buf);
    strncpy(person.anthroponym.firstName, buf, 20);

    printf("Enter the patronymic name.\n");
    scanf("%s", &buf);
    strncpy(person.anthroponym.patronymic, buf, 20);
    return person;
}


PersonalInformation ReadingData()
{
    PersonalInformation p;
    char buf[256];
    int scanfRes;

    printf("Enter the last name.\n");
    scanf("%s", &buf);
    strncpy(p.anthroponym.lastName, buf, 20);

    printf("Enter the first name.\n");
    scanf("%s", &buf);
    strncpy(p.anthroponym.firstName, buf, 20);

    printf("Enter the patronymic name.\n");
    scanf("%s", &buf);
    strncpy(p.anthroponym.patronymic, buf, 20);

    printf("Enter the contact's phone number.\n");
    scanf("%s", &buf);
    strncpy(p.phoneNumber, buf, 11);

    printf("Do you want to enter additional data? (y/n)\n");
    scanf("%s", &buf);
    if (buf[0] == 'y')
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
    }
    else
    {
        memset(p.workingEmail, '\0', 20);
        ClearWork(p.work);
    }

    return p;
}