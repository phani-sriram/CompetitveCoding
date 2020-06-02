//codeforces.com/contest/805/problem/B

#include <stdio.h>
void make_palindrome(int n, char str[])
{
    if (n == 0)
        return;
    str[0] = 'a';
    if (n == 1)
        return;
    str[1] = 'a';
    if (n == 2)
        return;
    str[2] = 'b';
    if (n == 3)
        return;
    for (int i = 3; i < n; i++)
    {
        if (str[i - 1] == 'a' && str[i - 2] == 'a')
            str[i] = 'b';
        else if (str[i - 1] == 'b' && str[i - 2] == 'b')
            str[i] = 'a';
        else if (str[i - 1] == 'a' && str[i - 2] == 'a')
            str[i] = 'b';
        else if (str[i - 1] == 'a' && str[i - 2] == 'c')
            str[i] = 'b';
        else if (str[i - 1] == 'c' && str[i - 2] == 'a')
            str[i] = 'b';
        else if (str[i - 1] == 'a' && str[i - 2] == 'b')
        {
            str[i] = 'a';
        }
        else if (str[i - 1] == 'b' && str[i - 2] == 'a')
            str[i] = 'b';
        else if (str[i - 1] == 'b' && str[i - 2] == 'c')
            str[i] = 'a';
        else if (str[i - 1] == 'c' && str[i - 2] == 'b')
            str[i] = 'a';
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    char string[n];
    make_palindrome(n, string);
    for (int i = 0; i < n; i++)
        printf("%c", string[i]);
    printf("\n");
    return 0;
}