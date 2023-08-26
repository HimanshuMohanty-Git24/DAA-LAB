// Aim of the experiment: Write a program to implement Linear search to give the position of first appearance of the element being searched.

#include <bits/stdc++.h>
using namespace std;
int LinearSearch(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
            return i;
    }
    return -1;
}
int main()
{
    int n, x;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter the element to be searched: ";
    cin >> x;
    int result = LinearSearch(arr, n, x);
    if (result == -1)
        cout << "Element is not present in the array";
    else
        cout << "Element is present at index " << result;
    return 0;
}