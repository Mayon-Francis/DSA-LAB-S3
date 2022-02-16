#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};
struct node* top = NULL;

struct node* createNode(int data)
{
    struct node* newNode = (struct node*)malloc((sizeof(struct node)));
    if(newNode == NULL)
    {
        printf("Sorry there was an error\n Aborting\n");
        exit(0);
    }
    newNode->next = NULL;
    newNode->data = data;
    return(newNode);
}

void push(int data)
{
    struct node *newNode = createNode(data);
	newNode->next = top;
    top = newNode;
    printf("Pushed: %d\n", data);
}

void peek()
{
    if(top == NULL)
        printf("\n Stack Empty");
    else
    {
        printf("\n Top: %d", top->data);
    }
    printf("\n");
}

void pop()
{
    if(top == NULL)
    {
        printf("\n Stack Empty\n");
    }
    else
    {
    	printf("Popped: %d\n", top->data);
    	struct node* temp = top;
    	top = top->next;
    	free(temp);
    }
}

int main()
{
    int choice;
    do
    {
        int data;
        printf("1: Push\n");
        printf("2: Peek\n");
        printf("3: Pop\n");
        printf("4: Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d",&data);
                push(data);
                break;
            case 2:
                peek();
                break;
            case 3:
                pop();
                break;
            case 4:
                break;
            default:
                printf("Invalid Choice\n");
                break;
        };
    }while(choice != 4);
    return 0;
}
