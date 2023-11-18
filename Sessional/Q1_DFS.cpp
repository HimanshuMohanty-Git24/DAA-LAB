#include <bits/stdc++.h>
using namespace std;

vector<int> adj[11];
bool visited[11];
int d[11], pi[11];

void addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void DFS(int u, int depth)
{
    visited[u] = true;
    d[u] = depth;
    for (int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if (!visited[v])
        {
            pi[v] = u;
            DFS(v, depth + 1);
        }
    }
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

    memset(visited, false, sizeof(visited));
    memset(d, -1, sizeof(d));
    memset(pi, -1, sizeof(pi));

    DFS(10, 0);

    for (int i = 2; i <= 10; i++)
    {
        cout << "Vertex: " << i << ", d[" << i << "]: " << d[i] << ", π[" << i << "]: " << pi[i] << endl;
    }

    return 0;
}
