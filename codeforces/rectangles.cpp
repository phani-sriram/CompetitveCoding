//codeforces.com/contest/610/problem/A
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n == 0 || n % 2 != 0)
    {
        cout << "0\n";
        return 0;
    }
    else
    {
        int count = 0;
        int k = n / 2;
        float z = k / 2;
        for (int i = 1; i <= ceil(z); i++)
        {
            if (i != k - i)
                count++;
        }
        cout << count << endl;
    }
}