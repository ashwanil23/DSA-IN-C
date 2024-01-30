#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Stack1
{
    int size;
    int top;
    char *arr;
};
int isFull(struct Stack1 *temp)
{
    if (temp->top >= temp->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty(struct Stack1 *temp)
{
    if (temp->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct Stack1 *temp, char ch)
{
    if (isFull(temp))
    {
        printf("Stack OverFlow! %d cannot be pushed into the stack \n", ch);
    }
    else
    {
        temp->top++;
        temp->arr[temp->top] = ch;
    }
}
char pop(struct Stack1 *temp)
{
    char operator;
    if (isEmpty(temp))
    {
        printf("Stack UnderFlow!\n");
    }
    else
    {
        operator= temp->arr[temp->top];
        temp->top--;
        return operator;
    }
}

char stackTop(struct Stack1 *temp)
{
    return temp->arr[temp->top];
}
int isOperator(char temp)
{
    if (temp == '+' || temp == '-' || temp == '*' || temp == '/')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int precedence(char temp1)
{
    if (temp1 == '/' || temp1 == '*')
    {
        return 3;
    }
    else if (temp1 == '+' || temp1 == '-')
    {
        return 2;
    }
    return 0;
}
char *postFix(char *tempExp)
{

    // Creating A stack To store the operators
    struct Stack1 *temp = (struct Stack1 *)malloc(sizeof(struct Stack1));
    temp->size = 100;
    temp->top = -1;
    temp->arr = (char *)malloc(temp->size * sizeof(char));
    // Stack Creation finished
    int i = 0;
    int j = 0;

    char *store = (char *)malloc((strlen(tempExp) + 1) * sizeof(char));

    while (tempExp[i] != '\0')
    {
        if (!isOperator(tempExp[i]))
        {
            store[j] = tempExp[i];
            i++;
            j++;
        }
        else
        {
            if (precedence(tempExp[i]) > precedence(stackTop(temp)))
            {
                push(temp, tempExp[i]);
                i++;
            }
            else
            {
                store[j] = pop(temp);
                j++;
            }
        }
    }
    while (!isEmpty(temp))
    {
        store[j] = pop(temp);
        j++;
    }
    store[j] = '\0';
    return store;
}
int main()
{
    char exp[100] = "a+b+c/c*u/d";
    printf("Postfix of %s is %s :", exp, postFix(exp));
    return 0;
} /* END OF MAIN FILE*/