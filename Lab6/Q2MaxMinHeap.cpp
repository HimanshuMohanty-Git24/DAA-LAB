#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void maxHeapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void minHeapify(vector<int> &arr, int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void buildAlternatingHeap(vector<int> &arr, int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        maxHeapify(arr, n, 2 * i + 1);
    }

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        minHeapify(arr, n, 2 * i);
    }
}

void display(vector<int> &arr)
{
    for (int value : arr)
    {
        cout << value << " ";
    }
    cout << endl;
}

int main()
{
    int n = 11;
    // cout << "Enter size of array: ";
    // cin >> n;

    vector<int> arr = {20, 15, 18, 10, 8, 12, 9, 6, 4, 8, 10};
    // cout << "Enter elements of the array: ";
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }

    buildAlternatingHeap(arr, n);

    cout << "Output: ";
    display(arr);

    return 0;
}
