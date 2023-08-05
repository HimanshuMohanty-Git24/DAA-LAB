// Wap to find the k th and k+1 th fibonacci number print it and then find their GCD
// input : k:10
// output:
// 10th and 11th Fibonacci numbers : 34 55
// GCD = 1

#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int main()
{
    int k;
    cout << "Enter the value of k: ";
    cin >> k;
    int a = 0, b = 1, c;
    for (int i = 2; i <= k + 1; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    cout << k << "th and " << k + 1 << "th Fibonacci numbers : " << a << " " << b << endl;
    cout << "GCD = " << gcd(a, b) << endl;
    return 0;
}