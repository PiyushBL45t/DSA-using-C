#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 50

char stack[SIZE];
int top = -1;
void inf_to_postf(char infix[]);
void push(char symbol);
char pop();

int main()
{
    char infix[25];
    printf("\nEnter the infix expression: ");
    gets(infix);
    inf_to_postf(infix);
    getch();
    
    return 0;
}

void push(char symbol){
    if(top >= SIZE -1){
        printf("\nStack overflow");
        return;
    }

    else
    {
        top = top + 1;
        stack[top] = symbol;
    }  
}

char pop(){
    char item;
    if(top == -1){
        printf("\nStack empty!");
        getch();
        return '\0';
    }

    else{
        item = stack[top];
        top--;
    }

    return item;
}

int preced(char ch){
    if(ch == 47){
        return 5;
    }

    else if (ch ==42)
    {
        return 4;
    }
    
    else if (ch == 43)
    {
        return 3;
    }

    else{
        return 2;
    }
    
}

void inf_to_postf(char infix[]){
    int length;
    static int index = 0, pos = 0;
    char symbol, temp, postfix[40];
    length = strlen(infix);
    push('#');
    while (index < length)
    {
        symbol = infix[index];
        switch(symbol){
            case '(':push(symbol);break;
            case ')':temp = pop();
            while(temp != '('){
                postfix[pos] = temp;
                pos++;
                temp = pop();
            }
            break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
            while (preced(stack[top]) >= preced(symbol))
            {
                temp = pop();
                postfix[pos] = temp;
                pos++;
            }

            push(symbol);break;

            default:postfix[pos++] = symbol;break;    
        }
        index++;
    }

    while (top > 0)
    {
        temp = pop();
        postfix[pos++] = temp;
    }

    postfix[pos++] = '\0';
    puts(postfix);return;
    
    
}
