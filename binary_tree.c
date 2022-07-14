#include <stdio.h>
#include <conio.h>
#include <process.h>
#include <stdlib.h>

// structure of a node in tree
struct node
{
    int num;
    struct node *left;
    struct node *right;
};

// universal declaration of node variable
typedef struct node node;

//function prototypes
node *p = NULL;
node *delNum(int digit, node *p);
node *deleteNode(int digit, node *p);
node *insert(node *p, int digit);
void search(node *p, int num);
void preorder(node *p);
void inorder(node *p);
void postorder(node *p);
int select();


int main(int argc, char const *argv[])
{
    int choice;
    int digit;

    do
    {
        choice = select();
        switch (choice)
        {
            case 1:{
                puts("\nEnter integer: To quit enter 0");
                scanf("%d", &digit);
                while (digit != 0)
                {
                    p = insert(p, digit);
                    scanf("%d", &digit);
                }continue;
                
            }

            case 2:{
                puts("\nEnter the number to be searched: ");
                scanf("%d", &digit);
                search(p, digit);
                continue;
            }

            case 3:{
                puts("\nPreorder traversing TREE");
                preorder(p);
                continue;
            }

            case 4:{
                puts("\nInorder traversing TREE");
                inorder(p);
                continue;
            }

            case 5:{
                puts("\nPostorder traversing TREE");
                postorder(p);
                continue;
            }

            case 6:{
                puts("\nEnter the element which you want to delete from the BST\n");
                scanf("%d", &digit);
                deleteNode(digit, p);
                continue;

            }

            case 7:{
                puts("\nEnd");
                exit(0);
            }
        }
    } while (choice != 7);
    
    return 0;
}

int select(){
    int selection;
    do
    {
        puts("Enter 1: Insert a node in the BST");
        puts("Enter 2: Search a node in BST");
        puts("Enter 3: Display (preorder) the BST");
        puts("Enter 4: Display (inorder) the BST");
        puts("Enter 5: Display (postorder) the BST");
        puts("Enter 6: Delete the element: ");
        puts("Enter 7: End");
        puts("Enter your choice");
        scanf("%d", &selection);
        if ((selection < 1) || (selection > 7)){
            puts("Wrong choice: Try again");
            getch();
        }        
    } while ((selection < 1) || (selection > 7));

    return (selection);
}

// structure as a function to insert a node in the binary tree
node *insert(node *p, int digit){

    // if the tree or root node does not exist
    // create a new root node
    if (p == NULL)
    {
        p = (node *)malloc(sizeof(node));
        p->left = p->right = NULL;
        p->num = digit;
    }

    else if (digit < p->num)
    {
        p->left = insert(p->left, digit);
    }

    else if (digit > p->num)
    {
        p->right = insert(p->right, digit);
    }

    else if (digit == p->num)
    {
        puts("Duplicate node : program exited");
        exit(0);
    }

    return (p);
    
}

node *delNum(int digit, node *r){
    node *q;
    if(r->right != NULL){
        delNum(digit, r->right);
    }

    else{
        q->num = r->num;
        q = r;
        r = r->left;
    }
}

node *deleteNode(int digit, node *p){
    node *r, *q;
    if(p == NULL){
        puts("P is empty");
        exit(0);
    }

    if (digit < p->num)
    {
        deleteNode(digit, p->left);
    }

    else if (digit > p->num)
    {
        deleteNode(digit, p->right);
    }

    q = p;
    if((q->right == NULL) && (q->left == NULL)){
        q = NULL;
    }

    else if (q->right == NULL)
    {
        p = q->left;
    }

    else if (q->left == NULL)
    {
        p = q->right;
    }

    else
    {
        delNum(digit, q->left);
    }
    free(q); 
}

void search(node *p, int digit){
    if(p == NULL){
        puts("The number does not exist\n");
    }
    else if (digit == p->num)
    {
        printf("\nNumber: %d", digit);
    }

    else if (digit < p->num)
    {
        search(p->left, digit);
    }

    else{
        search(p->right, digit);
    } 
}



void preorder(node *p){
    if (p != NULL)
    {
        printf("%d", p->num);
        preorder(p->left);
        preorder(p->right);
    }
    
}

void inorder(node *p){
    if (p != NULL)
    {
        inorder(p->left);
        printf("%d", p->num);
        inorder(p->right);
    }
    
}void postorder(node *p){
    if (p != NULL)
    {
        postorder(p->left);
        postorder(p->right);
        printf("%d", p->num);
    }
    
}