#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *createNode(int data){
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data ;
    ptr->prev = NULL;
    ptr->next = NULL;
    return ptr;
}
void inOrderTrav(struct node *temp){
    if (temp != NULL)
    {
        inOrderTrav(temp->prev);
        printf("%d ",temp->data);
        inOrderTrav(temp->next);
    } 
}
int isBst(struct node *temp){
    static struct node *ptr;
    if(temp != NULL){
        if (!(isBst(temp->prev)))
        {
            return 0;   
        }
        if (ptr != NULL && temp->data <= ptr->data)
        {
            return 0;
        }
        ptr = temp;
        return isBst(temp->next);
        
    }else{
        return 1;
    }
}

int isPresent(struct node *temp, int data){
    if (isBst(temp))
    {
        if (temp->prev != NULL)
        {
            if (temp->data != data)
            {
                return isPresent(temp->prev, data);
            }else{
                return 1;
            }   
        }
        if (temp->next != NULL)
        {
            if (temp->data != data)
            {
                return isPresent(temp->next, data);
            }else{
                return 1;
            }
        }    
    }else{
        return 0;
    }
    return 0;

}

//Insertion Function Starts Here
void insertElement(struct node *temp, int key){
    struct node *ptr1 = NULL;
    while (temp != NULL)
    {
        ptr1 = temp;
        if (key == temp->data)
        {
            printf("Cannot Insert %d In BST \n",key);
            return;
        }
        else if (temp->data < key)
        {
            temp = temp->next;
        }
        else if (temp->data > key)
        {
            temp = temp->prev;
        }    
    }
    struct node *newNode = createNode(key);
    if (key < ptr1->data)
    {
        ptr1->prev = newNode;
    }else{
        ptr1->next = newNode;
    }
        
}
//Insertion Function Ends Here


int main()
{
    struct node *rootNode = createNode(8);
    struct node *firstNode = createNode(3);
    struct node *secondNode = createNode(10);
    struct node *thirdNode = createNode(1);
    struct node *forthNode = createNode(6);
    // struct node *fifthNode = createNode(8);
    struct node *sixthNode = createNode(14);
    struct node *seventhNode = createNode(4);
    struct node *eighthNode = createNode(7);
    struct node *ninethNode = createNode(13);

    rootNode->prev = firstNode;
    rootNode->next = secondNode;
    firstNode->prev = thirdNode;
    firstNode->next = forthNode;
    secondNode->next = sixthNode;
    forthNode->prev = seventhNode;
    forthNode->next = eighthNode;
    sixthNode->prev = ninethNode;

    inOrderTrav(rootNode);

    insertElement(rootNode,9);
    printf("\n");

    inOrderTrav(rootNode);

    insertElement(rootNode,18);
    printf("\n");

    inOrderTrav(rootNode);

    insertElement(rootNode,17);
    printf("\n");

    inOrderTrav(rootNode);

    insertElement(rootNode,20);
    printf("\n");

    inOrderTrav(rootNode);

    return 0;
}		 /* END OF MAIN FILE*/