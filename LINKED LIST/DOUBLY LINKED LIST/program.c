#include <stdio.h>
#include <stdlib.h>
struct linkedList
{
    int data;
    struct linkedList *next;
    struct linkedList *prev;
};

void printListForword(struct linkedList *temp)
{
    int i = 1;
    do
    {
        printf("%d->", temp->data);
        temp = temp->next;
        i++;
    } while (temp != NULL);
    printf("NULL \n");
}
void printListBackword(struct linkedList *temp)
{
    int i = 1;
    while (temp->next != NULL)
    {
        temp = temp->next;
        i++;
    }
    printf("\t\t\t\tNULL<-");
    while (i >= 1)
    {
        printf("%d<-", temp->data);
        temp = temp->prev;
        i--;
    }
    printf("NULL\n");
}

int middleCounter(struct linkedList *temp)
{
    int i = 1;

    while (temp != NULL)
    {
        temp = temp->next;
        i++;
    }

    return i / 2;
}

struct linkedList *insertList(struct linkedList *temp, int data)
{
    struct linkedList *newNode;
    newNode = (struct linkedList *)malloc(sizeof(struct linkedList));
    newNode->data = data;
    newNode->next = temp;
    temp->prev = newNode;
    return newNode;
}

struct linkedList *insertListAtLast(struct linkedList *temp, int data)
{
    struct linkedList *newNode;
    struct linkedList *ptr;
    ptr = temp;

    newNode = (struct linkedList *)malloc(sizeof(struct linkedList));
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    newNode->data = data;
    ptr->next = newNode;
    newNode->prev = ptr;
    newNode->next = NULL;
    return temp;
}

struct linkedList *insertListAtMiddle(struct linkedList *temp, int data)
{
    int middleIndex = middleCounter(temp);
    struct linkedList *newNode;
    struct linkedList *ptr;
    struct linkedList *ptr2;
    ptr2 = temp->next;
    ptr = temp;
    int i = 0;
    while (i < middleIndex - 1)
    {
        ptr = ptr->next;
        ptr2 = ptr2->next;
        i++;
    }
    newNode = (struct linkedList *)malloc(sizeof(struct linkedList));
    newNode->data = data;
    newNode->next = ptr->next;
    ptr2->prev = newNode;
    ptr->next = newNode;
    newNode->prev = ptr;
    return temp;
}

struct linkedList *deleteList(struct linkedList *temp)
{
    temp = temp->next;
    return temp;
}

struct linkedList *deleteListAtEnd(struct linkedList *temp)
{
    struct linkedList *ptr;
    ptr = temp;
    struct linkedList *ptr2;
    ptr2 = temp->next;
    while (ptr2->next != NULL)
    {
        ptr2 = ptr2->next;
        ptr = ptr->next;
    }
    ptr->next = NULL;
    return temp;
}

struct linkedList *deleteListAtMiddle(struct linkedList *temp)
{
    struct linkedList *ptr;
    ptr = temp;
    struct linkedList *ptr2;
    ptr2 = temp->next;
    int middleIndex = 2;

    int i = 0;
    while (i < middleIndex - 1)
    {
        ptr = ptr->next;
        ptr2 = ptr2->next;
        i++;
    }
    ptr->next = ptr2->next;
    return temp;
}

int main()
{
    struct linkedList *node1;
    struct linkedList *node2;
    struct linkedList *node3;

    node1 = (struct linkedList *)malloc(sizeof(struct linkedList));
    node2 = (struct linkedList *)malloc(sizeof(struct linkedList));
    node3 = (struct linkedList *)malloc(sizeof(struct linkedList));

    node1->data = 10;
    node2->data = 20;
    node3->data = 30;

    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    node2->prev = node1;
    node3->prev = node2;
    node1->prev = NULL;

    printListForword(node1);
    printListBackword(node1);

    node1 = insertList(node1, 0);
    printListForword(node1);
    printListBackword(node1);

    node1 = insertListAtLast(node1, 40);
    printListForword(node1);
    printListBackword(node1);

    node1 = insertListAtMiddle(node1, 25);
    printListForword(node1);
    printListBackword(node1);

    node1 = deleteList(node1);
    printListForword(node1);

    node1 = deleteListAtEnd(node1);
    printListForword(node1);

    node1 = deleteListAtMiddle(node1);
    printListForword(node1);

    return 0;
} /* END OF MAIN FILE*/