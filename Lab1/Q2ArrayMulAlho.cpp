#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {3, 4, 5, 1, 2};
    int allMul = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        allMul = allMul * arr[i];
    }
    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = allMul / arr[i];
        cout << arr[i] << " ";
    }

    return 0;
}