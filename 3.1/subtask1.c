#include "subtask1.h"
#include "extra.h"

int CalcBitRepresChar(char *stringRights)
{
    int res = 0b000000000;

    for (int i = 8; i >= 0; i--)
    {
        if (stringRights[8-i] == 'r' && i % 3 == 2)
        {
            res = res | (1 << i);
        } 
        else if(stringRights[8-i] == 'w' && i % 3 == 1)
        {
            res = res | (1 << i);
        }
        else if(stringRights[8-i] == 'x' && i % 3 == 0)
        {
            res = res | (1 << i);
        }
        else if (stringRights[8-i] == '-')
        {
            continue;
        }
        else
        {
            fprintf(stderr, "Incorrect character\n");
            return -1;
        }
    }

    PrintBits(res);
    printf("\n");
    return res;
}

int CalcBitRepresNum(char *stringRights)
{
    int numRightsU = (stringRights[0] - '0') << 6;
    int numRightsG = (stringRights[1] - '0') << 3;
    int numRightsO = stringRights[2] - '0';

    int res = numRightsU | numRightsG | numRightsO;
    PrintBits(res);
    printf("\n");
    return res;
}

int Subtask1()
{
    char stringRights[16];

    printf("Введите права доступа в символьном или численном формате:\n");
    fgets(stringRights, sizeof(stringRights), stdin);

    if(CheckNumInput(stringRights))
    {
        if(strlen(stringRights) != 4)
        {
            fprintf(stderr, "Incorrect size of input\n");
            return -1;
        }
        return CalcBitRepresNum(stringRights);
    }
    else
    {
        if(strlen(stringRights) != 10)
        {
            fprintf(stderr, "Incorrect size of input\n");
            return -1;
        }
        return CalcBitRepresChar(stringRights);
    }
}