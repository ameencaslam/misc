#include <stdio.h>
#include <stdlib.h>
// make head=null del empty common in nodedel function
int count=0,nums=0,ch,data,position;

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

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
    nums++;
}

void insEnd(int data)
{
    struct node *newNode = nodeCreate(data);
    struct node *temp;
    if(head == NULL)
    {
        head=newNode;
        nums++;
        return;
    }
    temp=head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next=newNode;
    nums++;
}

void insMid(int data, int position)
{
    if((position <= 0) || ((position > nums) && (position != 1)))
    {
        printf("\nInvalid Position!\n");
        return;
    }
    
    if(position == 1)
    {
        insBegin(data);
        return;
    }

    if(position == nums)
    {
        insEnd(data);
        return;
    }

    struct node *temp,*newNode=nodeCreate(data);
    temp=head;
    count=1;
    while(count < position-1)
    {
        temp=temp->next;
        count++;
    }

    newNode->next=temp->next;
    temp->next=newNode;
    nums++;
}

void nodeInsert()
{
    printf("\nEnter the Value : ");
    scanf("%d",&data);
    x1:
    printf("\n\n1. Start\n2. End\n3. Custom\n\nEnter where to Insert : ");
    scanf("%d",&ch);
    if(ch == 3)
    {
        printf("\nEnter the Position to Insert : ");
        scanf("%d",&position);
    }
    
    switch(ch)
    {
        case 1:
        insBegin(data);
        break;

        case 2:
        insEnd(data);
        break;

        case 3:
        insMid(data,position);
        break;

        default:
        printf("\nInvalid Choice!\n");
        goto x1;
        break;
    }
}

void delBegin()
{
    struct node *temp;
    temp=head;
    head=temp->next;
    free(temp);
    nums--;
}

void delEnd()
{
    struct node *temp,*temp2;
    temp=head;
    count=1;
    while(count < nums-1)
    {
        temp = temp->next;
        count++;
    }
    temp2 = temp->next;
    temp->next = NULL;
    free(temp2);
    nums--;
}

void delMid(int position)
{
    if((position <= 0) || ((position > nums) && nums != 0))
    {
        printf("\nInvalid Position!\n");
        return;
    }
    
    if(position == 1)
    {
        delBegin();
        return;
    }

    if(position == nums)
    {
        delEnd();
        return;
    }

    struct node *temp,*temp2;
    temp=head;
    count=1;
    while(count < position-1)
    {
        temp=temp->next;
        count++;
    }
    temp2=temp->next;
    temp->next = temp2->next;
    free(temp2);
    nums--;
}

void nodeDelete()
{
    if(nums == 0)
    {
        printf("\nEmpty!\n");
        return;
    }
    x2:
    printf("\n\n1. Start\n2. End\n3. Custom\n\nEnter where to Delete : ");
    scanf("%d",&ch);
    if(ch == 3)
    {
        printf("\nEnter the Position to Insert : ");
        scanf("%d",&position);
    }
    switch(ch)
    {
        case 1:
        delBegin();
        break;

        case 2:
        delEnd();
        break;

        case 3:
        delMid(position);
        break;

        default:
        printf("\nInvalid Choice!\n");
        goto x2;
        break;
    }
}

void nodeDisplay()
{
    if(nums == 0)
    {
        printf("\nEmpty!\n");
        return;
    }
    
    count=1;
    struct node *temp;
    temp=head;
    while(temp->next != NULL)
    {
        printf("\n%d => %d",count,temp->data);
        temp=temp->next;
        count++;
    }
    printf("\n%d => %d\n\n",count,temp->data);
}

void main()
{
    do
    {
        printf("\n1. Insertion\n2. Display\n3. Delete\n4.EXIT\n\nEnter your Choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            nodeInsert();
            break;

            case 2:
            nodeDisplay();
            break;

            case 3:
            nodeDelete();
            break;

            case 4:
            break;

            default:
            printf("\nInvalid Choice!\n");
            break;
        }
    } while (ch != 4);
    printf("\n\nThank you...");
}
