#include <stdio.h>
#include <string.h>

#define MAX 50          // maximum size of stack

char st[MAX];           // stack array
int top = -1;           // top of stack

// Function to push element into stack
int add(char x)
{
    // Check for stack overflow
    if(top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return 0;
    }

    // Insert element into stack
    top++;
    st[top] = x;
    return 1;
}

// Function to pop element from stack
int remove1(char *x)
{
    // Check for stack underflow
    if(top == -1)
    {
        printf("Stack Underflow\n");
        return 0;
    }

    // Remove top element from stack
    *x = st[top];
    top--;
    return 1;
}

int main()
{
    char exp[50];       // to store input expression
    int i;              // loop variable
    char ch;             // to store popped bracket

    
    printf("Enter expression: ");
    scanf("%s", exp);   

    
    for(i = 0; i < strlen(exp); i++)
    {
        // If opening bracket, push into stack
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            if(!add(exp[i]))   // push failed
            {
                printf("Not Balanced\n");
                return 0;
            }
        }

        // If closing bracket
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            // If stack is empty, popping is not possible
            if(!remove1(&ch))
            {
                printf("Not Balanced\n");
                return 0;
            }

            // Check whether brackets match
            if((ch == '(' && exp[i] != ')') ||
               (ch == '{' && exp[i] != '}') ||
               (ch == '[' && exp[i] != ']'))
            {
                printf("Not Balanced\n");
                return 0;
            }
        }
    }

    // After scanning entire expression
    if(top == -1)
        printf("Balanced\n");     // stack empty means balanced
    else
        printf("Not Balanced\n"); // stack not empty means unbalanced

    return 0;
}