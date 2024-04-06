#ifndef BTREE_H_
#define BTREE_H_
#include <stdio.h>
#include <stdlib.h>
#include "persinfo.h"

typedef struct Btree
{
    PersonalInformation person;
    struct Btree* left;
    struct Btree* right;
} Btree;

Btree* AddInBtree(Btree* head, PersonalInformation newPerson);

int FullAnthroponymCompare(PersonalInformation  findPerson, PersonalInformation  curContact);

Btree* FindInBtree(Btree* head, PersonalInformation findPerson);

Btree* FindRootToNode(Btree* head, PersonalInformation findPerson);

int LeftOrRightListForRoot(Btree* root,  PersonalInformation list);

Btree* DeleteInBtree(Btree* head, PersonalInformation deletePerson);

void PrintBtree(Btree *elemBtree);

#endif