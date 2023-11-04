#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
    int i,l,j;
    char txt[30];
    char empty[30];
    char alpha[]=" abcdefghijklmnopqrstuvwxyz";
    printf("Enter : ");
    gets(txt);
    l=strlen(txt);

    for(i=0;i<l;i++)
    {
        for(j=0;j<27;j++)
        {
            empty[i]=alpha[j];
            // system("cls");
            puts(empty);
            if(empty[i]==txt[i])
            {
                break;
            }
        }
    }

}