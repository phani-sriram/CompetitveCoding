#include <stdio.h>
void merge(int left[], int right[], int array[], int ll, int lr)
{
    int i = 0, j = 0, k = 0;
    while (i < ll && j < lr)
    {
        //printf("Seg check 1\n");
        if (left[i] <= right[j])
        {
            array[k] = left[i];
            i++;
        }
        else
        {
            array[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < ll)
    {
        array[k] = left[i];
        i++;
        k++;
    }
    while (j < lr)
    {
        array[k] = right[j];
        j++;
        k++;
    }
    return;
}
void mergesort(int array[], int l)
{
    int n = l;
    if (n < 2)
        return;
    int mid = n / 2;
    int left[mid];
    int right[n - mid];
    for (int i = 0; i < mid; i++)
        left[i] = array[i];
    for (int i = mid; i < n; i++)
        right[i - mid] = array[i];
    mergesort(left, mid);
    mergesort(right, n - mid);
    merge(left, right, array, mid, n - mid);
    return;
}

int main()
{
    int n;
    scanf("%d", &n);
    int array[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    mergesort(array, n);
    int sum_left = 0;
    int sum_right = 0;
    for (int i = 0; i < n; i++)
    {
        sum_left += array[i];
    }
    int count = 0;
    int i = n - 1;
    while (sum_left > sum_right)
    {

        sum_right += array[i];
        sum_left -= array[i];
        if (sum_right > sum_left)
            break;
        i--;
        count++;
    }
    printf("%d", count + 1);
    return 0;
}