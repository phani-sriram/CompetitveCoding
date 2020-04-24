#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    scanf("%d", &n);
    int array[n][n];
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            scanf("%d", &array[i][j]);
        }
    }
    int sum1 = 0;
    int sum2 = 0;
    for(int i = 0;i<n;i++)
    {
        sum2 = sum2 + array[i][n-i-1];
        sum1 = sum1 + array[i][i];
    }
    printf("%d", abs(sum2-sum1));
    return 0;
    
    
}