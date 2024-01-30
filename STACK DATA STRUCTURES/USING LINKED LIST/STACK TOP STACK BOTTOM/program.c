#include <stdio.h>
#include <stdlib.h>
struct demo
{
    int data;
    struct demo *next;
};
int isfull(struct demo *temp)
{
    struct demo *p = (struct demo *)malloc(sizeof(struct demo));
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isempty(struct demo *temp)
{
    if (temp == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
struct demo *push(struct demo *temp1, int data)
{
    if (isfull(temp1))
    {
        printf("Stack OverFlow!\n");
    }
    else
    {
        struct demo *node;
        node = (struct demo *)malloc(sizeof(struct demo));
        node->data = data;
        node->next = temp1;
        temp1 = node;
        return temp1;
    }
}
void traversal(struct demo *temp)
{
    while (temp != NULL)
    {
        printf("Data : %d\n", temp->data);
        temp = temp->next;
    }
}
struct demo *pop(struct demo *temp1)
{
    if (isempty(temp1))
    {
        printf("Stack UnderFlow!\n");
    }
    else
    {
        struct demo *temp2;
        temp2 = temp1->next;
        return temp2;
    }
}

void stacktop(struct demo *temp)
{
    if (isempty(temp))
    {
        printf("No Top Data :\n");
    }
    else
    {
        printf("The top element is : %d\n", temp->data);
    }
}
void stackbottom(struct demo *temp)
{
    if (isempty(temp))
    {
        printf("NULL\n");
    }
    else
    {
        struct demo *temp2;
        temp2 = temp;
        while(temp2->next != NULL)
        {
            temp2 = temp2->next;
        }
        printf("The bottom element is : %d\n", temp2->data);
    }
}

int main()
{
    struct demo *node1;
    node1 = NULL;
    node1 = push(node1, 10);
    node1 = push(node1, 20);
    node1 = push(node1, 30);
    node1 = push(node1, 40);
    node1 = push(node1, 50);
    node1 = push(node1, 60);
    printf("Data After Push\n");
    traversal(node1);

    node1 = pop(node1);
    printf("Data After Pop\n");
    traversal(node1);

    stackbottom(node1);
    stacktop(node1);
} /* END OF MAIN FILE*/