#include "subtask3.h"
#include "extra.h"

int add(int fileMask, int ugoRwxMask)
{
    return (fileMask | ugoRwxMask);
}

int sub(int fileMask, int ugoRwxMask)
{
    return (fileMask & ~(ugoRwxMask));
}

int eq(int fileMask, int ugoRwxMask)
{
    return ugoRwxMask;
}

int UgoParse(char *inputString, int filemask)
{
    int rwxMask = 0b000000000;
    int ugoRwxMask = 0b000000000;
    int flagU = 0, flagG = 0, flagO = 0;
    int flagR = 0, flagW = 0, flagX = 0;
    int operator = -1;
    int (*operations[]) (int, int) = {add, sub, eq};
    for (int i = 0; i < strlen(inputString) - 1; i++)
    {
        // Как оказалось Ubuntu позволяет весьма в свободном формате менять права пользователя
        // Данные примеры являются корретными и робочими (хотя и странными):
        // chmod ogu+rwx <file> ; chmod ugo-xwr <file>; chmod uuugggo-xwr <file>, сhmod ugo-rrwwxxx <file>, chmod ugo+++rwx <file>; 
        // Внимание стоит обратить на случаи вида ugo+-rwx. Здесь по последнему знаку определяется, что делать с правами
        switch (inputString[i])
        {
        case 'u':
            flagU = 1;
            break;
        case 'g':
            flagG = 1;
            break;
        case 'o':
            flagO = 1;
            break;
        case 'r':
            flagR = 1;
            break; 
        case 'w':
            flagW = 1;
            break; 
        case 'x':
            flagX = 1;
            break; 
        case '+':
            operator = 0;
            break; 
        case '-':
            operator = 1;
            break; 
        case '=':
            operator = 2;
            break; 
        default:
            fprintf(stderr, "Incorrect \"ugo\"-format\n");
            return -1;
            break;
        }
    }
    if(operator == -1)
    {
        fprintf(stderr, "The operator is lost\n");
        return -1;
    }
    if(flagU == 0 && flagG == 0 && flagO == 0)
    {
        fprintf(stderr, "Not entered ugo\n");
        return -1;
    }
    if(flagR == 1) rwxMask |= (1 << 2);
    if(flagW == 1) rwxMask |= (1 << 1);
    if(flagX == 1) rwxMask |= 1;

    if(flagU == 1) ugoRwxMask |= rwxMask << 6;
    if(flagG == 1) ugoRwxMask |= rwxMask << 3;
    if(flagO == 1) ugoRwxMask |= rwxMask;

    double res = operations[operator](filemask, ugoRwxMask);
    PrintBits(res);
    printf("\n");
    return res;
}

int NumParse(char *inputString, int filemask)
{
    if (strlen(inputString) > 4)
    {
        fprintf(stderr, "Wrong size\n");
        return -1;
    }

    int rwxMask = 0b000000000;
    int ugoRwxMask = 0b000000000;
    int num = strlen(inputString) - 2;

    for (int i = num; i >= 0; i--)
    {
        int right = inputString[num - i] - '0';
        if(right <= '0' && right >= '7')
        {
            fprintf(stderr, "Wrong character\n");
            return -1;
        }
        rwxMask |= right << (3*i);
    }
    PrintBits(rwxMask);
    printf("\n");

    return rwxMask;
}

int Subtask3(int filemask)
{
    char inputString[16];

    printf("Введите в буквенном или численном формате права доступа\n");
    fgets(inputString, sizeof(inputString), stdin);

    if(CheckNumInput(inputString))
    {
        return NumParse(inputString, filemask);
    }
    else
    {
        return UgoParse(inputString, filemask);
    }
}