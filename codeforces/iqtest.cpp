#include <iostream>

using namespace std;
int even_different(int n, int array[])
{
    int count_even = 0;
    int count_odd = 0;
    int index_odd = -1;
    int index_even = -1;
    for (int i = 0; i < n; i++)
    {
        if (array[i] % 2 == 0)
        {
            count_even++;

            index_even = i;
        }
        else
        {
            count_odd++;

            index_odd = i;
        }
    }
    if (count_odd > 1)
    {
        return index_even + 1;
    }
    else if (count_even > 1)
    {
        return index_odd + 1;
    }
}

int main()
{
    int n;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    int k = even_different(n, array);
    cout << k << endl;
    return 0;
}