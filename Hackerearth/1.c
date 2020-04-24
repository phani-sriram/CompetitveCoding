//  https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/k-th-bit-faae0e0d/



#include <stdio.h>
#include <math.h>
void build_seg_tree(long long int array[], long long int segment_tree[], long long int n)
{
    for(long long int i =0;i<n;i++)
    {
        segment_tree[n+i-1] = array[i];
    }
    for(long long int i = n-2; i>=0;i--)
    {
        segment_tree[i] = segment_tree[2*i + 1] + segment_tree[2*i + 2];
    }
}
void update(long long int segment_tree[], long long int array[], long long int i, long long int n)
{
    i -= 1;
    array[i] = 0;
    i = n + i -1;
    segment_tree[i] = 0;
    i = (i-1)/2;
    while(i>=0)
    {
        segment_tree[i] = segment_tree[2*i + 1] + segment_tree[2*i + 2];
        if(i == 0)
            break;
        i = (i-1)/2;
    }
}

int closest_two_power(long long int n)
{
    long long int i=0;
    long long int tempn = n;
    while(n>0)
    {
        n = n/2;
        i++;
    }
    if((long long int)pow(2, i-1) == tempn)
    {
        return tempn;
    }
    else
    {
        return (long long int)pow(2, i);
    }
}
void print_index_kth(long long int segment_tree[], long long int l, long long int array[], long long int k)
{
    long long int p = 0;
    while(p < l-1)
    {
        if(segment_tree[p] >= k)
        {
            if(segment_tree[2*p + 1]>=k)
            {
                p = 2*p + 1;
            }
            else
            {
                k = k - segment_tree[2*p + 1];
                p = 2*p + 2;
            }
        }
        else
        {
            printf("-1\n");
            return;
        }
    }
    printf("%lld\n", p - l+2);
}



int main()
{
    long long int n, m;
    scanf("%lld", &n);
    scanf("%lld", &m);
    
    
    long long int l = closest_two_power(n);
    long long int array[l];
    for(long long int i = 0;i<n;i++)
    {
        array[i] = 1;
    }
    for(long long int i = n;i<l;i++)
    {
        array[i] = 0;
    }
    long long int segment_tree[2*l];
    build_seg_tree(array, segment_tree, l);
    
    long long int operations[2];
    long long int i1, i2;
    for(int i = 0;i<m;i++)
    {
        scanf("%lld%lld", &i1, &i2);
        operations[0] = i1;
        operations[1] = i2;
        if(operations[0] == 0)
        {
            update(segment_tree, array, operations[1], l);
            
        }
        if(operations[0] == 1)
        {
            print_index_kth(segment_tree, l, array, operations[1]);
        }
    
    }
    return 0;
    


}
