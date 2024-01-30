#include <stdio.h>
#include <stdlib.h>
/*                  creation of self Referential Structure                  */
struct node
{
    int data;               //4 bytes of memory + 4 bytes of padding
    struct node *next;      //8 bytes of memory (64 bits system)
};
/*                  creation of Self Referential Structure finished                 */

/*                  creation of Traversal Function                 */
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
/*                  creation of Traversal Function finished                */

/*                  creation of Deletion From Begining Function             */
struct node* deletion0(struct node * temp1){
    struct node *temp2;
    temp2=temp1->next;
    return temp2;
}

/*                  creation of Deletion For beginning Function finished                 */

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

    /*                  calling of traversal function               */
    printf("The Data Before Modification is : \n\n");
    listtraversal(node1);
    printf("\n");
    /*                  calling of traversal function               */

    /*                  calling of deletion from the beginning function               */
    node1 = deletion0(node1);
    /*                  calling of deletion from the beginning function Finished              */

    printf("The Data After Modification is :\n\n");
    listtraversal(node1);
    printf("\n");

    return 0;
} /* Middle at Specified position OF MAIN FILE*/