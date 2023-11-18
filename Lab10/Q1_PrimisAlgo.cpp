#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define INF 99999999

int main()
{
    int n = 9;
    vector<vector<int>> graph = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    int parent[n];
    int key[n];
    bool mstSet[n];
    for (int i = 0; i < n; i++)
    {
        key[i] = INF;
        mstSet[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;
    for (int i = 0; i < n - 1; i++)
    {
        int min = INF, min_index;
        for (int j = 0; j < n; j++)
        {
            if (mstSet[j] == false && key[j] < min)
            {
                min = key[j];
                min_index = j;
            }
        }
        mstSet[min_index] = true;
        for (int j = 0; j < n; j++)
        {
            if (graph[min_index][j] && mstSet[j] == false && graph[min_index][j] < key[j])
            {
                parent[j] = min_index;
                key[j] = graph[min_index][j];
            }
        }
    }
    cout << "Cost adjacency matrix of the minimum spanning tree:\n";
    for (int i = 1; i < n; i++)
    {
        cout << parent[i] << " - " << i << " : " << graph[i][parent[i]] << "\n";
    }
    int total_weight = 0;
    for (int i = 1; i < n; i++)
    {
        total_weight += graph[i][parent[i]];
    }
    cout << "Total cost of the minimum spanning tree: " << total_weight << "\n";
    return 0;
}