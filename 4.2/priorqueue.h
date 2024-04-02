#ifndef PRIORQUEUE_H_
#define PRIORQUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct PriorityQueue
{
    int priority;
    char massage;
    struct PriorityQueue* next;
    struct PriorityQueue* prev;
} PriorityQueue;

PriorityQueue* Push(PriorityQueue* head, PriorityQueue newElemPriority);

PriorityQueue* Top(PriorityQueue* head);

PriorityQueue* PopFromTop(PriorityQueue* head);

PriorityQueue* _PopElement(PriorityQueue* head, PriorityQueue* needToPop);

PriorityQueue* FindCertainPriority(PriorityQueue* head, int elemPriority);

PriorityQueue* FindNotLessPriority(PriorityQueue* head, int elemPriority);

PriorityQueue* PopNotLessPriority(PriorityQueue* head, int elemPriority);

PriorityQueue* PopCertainPriority(PriorityQueue* head, int elemPriority);

void PrintQueue(PriorityQueue* head);

void GenerateMassages(int n);

PriorityQueue* ReadFromFileInQueue(PriorityQueue* head);

#endif