#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

// In Order Traversal
void InOrder(struct node *temp)
{
    if (temp != NULL)
    {
        InOrder(temp->prev);
        printf("%d ", temp->data);
        InOrder(temp->next);
    }
}
// In Order Traversal Ends Here

// Function Checking For BST
int isBST(struct node *temp)
{
    static struct node *prevData = NULL;
    if (temp != NULL)
    {
        if (!(isBST(temp->prev)))
        {
            return 0;
        }
        if (prevData != NULL && temp->data <= prevData->data)
        {
            return 0;
        }
        prevData = temp;
        return isBST(temp->next);
    }
    else
    {
        return 1;
    }
}
// Function Checking For BST Ends Here

// Function Checking For BST For 2nd PERFECT BST
int isBST2(struct node *temp)
{
    static struct node *prevData2 = NULL;
    if (temp != NULL)
    {
        if (!(isBST2(temp->prev)))
        {
            return 0;
        }
        if (prevData2 != NULL && temp->data <= prevData2->data)
        {
            return 0;
        }
        prevData2 = temp;
        return isBST2(temp->next);
    }
    else
    {
        return 1;
    }
}
// Function Checking For BST For 2nd PERFECT BST Ends Here

// Function For Creating The Nodes
struct node *createNode(int data)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->prev = NULL;
    ptr->next = NULL;

    return ptr;
}
// Function For Creating The Nodes Ends Here

//Recursive Search in BST
struct node *recursiveSearch(struct node *temp, int key){
    if (temp == NULL)
    {
        return NULL;
    }
    if(temp->data == key){
        return temp;
    }
    if (temp->data > key)
    {
        return recursiveSearch(temp->prev,key);
    }
    else{
        return recursiveSearch(temp->next,key);
    }
}
void isPresent(struct node *temp, int key){
    struct node *isPre = recursiveSearch(temp,key);
    if (isPre != NULL)
    {
        printf("Found :%d \n",isPre->data);
    }else{
        printf("key Not Found \n");
    }
    
}
//Recursive Search in BST Ends Here


int main()
{

    /*               1
                   /   \
                  /     \
                 2       3
                / \     / \
               4   5   6   NULL     */

    // Creating Nodes
    struct node *rootNode = createNode(1);
    struct node *firstNode = createNode(2);
    struct node *secondNode = createNode(3);
    struct node *thirdNode = createNode(4);
    struct node *forthNode = createNode(5);
    struct node *fifthNode = createNode(6);
    // Creating Nodes Ends Here

    // Linking Of Nodes
    rootNode->next = secondNode;
    rootNode->prev = firstNode;
    firstNode->prev = thirdNode;
    firstNode->next = forthNode;
    secondNode->prev = fifthNode;
    // Linking Of Nodes Ends Here

    /*      "PERFECT BINARY SEARCH TREE"
                     7
                   /   \
                  /     \
                 5       9
                / \     / \
               4   6   8   10
            "PERFECT BINARY SEARCH TREE ENDS HERE" */

    // Creating Nodes For BST
    struct node *rootNode1 = createNode(7);
    struct node *firstNode1 = createNode(5);
    struct node *secondNode1 = createNode(9);
    struct node *thirdNode1 = createNode(4);
    struct node *forthNode1 = createNode(6);
    struct node *fifthNode1 = createNode(8);
    struct node *sixthNode1 = createNode(10);
    // Creating Nodes For BST Ends Here

    // Linking Of Nodes
    rootNode1->next = secondNode1;
    rootNode1->prev = firstNode1;
    firstNode1->prev = thirdNode1;
    firstNode1->next = forthNode1;
    secondNode1->prev = fifthNode1;
    secondNode1->next = sixthNode1;
    // Linking Of Nodes Ends Here

    InOrder(rootNode);
    printf("\n");

    // Checking For BST
    if (isBST(rootNode))
    {
        printf("Yes Its a BST");
    }
    else
    {
        printf("No Its not BST");
    }
    // Checking For BST Ends Here

    printf("\n");
    printf("\n");
    InOrder(rootNode1);
    printf("\n");

    // Checking For BST For 2nd PERFECT BST
    if (isBST2(rootNode1))
    {
        printf("PERFECT BINARY SEARCH TREE\n");
        printf("         7\n");
        printf("       /   \\\n");
        printf("      /     \\\n");
        printf("     5       9\n");
        printf("    / \\     / \\\n");
        printf("   4   6   8   10\n");
        printf("PERFECT BINARY SEARCH TREE ENDS HERE\n");
        printf("Yes Its a BST \n");
    }
    else
    {
        printf("No Its not BST \n");
    }
    // Checking For BST For 2nd PERFECT BST Ends Here
    isPresent(rootNode1,9);
    isPresent(rootNode,9);
    
    return 0;
} /* END OF MAIN FILE*/