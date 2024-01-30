#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct demo
{
    int size;
    int top;
    char *arr;
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
    if (temp->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct demo *temp, char ch)
{
    if (isfull(temp))
    {
        printf("Stack Overflow! Cannot push %d to the stack\n", ch);
    }
    temp->top++;
    temp->arr[temp->top] = ch;
}
char pop(struct demo *temp)
{
    if (isempty(temp))
    {
        printf("equation is balanced\n");
    }
    else
    {
        int value = temp->arr[temp->top];
        temp->top--;
        return value;
    }
}
int match(char a , char b){
    if (a == '(' && b == ')')
    {
        return 1;
    }
    else if (a == '[' && b == ']')
    {
        return 1;
    }
    else if (a == '{' && b == '}')
    {
        return 1;
    }
    else {
        return 0;
    }
}
int IsparenthesisMatch(char *exp)
{
    struct demo *temp = (struct demo *)malloc(sizeof(struct demo));
    temp->size = 100;
    temp->top = -1;
    temp->arr = (char *)malloc(temp->size * sizeof(char));

    char poppedch;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            push(temp, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            if (isempty(temp))
            {
                return 0;
            }
            else
            {
                poppedch = pop(temp);
                if (match(poppedch,exp[i]))
                {
                    return 1;
                }
                else {
                    return 0;
                }
                
            }
        }
    }

    if (isempty(temp))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char exp[100];
    printf("enter the expression : ");
    scanf("%s", exp);
    if (IsparenthesisMatch(exp))
    {
        printf("Balanced\n");
    }
    else
    {
        printf("Un-Balanced\n");
    }
    return 0;
} /* END OF MAIN FILE*/