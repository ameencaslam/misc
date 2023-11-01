#include <stdio.h>
#include <string.h>

void main()
{
    char txt[1000];
    int i,c=0,w=1,s=0,l;

    printf("Enter the Paragraph : \n\n");
    gets(txt);
    l=strlen(txt);

    for(i=0;i<l;i++)
    {
        if(txt[i] == ' ')
        {
            w++;
        }
        else if(txt[i] == '.')
        {
            s++;
        }
        else
        {
            c++;
        }
    }

    printf("Characters = %d\n",c);
    printf("Words = %d\n",w);
    printf("Sentences = %d\n",s);

}