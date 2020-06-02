// codeforces.com/contest/805/problem/B

#include <iostream>

using namespace std;
string make_palindrome(int n, string *stri)
{
    (*stri)[0] = 'a';
    cout << "String value is : " << (*stri)[0] << endl;
    // cout << 'a';
    string str;
    str[0] = 'z';
    cout << "String value 2 is : " << str[0] << endl;
    if (n == 1)
    {

        return str;
    }
    cout << 'a';

    if (n == 2)
    {
        cout << "\n";

        return str;
    }
    cout << 'b';
    if (n == 3)
    {
        cout << "\n";

        return str;
    }
    for (int i = 3; i < n; i++)
    {
        if (str[i - 1] == 'a' && str[i - 2] == 'a')
            cout << 'b';
        else if (str[i - 1] == 'b' && str[i - 2] == 'b')
            cout << 'a';
        else if (str[i - 1] == 'a' && str[i - 2] == 'a')
            cout << 'b';
        else if (str[i - 1] == 'a' && str[i - 2] == 'c')
            cout << 'b';
        else if (str[i - 1] == 'c' && str[i - 2] == 'a')
            cout << 'b';
        else if (str[i - 1] == 'a' && str[i - 2] == 'b')
            cout << 'b';
        else if (str[i - 1] == 'b' && str[i - 2] == 'a')
            cout << 'a';
        else if (str[i - 1] == 'b' && str[i - 2] == 'c')
            cout << 'a';
        else if (str[i - 1] == 'c' && str[i - 2] == 'b')
            cout << 'a';
    }
    cout << "\n";

    return str;
}

int main()
{
    int n;
    cin >> n;
    string str;
    make_palindrome(n, &str);
    return 0;
}