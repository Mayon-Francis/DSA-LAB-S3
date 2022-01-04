#include <stdio.h>

#define MAX 100

int stack[MAX], top = -1; // stack array and top

// Push function to insert element
void push(int data)
{
    if (top == MAX - 1)
        printf("\nStack overflow");
    else
        stack[++top] = data;
}

// Pop function to pop element
void pop()
{
    int del;
    if (top == -1)
        printf("\nStack empty");
    else
    {
        del = stack[top--];
        printf("\nDeleted: %d", del);
    }
}


// Displays top element without popping it
int peek()
{
	if(top == -1)
		return -1;
	else
		return stack[top];
}


// To print elements of stack
void display()
{
    if (top == -1)
        printf("\nStack empty");
    else
    {
        printf("\n");
        for (int i = 0; i <= top; i++)
        {
            printf("%d, ", stack[i]);
        }
    }
}

int main()
{
    int ch, element;
    do
    {
        printf("\n\nChoose operation");
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Display stack");
        printf("\n4.Display Top Element");
        printf("\n5.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter element to insert ");
            scanf("%d", &element);
            push(element);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
	        if(top == -1)
	        {
	        	printf("Stack Empty!");
	        }
	        else
	        {
                printf("Top element: %d", peek());
	        }
            break;
        }
    } while (ch < 5);

    return 0;
}
