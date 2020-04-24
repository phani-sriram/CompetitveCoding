#include <stdio.h>
int main()
{
    int alice[3];
    for(int i = 0;i<3;i++)
        scanf("%d", &alice[i]);
    int bob[3];
    for(int i = 0;i<3;i++)
        scanf("%d", &bob[i]);
    int al = 0;
    int bo = 0;
    for(int i = 0;i<3;i++)
    {
        if(alice[i]>bob[i])
            al++;
        else if(alice[i]<bob[i])
            bo++;
    }
    printf("%d %d", al, bo);
    return 0;
}