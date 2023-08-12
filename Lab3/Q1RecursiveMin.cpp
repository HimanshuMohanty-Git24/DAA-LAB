// 3.1 Aim of the experiment: Write a function recursiveMin(a, n) that recursively computes the
// minimum value in the input array a and returns it. Initially, n= |a|.
// Count the depth of recursion for input a of different sizes and record your observations below
// check if the value of estimated parameter c1 is stable or changing according to the input size. Justify your observation
// Input: Enter size of array : 100
// Output: Minimum value = 12
// Size of problem|a| |Observed depth of recursion d(recur) |Estimated parameter c1 = d(recur)/|a|
// 100               |
// 10000             |
// 1000000           |
// find the depth of recursion and also find the estimated parameter c1
#include <bits/stdc++.h>

using namespace std;

static int d = 0;
static int c1 = 0;

int recursiveMin(int a[], int n)
{
    d++;
    if (n == 1)
        return a[0];
    return min(a[n - 1], recursiveMin(a, n - 1));
}

int main()
{
    int n;
    cout << "Enter size of array : ";
    cin >> n;
    int a[n];
    cout << "Enter elements of array : ";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "Minimum value = " << recursiveMin(a, n);
    c1 = d / n;
    cout << "Depth of recursion = " << d << "\n";
    cout << "C1 = " << c1 << "\n";
    return 0;
}