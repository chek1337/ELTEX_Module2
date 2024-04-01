#include "subtask2.h"
#include "extra.h"

void UgoRights(int ugoMode)
{
    char rwx[] = "---";
    char tmp;
    if(ugoMode & S_IROTH)
        rwx[0] = 'r';

    if(ugoMode & S_IWOTH)
        rwx[1] = 'w';

    if(ugoMode & S_IXOTH)
        rwx[2] = 'x';

    printf("%s", rwx);
}

int OutputAccessRights(unsigned int mode)
{

    unsigned int userRights = (mode & S_IRWXU) >> 6;
    UgoRights(userRights);

    unsigned int groupRights = (mode & S_IRWXG) >> 3; 
    UgoRights(groupRights);

    unsigned int otherRights = mode & S_IRWXO;
    UgoRights(otherRights);

    printf(" %d%d%d ", userRights, groupRights, otherRights);

    double res = mode & (S_IRWXU | S_IRWXG | S_IRWXO);
    PrintBits(res);
    return res;
}

int Subtask2()
{
    struct stat statbuf;
    char inputBuffer[256];
    printf("Введите имя файла\n");
    fgets(inputBuffer, sizeof(inputBuffer), stdin);
    inputBuffer[strlen(inputBuffer)-1] = '\0';

    if (stat(inputBuffer, &statbuf)) {
        printf("The file does not exist\n");
        return -1;
    }

    double res = OutputAccessRights(statbuf.st_mode);
    printf(" %s\n", inputBuffer);
    return res;
}