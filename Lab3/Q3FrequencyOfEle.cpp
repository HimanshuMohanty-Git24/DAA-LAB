// 3.3 Aim of the experiment: To find distinct integers in an array.
// Write a function unique(a) that returns an array of unique elements in input array a. Run the
// function on inputs of following sizes and count the number of basic operations.

#include <bits/stdc++.h>

using namespace std;

vector<int> unique(vector<int> arr)
{ // T.C = O(n)
    int n = arr.size();
    int max = *max_element(arr.begin(), arr.end());
    int freq[max + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }
    vector<int> uniqueArr;
    for (int i = 0; i < max + 1; i++)
    {
        if (freq[i] == 1)
            uniqueArr.push_back(i);
    }
    return uniqueArr;
}

int main(int argc, char const *argv[])
{
    vector<int> arr;
    int n;
    cout << "Enter size of array : ";
    cin >> n;
    cout << "Enter elements of array : ";
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    vector<int> uniqueArr = unique(arr);
    cout << "Unique elements are : ";
    for (auto i : uniqueArr)
    {
        cout << i << " ";
    }
    return 0;
}
