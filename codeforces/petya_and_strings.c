#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main()
{
    char string1[101];
    char string2[101];
    scanf("%s", string1);
    scanf("%s", string2);
    int len = strlen(string1);
    for(int i =0;i<len;i++)
    {
        string1[i] = tolower(string1[i]);
        string2[i] = tolower(string2[i]);
    }
    for(int i = 0;i<len;i++)
    {
        if((int)string1[i]>(int)string2[i])
        {
            printf("1");
            return 0;
        }
        if((int)string1[i]<(int)string2[i])
        {
            printf("-1");
            return 0;
        }
    }
    printf("0");
    return 0;
}