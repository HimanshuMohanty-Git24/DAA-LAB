// 7.1 Aim of the experiment: Write a program to find the maximum profit nearest to but not
// exceeding the given knapsack capacity using the Fractional Knapsack algorithm. Notes# Declare a structure ITEM having members value and weight. Apply heap sort technique
// to sort the items in non-increasing order, according to their value/weight.
#include <bits/stdc++.h>
using namespace std;
struct item
{
    int value;
    int weight;
    float ratio;
};

void knapsack(item arr[], int n, int capacity)
{
    // Sorting should be in descending order using library function:
    sort(arr, arr + n, [](item a, item b)
         { return a.ratio > b.ratio; });
    float profit = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].weight <= capacity)
        {
            profit += arr[i].value;
            capacity -= arr[i].weight;
        }
        else
        {

            profit += arr[i].value * ((double)capacity / (double)arr[i].weight);
            break;
        }
    }
    cout << "Maximum profit: " << profit << endl;
}

int main()
{
    int n, capacity;
    cout << "Enter the number of items: ";
    cin >> n;
    item arr[n];
    cout << "Enter the Value of item : ";
    for (int i = 0; i < n; i++)
        cin >> arr[i].value;
    cout << "Enter the weight of item : ";
    for (int i = 0; i < n; i++)
        cin >> arr[i].weight;
    cout << "Enter the capacity of knapsack:";
    cin >> capacity;
    for (int i = 0; i < n; i++)
        arr[i].ratio = (float)arr[i].value / arr[i].weight;
    knapsack(arr, n, capacity);
    cout << "Item No\tValue\tWeight\tAmount to be taken" << endl;
    for (int i = 0; i < n; i++)
        cout << i + 1 << "\t" << arr[i].value << "\t" << arr[i].weight << "\t" << arr[i].ratio << endl;
    return 0;
}