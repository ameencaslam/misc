#include <stdio.h>

int i,x,top=-1,ch;
int stack[10];

void push()
{
    if(top>=10)
    {
        printf("\nOverflow Error");
    }
    else
    {
        top++;
        printf("\nEnter the Element : ");
        scanf("%d",&x);
        stack[top]=x;
    }
}

void pop()
{
    if(top==-1)
    {
        printf("\nEmpty Stack");
    }
    else
    {
        top--;
    }
}

void display()
{
    for(i=top;i>=0;i--)
    {
        printf("\n%d",stack[i]);
    }
}

void main()
{
    do
    {
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. DISPLAY\n");
        printf("4. END\n");
        printf("Enter your Choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
            push();
            break;

            case 2:
            pop();
            break;
            
            case 3:
            display();
            break;

            case 4:
            break;
            
            default:
            printf("\nInvalid Option");
        }

        printf("\n\nTOP = %d | Value = %d\n",top,stack[top]);

    }while(ch!=4);
    printf("Adios...");
}