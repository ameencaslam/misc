#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}struct node *head = NULL;

struct node *nodeCreate(int data)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL)
    {
        printf("Error allocating!");
        exit(1);
    }
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

void insBegin(int data)
{
    struct node *newNode = nodeCreate(data);
    newNode->next=head;
    head=newNode;
}

void insEnd(int data)
{
    struct node *newNode = nodeCreate(data);
    struct node *temp;
    if(head == NULL)
    {
        head=newNode;
        return;
    }
    temp=head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next=newNode;
}

void insMid(int data, int pos)
{
    struct node *temp=head;
    int crnt=0;
    
    while(temp->next != NULL)
    {
        temp=temp->next;
        crnt++;
    }
    // resume from here
    if((pos <= 0))
    {
        return;
    }
    
    if(pos == 1)
    {
        insBegin(data);
        return;
    }


}

void main()
{
    int ch;
    printf("1. Insertion\n2. Display\n\nEnter your Choice : ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        nodeInsert();
        break;

        case 2:
        nodeDisplay();
        break;

        case default:
        printf("Enter Valid Choice!");
        break;
    }
}
