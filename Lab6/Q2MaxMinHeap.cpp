#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Helper function to perform max-heapify
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

// Helper function to perform min-heapify
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

// Build alternating min-max heap
void buildAlternatingHeap(vector<int> &arr, int n)
{
    // Build max heap starting from index 1
    for (int i = 1; i < n; i += 2)
    {
        maxHeapify(arr, n, i);
    }

    // Build min heap starting from index 0
    for (int i = 0; i < n; i += 2)
    {
        minHeapify(arr, n, i);
    }
}

// Display the elements of the array
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
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    buildAlternatingHeap(arr, n);

    cout << "Output: ";
    display(arr);

    return 0;
}
