#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//structure of a node in Linked-list
struct node{
    int data;
    struct node *next;
} *rear = NULL, *front = NULL; // global variables

typedef struct node node;

void enque(int val){
    node *ptr;
	ptr = (struct node *)malloc(sizeof(struct node));
	ptr->data = val;
	ptr->next = NULL;
	if ((front == NULL) && (rear == NULL)) {
		front = rear = ptr; //assign as first element
	} else {
		rear->next = ptr;
		rear = ptr; // inserting the node from rear end
	}
	printf("\nElement inserted!");
    
}

int dequeue(){
    
    if(front == NULL){
        printf("\nQueue is full cannot delete elements!");
        return -1;
    }

    node *p = front;
    int temp = front->data; // assigning the value of table to front
    front = front->next;
    free(p);
    return temp;

}

void traverse(){
    node *temporary;
    if ((front == NULL) && (rear == NULL)) {
		printf("\nQueue is Empty\n");
	} else {
		printf("The queue is \n");
		temporary = front;
		while (temporary != NULL) {
			printf("%d-->", temporary->data);
			temporary = temporary->next;
		}
		printf("NULL\n\n");
	}
}

int peek(){
    node *temp;
    temp = front;
    if(front == NULL){
        printf("\nQueue is empty!");
        return 1;
    }

    else{
        return temp->data; 
    }
}

int main()
{
    int ch;
    do
    {
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Traverse");
        printf("\n4. Peek");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%i", &ch);
        switch (ch)
        {
            case 1:{
                int value;
                printf("\nEnter the element to insert: ");
                scanf("%d", &value);
                enque(value);
                break;
            }
                
            case 2:{
                printf("\nThe deleted element is: %d", dequeue());
                break;
            }
            
            case 3:{
                traverse();
                break;
            }

            case 4:{
                printf("\nThe front element is: %d", peek());
                break;

            }

            case 5:{
                exit(0);
                break;

            }

            default:{
                printf("Wrong choice...");
                break;
            }

        }


    } while (ch != 5);
    
    
    return 0;
}
