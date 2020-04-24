// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/update-and-query/



#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include<string.h>
#define INT_MAX 2147483646
#define INT_MIN -2147483646


int closest_two_power(int n)
{
    int i=0;
    int tempn = n;
    while(n>0)
    {
        n = n/2;
        i++;
    }
    if(pow(2, i-1) == tempn)
    {
        return tempn;
    }
    else
    {
        return pow(2, i);
    }
}


void BuildMaxSegmentTree(int array[], int segment_tree[], int n)
{
    for(int i = 0; i<n; i++)
    {
        segment_tree[n-1+i] = i;
    }
    for(int i = n-2; i > -1; i--)
    {
        if(array[segment_tree[2*i+1]] < array[segment_tree[2*i+2]])
        {
            segment_tree[i] = segment_tree[2*i+2];
        }
        else
        {
            segment_tree[i] = segment_tree[2*i+1];
        }
    }
}

void BuildMinSegmentTree(int array[], int segment_tree[], int n)
{
    for(int i = 0; i<n; i++)
    {
        segment_tree[n-1+i] = i;
    }
    for(int i = n-2; i > -1; i--)
    {
        if(array[segment_tree[2*i+1]] > array[segment_tree[2*i+2]])
        {
            segment_tree[i] = segment_tree[2*i+2];
        }
        else
        {
            segment_tree[i] = segment_tree[2*i+1];
        }
    }
}




void UpdateMaxSegmentTree(int array[], int segment_tree[], int n, int index, int value)
{
    array[index] = value;
    int parent = ((n-1+index)-1)/2;

    while( parent > 0 )
    {
        if(array[segment_tree[2*parent+1]] < array[segment_tree[2*parent+2]])
        {
            segment_tree[parent] = segment_tree[2*parent+2];
        }
        else{
            segment_tree[parent] = segment_tree[2*parent+1];
        }
        parent = (parent-1)/2;
    }

    segment_tree[0] = array[segment_tree[1]] < array[segment_tree[2]] ? segment_tree[2] : segment_tree[1];
}

void UpdateMinSegmentTree(int array[], int segment_tree[], int n, int index, int value)
{
    array[index] = value;
    int parent = ((n-1+index)-1)/2;

    while( parent > 0 )
    {
        if(array[segment_tree[2*parent+1]] > array[segment_tree[2*parent+2]])
        {
            segment_tree[parent] = segment_tree[2*parent+2];
        }
        else{
            segment_tree[parent] = segment_tree[2*parent+1];
        }
        parent = (parent-1)/2;
    }

    segment_tree[0] = array[segment_tree[1]] > array[segment_tree[2]] ? segment_tree[2] : segment_tree[1];
}



int RangeMaxQuery(int array[], int segment_tree[], int n, int i, int j, int start, int end, int root)
{    
    if (start > j || end < i)
    {
        return n;
    }
    else if (start >= i && end <= j)
    {
        return segment_tree[root];
    }

    int mid = (start+end)/2;

    int left = RangeMaxQuery(array,segment_tree,n,i,j,start,mid,2*root+1);
    int right = RangeMaxQuery(array,segment_tree,n,i,j,mid+1,end,2*root+2);

    if(array[left] > array[right])
        return left;
    else
        return right;
}

int RangeMinQuery(int array[], int segment_tree[], int n, int i, int j, int start, int end, int root)
{    
    if (start > j || end < i)
    {
        return n;
    }
    else if (start >= i && end <= j)
    {
        return segment_tree[root];
    }

    int mid = (start+end)/2;

    int left = RangeMinQuery(array,segment_tree,n,i,j,start,mid,2*root+1);
    int right = RangeMinQuery(array,segment_tree,n,i,j,mid+1,end,2*root+2);

    if(array[left] < array[right])
        return left;
    else
        return right;
}

int Query(int max_array[], int min_array[], int max_seg_tree[], int min_seg_tree[], int n, int X, int c)
{
    int left = 1;
    int right = n-X;
    int mean, flag;
    while(left<right)
    {
        mean = (left+right)/2;
        int min = RangeMinQuery(min_array, min_seg_tree, n, X, X+mean-1, 0, n-1, 0);
        int max = RangeMaxQuery(max_array, max_seg_tree, n, X, X+mean-1, 0, n-1, 0);
        if(min_array[X]-c <= min_array[min] && max_array[max]<=max_array[X]+c)
        {
            left = mean+1;
            flag = 1; 
        }
        else
        {
            right = mean;
            flag = 0;
        }
    }
    if(flag == 1)
        return mean;
    else
    {
        return mean-1;
    }
}


int minimum_query(int max_array[], int min_array[], int max_seg_tree[], int min_seg_tree[], int n, int X, int len)
{
    int min = RangeMinQuery(min_array, min_seg_tree, n, X, X+len-1, 0, n-1, 0);
    int max = RangeMaxQuery(max_array, max_seg_tree, n, X, X+len-1, 0, n-1, 0);
    int a = min_array[X] - min_array[min];
    int b = max_array[max] - max_array[X];

    if(b>a)
    {
        return b;
    }
    else
    {
        return a;
    }
    
}



int main()
{
    int num, q;
    scanf("%d %d", &num ,&q);
    
    int n = closest_two_power(num);

    int max_array[n+1];
    int min_array[n+1];
    int max_ST[2*n+1];
    int min_ST[2*n+1];

    for(int i = 0;i<num;i++)
    {
        scanf("%d", &max_array[i]) ;
        min_array[i] = max_array[i];
    }

    for(int i = num;i<n;i++)
    {
        max_array[i] = INT_MAX;
        min_array[i] = INT_MIN;
    }
    max_array[n] = INT_MIN;
    min_array[n] = INT_MAX;

    BuildMaxSegmentTree(max_array, max_ST, n);
    BuildMinSegmentTree(min_array, min_ST, n);
    for(int i = 0;i<q; i++)
    {
        char query[2];
        int x, y ;
        scanf("%s%d%d", query, &x, &y);
        if(query[0] == 'Q')
        {
            if(y > 0)
            {
                int len = Query(max_array, min_array, max_ST, min_ST, n, x-1, y);
                int minZ = minimum_query(max_array, min_array, max_ST, min_ST, n, x-1, len);
                printf("%d %d\n", len, minZ);
            
            }
            else
            {
                printf("-1 -1\n");    
            }
        }
        else if(query[0] == 'U') 
        {
            UpdateMaxSegmentTree(max_array, max_ST, n, x-1, y);
            UpdateMinSegmentTree(min_array, min_ST, n, x-1, y);
            
        }
    }
    return 0;

    
}

