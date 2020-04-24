#include <stdio.h>
#include <stdlib.h>
int* records(int n, int array[])
{
    int*returner = malloc(sizeof(int)*2);
    returner[0] = 0;
    returner[1] = 0;
    int max = array[0];
    int min = array[0];
    for(int i =1;i<n;i++)
    {
        if(array[i]>max)
        {
            max = array[i];
            returner[0]++;
        }
        if(array[i]<min)
        {
            min = array[i];
            returner[1]++;
        }
    }
    return returner;
}
int main()
{
    int n;
    scanf("%d", &n);
    int array[n];
    // array = (int*)malloc(n*sizeof(int));
    for(int i =0 ;i<n;i++)
        scanf("%d", &array[i]);
    int*returner = malloc(sizeof(int)*2);
    returner = records(n, array);
    printf("%d %d", returner[0], returner[1]);
    return 0;
}