#include "extra.h"

void PrintBits(int val) 
{
  for (int i = 8; i >= 0; i--) {
    printf("%c", (val & (1 << i)) ? '1' : '0');
  }
}

int CheckNumInput(char *stringRights)
{
    if(stringRights[0] >= '0' &&  stringRights[0] <= '7')
    {
        if(stringRights[1] >= '0' &&  stringRights[1] <= '7')
        {
            if(stringRights[2] >= '0' &&  stringRights[2] <= '7')
                return 1;
        }
    }
    return 0;
}
