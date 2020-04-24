//  https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/akash-and-too-many-assignments/



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int closest_two_power(int n)
{
    int i=0;
    int tempn = n;
    while(n>0)
    {
        n = n/2;
        i++;
    }
    if((int)pow(2, i-1) == tempn)
    {
        return tempn;
    }
    else
    {
        return (int)pow(2, i);
    }
}
void build_seg_tree(char string[],  int* segment_tree[],  int n, int k)                                                           
{
    for(int i =0;i<strlen(string);i++)
    {
        if((int)string[i] == ((int)'a' + k))
            segment_tree[k][n+i-1] = 1;
        else
        {
            segment_tree[k][n+i-1] = 0;
        }
    }
    for(int i = strlen(string);i<n;i++)
    {
        segment_tree[k][n+i-1] = 0;
    }
    for(int i = n-2; i>=0;i--)
    {
        segment_tree[k][i] = segment_tree[k][2*i + 1] + segment_tree[k][2*i + 2];
    }
}
int range_sum_query(int segment_tree[], int i, int j, int s, int e, int p)
{
    if(j<s || i>e)
    {
        return 0;
    }
    if(i<=s && e<=j)
    {
        return segment_tree[p];
    }
    int m = (s+e)/2;
    int l1 = range_sum_query(segment_tree,i, j, s, m, 2*p + 1 );
    int l2 = range_sum_query(segment_tree, i, j, m+1, e, 2*p + 2);
    return l1+l2;
}
void update(int* segment_tree[], char string[], int index, char character, int n)
{
    index--;
    int k = string[index] - 'a';
    string[index] = character;
    segment_tree[k][n-1+index] = 0;
    segment_tree[character - 'a'][n-1+index] = 1;
    int parent = (n-2-index)/2;
    while(parent >= 0)
    {
        segment_tree[k][parent] --;
        segment_tree[character-'a'][parent] ++;
        if(parent == 0)
            break;
        parent = (parent-1)/2;

    }
}
int kthsmallestcharacter(int* segment_tree[], int n, int left, int right, int k)
{
    int f = 0;
    if(k<=0)
        return -1;
    for(int i = 0;i <26;i++)
    {
        if(k-f < 0)
            return -1;
        f = f + range_sum_query(segment_tree[i], left-1, right-1, 0, n-1, 0);
        if(f>=k)
            return i;

    }
    return -1;
}
    

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    
    
    int k = closest_two_power(n);
    char* string = calloc(k, sizeof(char));
    scanf("%s", string);
    int* segment_tree[26];
    for(int i = 0;i<26;i++)
    {
        segment_tree[i] = malloc(sizeof(int)*(2*k-1));
    }
    for(int i = 0;i<26;i++)
    {
        build_seg_tree(string, segment_tree, k,  i);
    }
    for(int i = 0;i<m;i++)
    {
        int op_code;
        scanf("%d", &op_code);
        if(op_code == 1)
        {
            int left, right;
            int m;
            scanf("%d%d%d", &left, &right, &m);
            int l = kthsmallestcharacter(segment_tree, k, left, right, m);
            if(l == -1)
                printf("Out of range\n");
            else
            {
                printf("%c\n", l+'a');
            }

        }
        else
        {
            int index;
            char operation[2];
            scanf("%d", &index);
            scanf("%s", string);
            update(segment_tree, string, index, string[0], k);
        }

    }
    /*for(int i = 0;i<26;i++)
    {
        for(int j = 0;j<2*k-1;j++)
        {
            printf("%d ", segment_tree[i][j]);
        }
        printf("\n");
    }*/
     //printf("Range sum query : %d\n",(range_sum_query(segment_tree[1],1 , 4, 0, k-1, 0)));

    return 0;


}
