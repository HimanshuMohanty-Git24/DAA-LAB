// 3.1 Aim of the experiment: Write a function recursiveMin(a, n) that recursively computes the
// minimum value in the input array a and returns it. Initially, n= |a|.
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