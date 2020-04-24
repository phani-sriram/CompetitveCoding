#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main()
{
    char string[101];
    scanf("%s", string);
    char string1[202];
    char vowels[12] = {'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'};
    
    int j =0 ;
    for(int i = 0;i<strlen(string);i++)
    {
        char c = string[i];
        int flag_vowels=0;
        for(int j = 0;j<12;j++)
        {
                            

            if(c == vowels[j])
            {
                flag_vowels = 1;
                break;
            }
        }
        if(flag_vowels == 0)
        {
            char temp = tolower(c);
            printf(".%c", temp);
        }
    }
}