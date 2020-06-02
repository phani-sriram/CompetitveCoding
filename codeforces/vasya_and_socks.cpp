#include <iostream>

using namespace std;

int days(int n, int m)
{
    int i = 0;
    int days = 0;
    while (n + i > 0)
    {
        if (days % m == 0)
            i++;
        n--;
        if (n + i == 0)
            return days;
        days++;
    }
    return days;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int k = days(n, m);
    cout << k << endl;
    return 0;
}