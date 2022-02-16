//Priority queue using O(1) insertion and O(n) deletion

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    int priority;
    struct node* next;
};
struct node *front = NULL, *rear = NULL;

struct node* createNode(int data, int prior)
{
    struct node* newNode = (struct node*)malloc((sizeof(struct node)));
    if(newNode == NULL)
    {
        printf("Sorry there was an error\n Aborting\n");
        exit(0);
    }
    newNode->next     = NULL;
    newNode->data     = data;
    newNode->priority = prior;
    return(newNode);
}

void push(int data, int prior)
{
    struct node *newNode = createNode(data, prior);
    if(rear == NULL)
    {
		front = newNode;
		rear  = newNode;
    }
    else
    {
		rear->next = newNode;
		rear = newNode;
    }
    printf("Pushed: %d\n", data);
}

void display()
{
    if(front == NULL)
        printf("\n Queue Empty");
    else
    {
        struct node *temp = front;
	    printf("\n");
        while(temp != NULL)
        {
        	printf("Data:%d  Priority: %d\n", temp->data, temp->priority);
        	temp = temp->next;
        }
    }
    printf("\n");
}

void pop()
{
    if(front == NULL)
    {
        printf("\n Queue Empty\n");
    }
    else
    {
    	int maxPrior = front->data;
    	struct node *prev = NULL, *temp=front;
    	while(temp->next !=NULL)
    	{
    		if(temp->next->priority > maxPrior)
    		{
    			prev = temp;
    			maxPrior = temp->next->priority;
    		}
    		temp = temp->next;
    	}
    	
    	// this means maxPriority is front element
    	if(prev == NULL)
    	{
    		temp = front;
    		front = front->next;
    		if(front == NULL)
    			rear = NULL;
    		free(temp);
    	}
    	else
    	{
    		struct node *del = prev->next;
    		prev->next = prev->next->next;
    		free(del);
    	}
    }
}

int main()
{
    int choice;
    do
    {
        int data, prior;
        printf("1: Push\n");
        printf("2: Display Queue\n");
        printf("3: Pop\n");
        printf("4: Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d",&data);
                printf("Enter priority: ");
                scanf("%d",&prior);
                push(data, prior);
                break;
            case 2:
                display();
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
