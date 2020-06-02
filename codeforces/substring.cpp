#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

bool checks_if_repeats(string str, int string_length, int sub_length)
{
    if (sub_length == 0)
        return false;
    unordered_multimap<string, int> hash_table;
    for (int i = 0; i <= string_length - sub_length; i++)
    {
        string temp = str.substr(i, sub_length);
        auto itr = hash_table.find(temp);
        if (itr != hash_table.end())
            return true;
        pair<string, int> pair1;
        pair1.first = temp;
        pair1.second = i;
        hash_table.insert(pair1);
    }
    return false;
}

int binary_search(string str, int string_length) //has to be fixed
{
    float left = 0;
    float right = string_length;
    float mean;
    while (left < right)
    {
        mean = ceil((left + right) / 2);

        if (checks_if_repeats(str, string_length, mean) == true)
        {

            left = mean;
        }
        else
        {
            right = mean - 1;
        }

        if (left == right)
        {
            return left;
        }
    }
    return -1;
}
int main()
{
    string str;
    cin >> str;
    int len = str.length();

    int len1 = binary_search(str, len);
    int k = 0;
    if (len1 == -1)
        cout << k << endl;
    else
        cout << len1 << endl;
    return 0;
}