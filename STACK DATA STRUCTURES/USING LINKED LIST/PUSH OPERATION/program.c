#include <stdio.h>
#include <stdlib.h>
/*                  creation of Structure                  */
struct node
{
    int data;
    struct node *next;
};

int isfull(struct node *temp1)
{
    struct node *temp2 = (struct node *)malloc(sizeof(struct node *));
    if (temp2 == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
struct node *push(struct node *temp1, int data)
{
    struct node *temp2;
    temp2 = (struct node*)malloc(sizeof(struct node));
    struct node *top = temp1;
    if (isfull(temp1))
    {
        printf("Stack OverFlow! No More Data Can Be entered\n");
    }
    else
    {
        temp2->data = data;
        temp2->next = temp1;
        top = temp2;
        return top;
    }
}

void listtraversal(struct node *temp1)
{
    struct node *temp2;
    temp2 = temp1;
    int i = 1;
    while (temp2 != NULL)
    {
        printf("The Value of node at %d is : %d\n", i, temp2->data);
        temp2 = temp2->next;
        i++;
    }
}
int main()
{
    /*                  creation of nodes                  */
    struct node *node1;
    struct node *node2;
    struct node *node3;
    struct node *node4;
    struct node *node5;
    struct node *node6;
    struct node *node7;
    struct node *node8;
    struct node *node9;
    struct node *node10;
    /*                  creation finished                  */

    /*                  memory allocation for the nodes created                  */
    node1 = (struct node *)malloc(sizeof(struct node));
    node2 = (struct node *)malloc(sizeof(struct node));
    node3 = (struct node *)malloc(sizeof(struct node));
    node4 = (struct node *)malloc(sizeof(struct node));
    node5 = (struct node *)malloc(sizeof(struct node));
    node6 = (struct node *)malloc(sizeof(struct node));
    node7 = (struct node *)malloc(sizeof(struct node));
    node8 = (struct node *)malloc(sizeof(struct node));
    node9 = (struct node *)malloc(sizeof(struct node));
    node10 = (struct node *)malloc(sizeof(struct node));
    /*                  memory allocation for the nodes finished                  */

    /*                  entering data mannually in the linked list                 */
    node1->data = 1;
    node2->data = 2;
    node3->data = 3;
    node4->data = 4;
    node5->data = 5;
    node6->data = 6;
    node7->data = 7;
    node8->data = 8;
    node9->data = 9;
    node10->data = 10;
    /*                  entering data mannually in the linked list finished                 */

    /*                  linking mannually of the linked list nodes               */
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = node8;
    node8->next = node9;
    node9->next = node10;
    node10->next = NULL;
    /*                  linking mannually of the linked list nodes finished               */

    /*                  calling oif traversal function               */
    printf("Data Before Modification : \n");
    listtraversal(node1);

    node1 = push(node1, 11);

    printf("Data after Modification : \n");
    listtraversal(node1);

    return 0;
} /* END OF MAIN FILE*/