// Wap to find the k th and k+1 th fibonacci number print it and then find their GCD
// input : k:10
// output:
// 10th and 11th Fibonacci numbers : 34 55
// GCD = 1

#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    static int ctr = 0;
    ctr++;
    cout << "Call " << ctr << " : a = " << a << " b = " << b << endl;
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
    for (int i = 2; i <= k; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    cout << k << "th and " << k + 1 << "th Fibonacci numbers : " << a << " " << b << endl;
    int ans = gcd(a, b);
    cout << "GCD = " << ans << endl;
    return 0;
}