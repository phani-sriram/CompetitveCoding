#include <stdio.h>
int main()
{
    int w;
    scanf("%d", &w);
    //printf("hhlh");
    if(w==0||w==2)
        printf("NO");
    else if(w%2==0)
        printf("YES");
    else
    {
        printf("NO");
    }
    return 0;
    
}