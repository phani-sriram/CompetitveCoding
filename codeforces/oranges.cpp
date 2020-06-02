#include <iostream>

using namespace std;
struct number
{
    int key;
    bool mark;
};

void check(int n, int k, int array[])
{
    struct number array1[n * k];

    for (int i = 0; i < n * k; i++)
    {
        array1[i].key = i + 1;
        array1[i].mark = false;
    }
    for (int i = 0; i < k; i++)
    {
        array1[array[i] - 1].mark = true;
    }
    int partitions[k][n];
    for (int i = 0; i < k; i++)
    {
        partitions[i][0] = array[i];
        int j = 0;
        int counter = 1;

        while (counter < n && i + j < n * k)
        {
            while (array1[j + i].mark == true)
            {
                j++;
            }

            partitions[i][counter] = array1[i + j].key;

            counter++;

            array1[i + j].mark = true;
        }
    }
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << partitions[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    int array[k];
    for (int i = 0; i < k; i++)
    {
        cin >> array[i];
    }
    check(n, k, array);
    return 0;
}