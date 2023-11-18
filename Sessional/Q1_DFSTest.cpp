#include <bits/stdc++.h>
using namespace std;

vector<int> adj[11]; // adjacency list
int d[11];           // distance array
int p[11];           // predecessor array

void addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void DFSVisit(int u, bool visited[])
{
    visited[u] = true;

    for (int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if (!visited[v])
        {
            d[v] = d[u] + 1;
            p[v] = u;
            DFSVisit(v, visited);
        }
    }
}

void DFS(int start)
{
    bool visited[11];
    for (int i = 0; i < 11; i++)
    {
        visited[i] = false;
        d[i] = INT_MAX;
        p[i] = -1;
    }

    DFSVisit(start, visited);
}

int main()
{
    for (int i = 2; i <= 10; i++)
    {
        for (int j = i + 1; j <= 10; j++)
        {
            if (j % i == 0 || j == i + 1)
            {
                addEdge(i, j);
            }
        }
    }

    DFS(10);

    for (int i = 2; i <= 10; i++)
    {
        cout << "Vertex: " << i << ", Distance: " << d[i] << ", Predecessor: " << p[i] << endl;
    }

    return 0;
}
