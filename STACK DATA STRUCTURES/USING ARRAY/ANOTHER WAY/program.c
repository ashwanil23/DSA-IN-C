#include <stdio.h>
#include <stdlib.h>
struct demo
{
    int size;
    int top;
    int *arr;
};
int isfull(struct demo *temp)
{
    if (temp->top == temp->size - 1)
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
    if (temp->top == (-1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct demo *temp, int data)
{
    if (isfull(temp))
    {
        printf("stack OverFlow! %d cann't be pushed\n", data);
    }
    else
    {
        temp->top++;
        temp->arr[temp->top] = data;
    }
}
int pop(struct demo *temp)
{
    if (isempty(temp))
    {
        printf("Stack underflow\n");
        return 1;
    }
    else
    {
        int value;
        value = temp->arr[temp->top];
        temp->top--;
        return (value);
    }
}
void peek(struct demo *temp, int index)
{
    int value = temp->top - index + 1;
    if (value < 0)
    {
        printf("enter the value of index < %d\n", index);
    }
    else
    {
        printf("The value At index %d is %d\n", index, temp->arr[temp->top - index + 1]);
    }
}
int main()
{
    struct demo mystack;
    mystack.size = 5;
    mystack.top = -1;
    mystack.arr = malloc(mystack.size * sizeof(int));
    push(&mystack, 10);
    push(&mystack, 20);
    push(&mystack, 30);
    push(&mystack, 40);
    push(&mystack, 50);
    push(&mystack, 60);
    push(&mystack, 70);
    push(&mystack, 80);
    printf("popped value is : %d\n", pop(&mystack));
    peek(&mystack, 1);
    peek(&mystack, 2);
    peek(&mystack, 3);
     peek(&mystack, 4);
    peek(&mystack, 5);
    peek(&mystack, 6);
    return 0;
} /* END OF MAIN FILE*/