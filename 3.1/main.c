#include <stdio.h>
#include "extra.h"
#include "subtask1.h"
#include "subtask2.h"
#include "subtask3.h"

int main()
{
    int maskTask1 = -1;
    for (maskTask1; maskTask1 < 0 ;)
    {
        printf("***Введите данные для задания 1***\n");
        maskTask1 = Subtask1();
    }


    int maskTask2 = -1;
    for ( maskTask2; maskTask2 < 0 ;)
    {
        printf("***Введите данные для задания 2***\n");
        maskTask2 = Subtask2();
    }

    for (int statusExit = 0; statusExit != 1 ; )
    {
        printf("***Выбирите для 3 задания поменять права доступа из 1ого или 2ого задания***\n");
        // int choice = getchar();
        char choice[16];
        fgets(choice, sizeof(choice), stdin);
        int maskTask3 = -1;

        switch(choice[0])
        {
            case '1':
                for ( maskTask3; maskTask3 < 0 ;)
                {
                    maskTask3 = Subtask3(maskTask1);
                }
                statusExit = 1;
                break;

            case '2':
                for ( maskTask3; maskTask3 < 0 ;)
                {
                    maskTask3 = Subtask3(maskTask2);
                }
                statusExit = 1;
                break;
            default:
                printf("Неправильный выбор\n");
                break;
        }
    }
    
   

}