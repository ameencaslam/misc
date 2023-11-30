#include <stdio.h>
#include <string.h>

void main()
{
    int i,j,len1,len2,count=0,count2,num=0;
    char str[100],pat[100];
    
    printf("Input the String : ");
    gets(str);
    printf("Input the Pattern : ");
    gets(pat);

    len1=strlen(str);
    len2=strlen(pat);
    for(i=0;i<=len1-len2;i++)
    {
        count2=0;
        for(j=0;j<len2;j++)
        {
            if(str[i+j]==pat[j])
            {
                count2++;
            }
        }
        if(count2==len2)
        {
            printf("\nMatch in Index %d",count);
            num++;
        }
        count++;
    }
    if(num==0)
    {
        printf("No Match Found");
    }
}
