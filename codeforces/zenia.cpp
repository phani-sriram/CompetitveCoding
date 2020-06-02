#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void build_seg_tree(vector<int> segment_tree, vector<int> base, int n)
{
    int level = 0;
    for (int i = 0; i < n; i++)
    {

        segment_tree[n + i - 1] = base[i];
    }
    level = 2;
    int identifier = 1;
    while (level != n)
    {
        while (identifier % (pow(2, n - level)) != 0)
        {
            if (level % 2 == 0)
                segment_tree[identifier] = segment_tree[2 * identifier + 1] | segment_tree[2 * identifier + 2];
            else
            {
                segment_tree[identifier] = segment_tree[2 * identifier + 1] ^ segment_tree[2 * identifier + 2];
            }
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> base;
    base.reserve(pow(2, n));
    int p = pow(2, n);
    for (int i = 0; i < n; i++)
    {
        cin >> base[i];
    }
    vector<int> segment_tree[2 * p + 1];

    return 0;
}