#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

int cost[11][11];               // cost-adjacency matrix
vector<pair<int, int>> MST[11]; // minimum-cost spanning tree in cost-adjacency list representation

void addEdge(int u, int v, int w)
{
    cost[u][v] = w;
    cost[v][u] = w;
}

void prim(int s)
{
    int parent[11]; // parent array
    int key[11];    // key values
    bool inMST[11]; // to check if a vertex is included in MST

    for (int i = 1; i <= 10; i++)
    {
        key[i] = INF;
        inMST[i] = false;
        parent[i] = -1;
    }

    key[s] = 0;

    for (int count = 1; count <= 10; count++)
    {
        int u = -1;

        for (int i = 1; i <= 10; i++)
        {
            if (!inMST[i] && (u == -1 || key[i] < key[u]))
            {
                u = i;
            }
        }

        inMST[u] = true;

        for (int v = 1; v <= 10; v++)
        {
            if (cost[u][v] != 0 && !inMST[v] && cost[u][v] < key[v])
            {
                key[v] = cost[u][v];
                parent[v] = u;
            }
        }
    }

    for (int i = 1; i <= 10; i++)
    {
        if (parent[i] != -1)
        {
            MST[parent[i]].push_back({i, cost[i][parent[i]]});
            MST[i].push_back({parent[i], cost[i][parent[i]]});
        }
    }
}

int main()
{
    for (int i = 1; i <= 10; i++)
    {
        for (int j = i + 1; j <= 10; j++)
        {
            if (j % i == 0 || j == i + 1)
            {
                int w = (i + j) * (i + j) % 100;
                addEdge(i, j, w);
            }
        }
    }

    prim(1);

    for (int i = 1; i <= 10; i++)
    {
        cout << "Vertex: " << i << endl;
        for (auto it : MST[i])
        {
            cout << "Connected to: " << it.first << ", Cost: " << it.second << endl;
        }
        cout << endl;
    }

    return 0;
}
