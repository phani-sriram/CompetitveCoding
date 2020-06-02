#include <iostream>

using namespace std;

bool check(int n, int n1, int n2, int array1[], int array2[])
{
    int array3[n];
    for (int i = 0; i < n; i++)
    {
        array3[i] = i + 1;
    }
    for (int i = 0; i < n1; i++)
    {
        array3[array1[i] - 1] = 0;
    }
    for (int i = 0; i < n2; i++)
    {
        array3[array2[i] - 1] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (array3[i] != 0)
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    int n1;
    cin >> n1;
    int array1[n1];
    for (int i = 0; i < n1; i++)
    {
        cin >> array1[i];
    }
    int n2;
    cin >> n2;
    int array2[n2];
    for (int i = 0; i < n2; i++)
    {
        cin >> array2[i];
    }
    if (!check(n, n1, n2, array1, array2))
    {
        cout << "Oh, my keyboard!\n";
    }
    else
    {
        cout << "I become the guy." << endl;
    }
    return 0;
}