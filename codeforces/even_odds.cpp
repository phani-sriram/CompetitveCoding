#include <iostream>
#include <vector>

using namespace std;

int kth_new_order(int n, int k, vector<int> v)
{

    for (int i = 1; i <= n; i++)
    {
        if (i % 2 != 0)
        {
            v.push_back(i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            v.push_back(i);
        }
    }

    return v[k - 1];
}
int main()
{
    long n, k;
    cin >> n >> k;
    vector<int> v;
    int ans = kth_new_order(n, k, v);
    cout << ans << endl;
    return 0;
}