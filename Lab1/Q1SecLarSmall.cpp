#include <bits/stdc++.h>
using namespace std;
int main()
{
    srand(time(0));
    cout << "Enter K: ";
    int k;
    cin >> k;
    cout << "\nEnter n: ";
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        arr.push_back(rand() % 100);
    }
    cout << "Input Array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    int max = INT_MIN, min = INT_MAX;
    for (int i = 0; i < n; i++) // finding max and min
    {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }
    int freq[max + 1] = {0};    // hash map
    for (int i = 0; i < n; i++) // frequency of each element
    {
        freq[arr[i]]++;
    }
    cout << k << "th smallest num: ";
    int count = 0;
    for (int i = 0; i <= max; i++) // finding kth smallest
    {
        if (freq[i] != 0)
        {
            count = count + freq[i];
            if (count >= k)
            {
                cout << i << endl;
                break;
            }
        }
    }
    cout << k << "th largest num: ";
    count = 0;
    for (int i = max; i >= 0; i--) // finding kth largest
    {
        if (freq[i] != 0)
        {
            count = count + freq[i];
            if (count >= k)
            {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}