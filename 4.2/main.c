#include "priorqueue.h"

int main()
{
    PriorityQueue* head = NULL;

    GenerateMassages(20);

    head = ReadFromFileInQueue(head);

    PrintQueue(head);
}