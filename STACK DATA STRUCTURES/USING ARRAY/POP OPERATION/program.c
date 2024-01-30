#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr;
};
int isfull(struct stack *temp)
{
    if (temp->top == temp->size - 1)
    {
        printf("stack overflow ! No data can be entered more\n");
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct stack *ptr, int value)
{
    if (isfull(ptr))
    {
        printf("Therefore %d cann't be pushed \n\n", value);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}
int isempty(struct stack *temp)
{
    if (temp->top == -1)
    {
        printf("stack underflow ! No data can be poped more\n");
        return 1;
    }
    else
    {
        return 0;
    }
}
int pop(struct stack *ptr)
{
    int value = ptr->arr[ptr->top];
    if (isempty(ptr))
    {
        printf("Therefore %d cann't be popped \n\n", value);
    }
    else
    {
        ptr->top--;
        return value;
    }
}
int main()
{

    struct stack *myStack;
    myStack = (struct stack *)malloc(sizeof(struct stack));
    myStack->size = 10;
    myStack->top = -1;
    myStack->arr = (int *)malloc(myStack->size * sizeof(int));
    // myStack->arr[myStack->top++] = 1;  // --> mannul pushing of element
    for (int j = 0; j < myStack->size; j++)
    {
        push(myStack, j);
    }
    for (int j = 0; j < myStack->size; j++)
    {
        printf("the value pooped is = %d\n", pop(myStack));
    }
    return 0;
} /* END OF MAIN FILE*/