#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

//Post Order Traversal
void postOrder(struct node *temp){
    if (temp != NULL)
    {
        postOrder(temp->prev);
        postOrder(temp->next);
        printf("%d",temp->data);
    }
    
}
//Post Order Traversal Ends Here


//Function For Creating The Nodes
struct node *createNode(int data)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->prev = NULL;
    ptr->next = NULL;

    return ptr;
}
//Function For Creating The Nodes Ends Here


int main()
{

    //Creating Nodes 
    struct node *rootNode = createNode(1);
    struct node *firstNode = createNode(2);
    struct node *secondNode = createNode(3);
    struct node *thirdNode = createNode(4);
    struct node *forthNode = createNode(5);
    struct node *fifthNode = createNode(6);
    //Creating Nodes Ends Here


    //Linking Of Nodes
    rootNode->next = secondNode;
    rootNode->prev = firstNode;
    firstNode->prev = thirdNode;
    firstNode->next = forthNode;
    secondNode->prev = fifthNode;
    //Linking Of Nodes Ends Here


    postOrder(rootNode);


    return 0;
} /* END OF MAIN FILE*/