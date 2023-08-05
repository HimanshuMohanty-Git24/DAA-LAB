// 2.2 Aim of the experiment: Write a function sine(x, d) that returns the sine of input x accurately
// upto d decimal places computed using Taylor's series approximation of sine.
// Input: Enter x - 25.56
// Enter decimal places - 3
// Output: 0.431
#include <bits/stdc++.h>
using namespace std;

double power(double x, int n)
{
    double ans = 1;
    for (int i = 1; i <= n; i++)
        ans *= x;
    return ans;
}
double sine(double x, int d)
{
    double sum = 0, term = x, eps = pow(10, -d - 1);
    int i = 1;
    while (abs(term) > eps)
    {
        sum += term;
        term = -term * x * x / (2 * i * (2 * i + 1));
        i++;
    }
    return sum;
}
int main()
{
    double x;
    int d;
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter decimal places: ";
    cin >> d;
    cout << "Sine of " << x << " upto " << d << " decimal places is: " << sine(x, d) << endl;
    return 0;
}