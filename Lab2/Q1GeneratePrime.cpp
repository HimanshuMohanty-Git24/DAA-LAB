// Wap to genrate all the prime inside a range taken as n input from user
#include <bits/stdc++.h>

using namespace std;

void genratePrime(int n)
{
    int i, j, flag;
    int outer_loop = 0, inner_loop = 0;
    float c1, c2;
    cout << "Prime numbers between 1 to " << n << " are: ";
    for (i = 2; i <= n; i++)
    {
        outer_loop++;
        flag = 0;
        for (j = 2; j <= i / 2; j++)
        {
            inner_loop++;
            if (i % j == 0)
            {
                flag = 1;
                break;
            }
        }
        if (!flag)
            cout << i << " ";
    }
    c1 = (float)outer_loop / (float)n;
    c2 = (float)inner_loop / (float)n;
    cout << endl;
    cout << "Outer loop executes " << outer_loop << " times and inner loop executes " << inner_loop << " times.";
    cout << "\nComplexity of outer loop: " << c1;
    cout << "\nComplexity of inner loop: " << c2;
}

int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter the range: ";
    cin >> n;
    genratePrime(n);
    return 0;
}
