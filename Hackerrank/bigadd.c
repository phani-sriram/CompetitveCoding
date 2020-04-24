#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    long int array[n];
    for(int i = 0;i<n;i++)
        scanf("%ld", &array[i]);
    long int sum = 0;
    for(int i = 0;i<n;i++)
        sum  = sum + array[i];
    printf("%ld", sum);
}