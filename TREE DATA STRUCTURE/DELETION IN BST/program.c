#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void preOrderTraversal(struct node *temp)
{
    if (temp != NULL)
    {
        printf("%d ", temp->data);
        preOrderTraversal(temp->left);
        preOrderTraversal(temp->right);
    }
}

void postOrderTraversal(struct node *temp)
{
    if (temp != NULL)
    {
        postOrderTraversal(temp->left);
        postOrderTraversal(temp->right);
        printf("%d ", temp->data);
    }
}

void inOrderTraversal(struct node *temp)
{
    if (temp != NULL)
    {
        inOrderTraversal(temp->left);
        printf("%d ", temp->data);
        inOrderTraversal(temp->right);
    }
}

int isBST(struct node *temp)
{
    static struct node *preData = NULL;
    if ((temp != NULL))
    {
        if (!isBST(temp->left))
        {
            return 0;
        }
        if (preData != NULL && temp->data <= preData->data)
        {
            return 0;
        }
        preData = temp;
        return isBST(temp->right);
    }
    else
    {
        return 1;
    }
}

struct node *isPresent(struct node *temp, int key)
{
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return temp;
        }
        if (temp->data < key)
        {
            return isPresent(temp->right, key);
        }
        if (temp->data > key)
        {
            return isPresent(temp->left, key);
        }
    }

    return NULL;
}

//__________________________________________________________________________________________________________________
//Deletion Functon Starts Here(recurrsive approach)
struct node *deleteNode(struct node *temp, int element) {
    if (temp == NULL) {
        return temp; // Node not found
    }

    if (element < temp->data) {
        temp->left = deleteNode(temp->left, element);
    } else if (element > temp->data) {
        temp->right = deleteNode(temp->right, element);
    } else { // Node found

        // Handle node with no children (leaf node)
        if (temp->left == NULL && temp->right == NULL) {
            free(temp);
            temp = NULL; // Set pointer to NULL to indicate deletion
            return temp;
        }

        // Handle node with one child (right child)
        if (temp->left == NULL) {
            struct node *ptr = temp->right;
            free(temp);
            return ptr; // Replace deleted node with its right child
        }

        // Handle node with one child (left child)
        if (temp->right == NULL) {
            struct node *ptr = temp->left;
            free(temp);
            return ptr; // Replace deleted node with its left child
        }

        // Handle node with two children (use in-order successor)
        struct node *ptr = temp->right;
        while (ptr->left != NULL) {
            ptr = ptr->left;
        }
        temp->data = ptr->data;
        temp->right = deleteNode(temp->right, ptr->data); // Delete in-order successor
    }

    return temp;
}
//Deletion Functon Ends Here(recurrsive approach)
//__________________________________________________________________________________________________________________

int main()
{
    struct node *rootNode = createNode(25);
    struct node *firstNode = createNode(20);
    struct node *secondNode = createNode(36);
    struct node *thirdNode = createNode(10);
    struct node *forthNode = createNode(22);
    struct node *fifhtNode = createNode(30);
    struct node *sixthNode = createNode(40);
    struct node *seventhNode = createNode(5);
    struct node *eighthNode = createNode(12);
    struct node *ninethNode = createNode(28);
    struct node *tenthNode = createNode(38);
    struct node *eleventhNode = createNode(48);

    // Constructing the BST by inserting nodes in the correct order
    rootNode->left = firstNode;
    rootNode->right = secondNode;
    firstNode->left = thirdNode;
    firstNode->right = forthNode;
    secondNode->left = fifhtNode;
    secondNode->right = sixthNode;
    thirdNode->left = seventhNode;
    thirdNode->right = eighthNode;
    fifhtNode->left = ninethNode;
    sixthNode->left = tenthNode;
    sixthNode->right = eleventhNode;

    preOrderTraversal(rootNode);
    printf("\n");
    postOrderTraversal(rootNode);
    printf("\n");
    inOrderTraversal(rootNode);
    printf("\n");
    if (isBST(rootNode))
    {
        printf("Yes This is BST \n");
    }
    else
    {
        printf("This Isn't BST \n");
    }

    int searchingElement = 49;
    if ((isPresent(rootNode, searchingElement)) != NULL)
    {
        printf("yes %d is Present \n", searchingElement);
    }
    else
    {
        printf("No %d Not Found", searchingElement);
    }
    printf("\n");
    rootNode = deleteNode(rootNode, 5);
    inOrderTraversal(rootNode);
    return 0;
} /* END OF MAIN FILE*/