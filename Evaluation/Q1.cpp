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

void BFS(int s)
{
    bool visited[11];
    for (int i = 0; i < 11; i++)
    {
        visited[i] = false;
        d[i] = INT_MAX;
        p[i] = -1;
    }

    queue<int> Q;
    visited[s] = true;
    d[s] = 0;
    Q.push(s);

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        for (int i = 0; i < adj[u].size(); i++)
        {
            if (visited[adj[u][i]] == false)
            {
                visited[adj[u][i]] = true;
                d[adj[u][i]] = d[u] + 1;
                p[adj[u][i]] = u;
                Q.push(adj[u][i]);
            }
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

    BFS(2);

    for (int i = 2; i <= 10; i++)
    {
        cout << "Vertex: " << i << ", Distance: " << d[i] << ", Predecessor: " << p[i] << endl;
    }

    return 0;
}
