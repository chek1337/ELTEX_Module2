#include "priorqueue.h"

/*Производит добавление элемента в очередь*/
/*Возвращает указатель на голову*/
PriorityQueue* Push(PriorityQueue* head, PriorityQueue newElemPriority)
{
    PriorityQueue* pTmp = (PriorityQueue*) malloc(sizeof(PriorityQueue));

    pTmp->massage = newElemPriority.massage;
    pTmp->priority = newElemPriority.priority;
    pTmp->next = NULL;
    pTmp->prev = NULL;

    if (head == NULL)
    {
        head = pTmp;
        return head;
    }

    PriorityQueue* curElem = head;
    PriorityQueue* prevElem = head->prev;

    for (; curElem != NULL; )
    {
        if (newElemPriority.priority < curElem->priority)
        {
            if (head == curElem)
            {
                pTmp->next = curElem;
                curElem->prev = pTmp;
                head = pTmp;
                return head;
            }
            else
            {
                pTmp->next = curElem;
                pTmp->prev = prevElem;
                curElem->prev = pTmp;
                prevElem->next = pTmp;
                return head;
            }
        }
        prevElem = curElem;
        curElem = curElem->next;
    }

    prevElem->next = pTmp;
    pTmp->prev = prevElem;
    return head;
}

/*Возвращает указатель на голову*/
PriorityQueue* Top(PriorityQueue* head)
{
    return head;
}

/*Убирает элемент из начала очереди*/
/*Если удалось найти и убрать элемент, возвращает указатель на голову*/
/*иначе возвращает NULL*/
PriorityQueue* PopFromTop(PriorityQueue* head)
{
    return _PopElement(head, head);   
}

/*Убирает элемент из очереди по указателю*/
/*Если удалось найти и убрать элемент, возвращает указатель на голову*/
/*иначе возвращает NULL*/
PriorityQueue* _PopElement(PriorityQueue* head, PriorityQueue* needToPop)
{
    if (needToPop != NULL)
    {
        if (head == needToPop)
        {
            head = head->next;
            head->prev = NULL;
            free(needToPop);
            return head;
        }
        else
        {
            if (needToPop->next != NULL)
            {
                needToPop->prev->next = needToPop->next;
                needToPop->next->prev = needToPop->prev;
                free(needToPop);
                return head;
            }
            else
            {
                needToPop->prev->next = NULL;
                free(needToPop->prev->next);
                return head;
            }

        }
    }
    return NULL;
}

/*Находит указатель на элемент с необходимым приоритет*/
/*Если удалось найти, возвращает указатель на найденный элемент*/
/*иначе возвращает NULL*/
PriorityQueue* FindCertainPriority(PriorityQueue* head, int elemPriority)
{
    PriorityQueue* curElem = head;
    for (; curElem != NULL; )
    {
        if (elemPriority <= curElem->priority)
        {
            if (elemPriority == curElem->priority)
            {
                return curElem;
            }
            else
            {
                return NULL;
            }
        }
        curElem = curElem->next;
    }
    return NULL;
}

/*Находит указатель на элемент с минимальным приоритет*/
/*Если удалось найти, возвращает указатель на найденный элемент*/
/*иначе возвращает NULL*/
PriorityQueue* FindNotLessPriority(PriorityQueue* head, int elemPriority)
{
    PriorityQueue* curElem = head;
    for (; curElem != NULL; )
    {
        if (elemPriority <= curElem->priority)
        {
            return curElem;
        }
        curElem = curElem->next;
    }
    return NULL;
}

/*Убирает элемент из очереди с не менее чем указанный приоритет*/
/*Если удалось найти и убрать элемент, возвращает указатель на голову*/
/*иначе возвращает NULL*/
PriorityQueue* PopNotLessPriority(PriorityQueue* head, int elemPriority)
{
    PriorityQueue* needToPop = FindNotLessPriority(head, elemPriority);
    if (needToPop != NULL)
        return _PopElement(head, needToPop);
    return NULL;
}

/*Убирает элемент из очереди с указанным приоритетом*/
/*Если удалось найти и убрать элемент, возвращает указатель на голову*/
/*иначе возвращает NULL*/
PriorityQueue* PopCertainPriority(PriorityQueue* head, int elemPriority)
{
    PriorityQueue* needToPop = FindCertainPriority(head, elemPriority);
    if(needToPop != NULL)
        return _PopElement(head, needToPop);
    return NULL;
}

/*Выводит содержисое очереди*/
void PrintQueue(PriorityQueue* head)
{
    PriorityQueue* curElem = head;
    for (int i = 1;  curElem != NULL; i++)
    {
        printf("#%d Massage: %c Priority: %d\n", i, curElem->massage, curElem->priority);
        curElem = curElem->next;
    }
    printf("\n");
}

/*Производит генерацию "сообщений" в формате "<буква> <приоритет>"*/
void GenerateMassages(int n)
{
    FILE* massageFile = fopen("msg.txt", "w");

    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        fprintf(massageFile, "%c ", (char)(rand() % 25 + 65));
        fprintf(massageFile, "%d\n", rand() % 256);
    }
    fclose(massageFile);
}

/*Производит считывание "сообщений" в формате "<буква> <приоритет>"*/
/*Возвращает указатель на голову*/
PriorityQueue* ReadFromFileInQueue(PriorityQueue* head)
{
    FILE* massageFile = fopen("msg.txt", "r");
    int pri;
    char msg;
    char trsh;
    if (!massageFile)
       exit(1);

    PriorityQueue q;
    int endFile;
    endFile = fscanf(massageFile, "%c", &msg);
    endFile = fscanf(massageFile, "%d", &pri);
    endFile = fscanf(massageFile, "%c", &trsh);
    for (; endFile != EOF ;)
    {
        q.massage = msg;
        q.priority = pri;
        head = Push(head, q);
        endFile = fscanf(massageFile, "%c", &msg);
        endFile = fscanf(massageFile, "%d", &pri);
        endFile = fscanf(massageFile, "%c", &trsh);
    }
    fclose(massageFile);
    return head;
}
