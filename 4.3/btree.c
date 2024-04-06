#include "btree.h"
#include "anthroponym.h"

Btree* AddInBtree(Btree* head, PersonalInformation newPerson)
{
    Btree* pTmp = (Btree*)malloc(sizeof(Btree));

    pTmp->left = NULL;
    pTmp->right = NULL;

    pTmp->person.anthroponym.firstName;
    strncpy(pTmp->person.anthroponym.firstName, newPerson.anthroponym.firstName, 20);
    strncpy(pTmp->person.anthroponym.lastName, newPerson.anthroponym.lastName, 20);
    strncpy(pTmp->person.anthroponym.patronymic, newPerson.anthroponym.patronymic, 20);
    strncpy(pTmp->person.phoneNumber, newPerson.phoneNumber, 12);
    strncpy(pTmp->person.workingEmail, newPerson.workingEmail, 20);
    strncpy(pTmp->person.work.workName, newPerson.work.workName, 20);
    strncpy(pTmp->person.work.workingPosition, newPerson.work.workingPosition, 20);

    if (head == NULL)
    {
        head = pTmp;
        return head;
    }

    Btree* curElem = head;

    for (; curElem != NULL; )
    {
        if (LastnameComparer(pTmp->person.anthroponym, curElem->person.anthroponym))
        {
            if(curElem->left == NULL)
            {
                curElem->left = pTmp;
                return head;
            }
            curElem = curElem->left;     
        }
        else
        {
            if(curElem->right == NULL)
            {
                curElem->right = pTmp;
                return head;
            }
            curElem = curElem->right;   
        }
    }
    fprintf(stderr, "Какой-то трабл");
    return NULL;
}

void PrintBtree(Btree *elemBtree) 
{
    if (elemBtree == NULL) 
        return;
    PrintBtree(elemBtree->left);

    printf("Name: %s %s %s ", elemBtree->person.anthroponym.lastName, elemBtree->person.anthroponym.firstName, elemBtree->person.anthroponym.patronymic);
    printf("Phone Number: %s\n", elemBtree->person.phoneNumber);

    PrintBtree(elemBtree->right);
}

int FullAnthroponymCompare(PersonalInformation  findPerson, PersonalInformation  curContact)
{
    if (strcmp(findPerson.anthroponym.lastName, curContact.anthroponym.lastName) == 0)
            if (strcmp(findPerson.anthroponym.firstName, curContact.anthroponym.firstName) == 0)
                if (strcmp(findPerson.anthroponym.patronymic, curContact.anthroponym.patronymic) == 0)
                    return 1;
    return -1;
}

Btree* FindInBtree(Btree* head, PersonalInformation findPerson)
{
    Btree* curContact = head;
    for (; curContact != NULL; )
    {
        if(FullAnthroponymCompare(findPerson ,curContact->person) == 1)
            return curContact;
        
        if(LastnameComparer(findPerson.anthroponym, curContact->person.anthroponym))
            curContact = curContact->left;
        else    
            curContact = curContact->right;
    }
    return NULL;
}


Btree* FindRootToNode(Btree* head, PersonalInformation findPerson)
{
    Btree* curContact = head;
    Btree* prevContact = head;
    for (; curContact != NULL; )
    {
        if (strcmp(findPerson.anthroponym.lastName, curContact->person.anthroponym.lastName) == 0)
            if (strcmp(findPerson.anthroponym.firstName, curContact->person.anthroponym.firstName) == 0)
                if (strcmp(findPerson.anthroponym.patronymic, curContact->person.anthroponym.patronymic) == 0)
                    return prevContact;
        
        if(LastnameComparer(findPerson.anthroponym, curContact->person.anthroponym))
        {
            prevContact = curContact;
            curContact = curContact->left;
        }
        else
        {
            prevContact = curContact;
            curContact = curContact->right;
        }    
            
    }
    return NULL;
}

int LeftOrRightListForRoot(Btree* root,  PersonalInformation list)
{
    if(root->left != NULL && FullAnthroponymCompare(root->left->person, list))
    {
        // left
        return 0;
    }
    else if(root->right != NULL && FullAnthroponymCompare(root->right->person, list))
    {
        // right
        return 1;
    }
    return -1;
}

Btree* DeleteInBtree(Btree* head, PersonalInformation deletePerson)
{
    Btree* pDeletePerson = FindInBtree(head, deletePerson);
    Btree* rootToDeletePerson;
    if(pDeletePerson == NULL)
        return NULL;
    
    if(pDeletePerson->left == NULL && pDeletePerson->right == NULL) // лист
    {
        rootToDeletePerson = FindRootToNode(head, deletePerson);
        int leftOrRight = LeftOrRightListForRoot(rootToDeletePerson, deletePerson);
        if(leftOrRight == 0) //left
        {
            rootToDeletePerson->left = NULL;
        }
        else if(leftOrRight == 1) //right
        {
            rootToDeletePerson->right = NULL;
        }
        else
        {
            fprintf(stderr, "err\n");
            return NULL;
        }
        free(pDeletePerson);
        return head;
    }
    else if(pDeletePerson->left == NULL) // есть только правый лист
    {
        rootToDeletePerson = FindRootToNode(head, deletePerson);
        int leftOrRight = LeftOrRightListForRoot(rootToDeletePerson, deletePerson);
        if(leftOrRight == 0) //left
        {
            rootToDeletePerson->left = rootToDeletePerson->right;
        }
        else if(leftOrRight == 1) //right
        {
            rootToDeletePerson->right = rootToDeletePerson->right;
        }

        free(pDeletePerson);
        return head;
    }
    else if(pDeletePerson->right == NULL) // есть только левый лист
    {
        rootToDeletePerson = FindRootToNode(head, deletePerson);
        int leftOrRight = LeftOrRightListForRoot(rootToDeletePerson, deletePerson);
        if(leftOrRight == 0) //left
        {
            rootToDeletePerson->left = rootToDeletePerson->left;
        }
        else if(leftOrRight == 1) //right
        {
            rootToDeletePerson->right = rootToDeletePerson->left;
        }
        free(pDeletePerson);
        return head;
    }
    else if(pDeletePerson->left != NULL && pDeletePerson->right != NULL)
    {
        Btree* root = pDeletePerson;
        Btree* curElem = pDeletePerson->left;
        for (; curElem->right != NULL ; )
        {
            root = curElem;
            curElem = curElem->right;
        }
        if(root == pDeletePerson)
        {
            rootToDeletePerson = FindRootToNode(head, pDeletePerson->person);
            int leftOrRight = LeftOrRightListForRoot(rootToDeletePerson, pDeletePerson->person);
            if(leftOrRight == 0)
            {
                rootToDeletePerson->left = curElem;
            }
            else if(leftOrRight == 1)
            {
                rootToDeletePerson->right = curElem;
            }
            curElem->right = root->right;
        }
        else
        {
            root->right = NULL;
            curElem->left = pDeletePerson->left;
            curElem->right = pDeletePerson->right;
        }
        
        
        if(head == pDeletePerson)
            head = curElem;
        free(pDeletePerson);
        return head;
    }
    return NULL;
}
