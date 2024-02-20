#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

void ListTraversal(struct node *temp) {
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void ListTraversalBackward(struct node *temp) {
    if (temp == NULL) {
        printf("Empty list\n");
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    printf("NULL <- ");

    while (temp != NULL) {
        printf("%d <- ", temp->data);
        temp = temp->prev;
    }

    printf("NULL\n");
}

struct node *insertAtStart(struct node *temp, int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = temp;
    newNode->prev = NULL;
    if (temp != NULL) {
        temp->prev = newNode;
    }
    return newNode;
}

struct node *insertAtLast(struct node *temp, int data) {
    struct node *ptr;
    ptr = temp;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if (temp == NULL) {
        newNode->prev = NULL;
        return newNode;
    }
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->prev = ptr;
    return temp;
}

struct node *insertAtMiddle(struct node *temp, int data, int index) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    struct node *ptr;
    ptr = temp;
    int i = 1;
    while (i < index && ptr->next != NULL) {
        ptr = ptr->next;
        i++;
    }
    if (i != index) {
        printf("Index out of range\n");
        return temp;
    }
    newNode->data = data;
    newNode->next = ptr->next;
    newNode->prev = ptr;
    if (ptr->next != NULL) {
        ptr->next->prev = newNode;
    }
    ptr->next = newNode;
    return temp;
}

struct node *deleteFormStart(struct node *temp) {
    if (temp == NULL) {
        printf("Empty list\n");
        return NULL;
    }
    struct node *ptr = temp;
    temp = temp->next;
    if (temp != NULL) {
        temp->prev = NULL;
    }
    free(ptr);
    return temp;
}

struct node *deleteFromEnd(struct node *temp) {
    if (temp == NULL) {
        printf("Empty list\n");
        return NULL;
    }
    if (temp->next == NULL) {
        free(temp);
        return NULL;
    }
    struct node *ptr1 = temp;
    struct node *ptr2 = temp->next;
    while (ptr2->next != NULL) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    ptr1->next = NULL;
    free(ptr2);
    return temp;
}

struct node *deleteFromMiddle(struct node *temp, int index) {
    struct node *ptr1 = temp;
    struct node *ptr2 = temp->next;
    int i = 1;
    while (i < index && ptr2 != NULL) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
        i++;
    }
    if (i != index || ptr2 == NULL) {
        printf("Index out of range\n");
        return temp;
    }
    ptr1->next = ptr2->next;
    if (ptr2->next != NULL) {
        ptr2->next->prev = ptr1;
    }
    free(ptr2);
    return temp;
}

int main() {
    struct node *firstNode = NULL;

    firstNode = insertAtStart(firstNode, 1);
    firstNode = insertAtLast(firstNode, 2);
    firstNode = insertAtLast(firstNode, 3);

    ListTraversal(firstNode);

    firstNode = insertAtStart(firstNode, 0);
    ListTraversal(firstNode);

    firstNode = insertAtLast(firstNode, 4);
    ListTraversal(firstNode);

    firstNode = insertAtMiddle(firstNode, 5, 4);
    ListTraversal(firstNode);

    firstNode = deleteFormStart(firstNode);
    ListTraversal(firstNode);

    firstNode = deleteFromEnd(firstNode);
    ListTraversal(firstNode);

    firstNode = deleteFromMiddle(firstNode, 2);
    ListTraversal(firstNode);

    ListTraversalBackward(firstNode);

    return 0;
}
