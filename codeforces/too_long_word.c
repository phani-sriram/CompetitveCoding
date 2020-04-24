#include <stdio.h>
#include <string.h>
int main()
{
    int n;
    scanf("%d", &n);
    char array[n][101];
    for(int i =0;i<n;i++)
    {
        scanf("%s", array[i]);
    }
    for(int i =0 ;i<n;i++)
    {
        if(strlen(array[i])>10 && strlen(array[i])<100)
        {
            // printf("this string is too long\n");
            printf("%c", array[i][0]);
            printf("%ld", strlen(array[i])-2);
            printf("%c\n", array[i][strlen(array[i])-1]);
        }
        else if(strlen(array[i])==100)
        {
            printf("%c", array[i][0]);
            printf("98");
            printf("%c\n", array[i][99]);
        }
        else
        {
            printf("%s\n", array[i]);
        }
        //printf("%ld\n", strlen(array[i]));
        
    }
    return 0;   
    
    
}