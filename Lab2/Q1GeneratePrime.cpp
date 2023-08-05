// Wap to genrate all the prime inside a range taken as n input from user
#include <bits/stdc++.h>

using namespace std;

void genratePrime(int n)
{
    int i, j, flag;
    cout << "Prime numbers between 1 to " << n << " are: ";
    for (i = 2; i <= n; i++)
    {
        flag = 0;
        for (j = 2; j <= i / 2; j++)
        {
            if (i % j == 0)
            {
                flag = 1;
                break;
            }
        }
        if (!flag)
            cout << i << " ";
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter the range: ";
    cin >> n;
    genratePrime(n);
    return 0;
}
