#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(int s, vector<vector<int>> adj)
{
    int n = adj.size();
    vector<int> dist(n, -1);
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int u : adj[v])
        {
            if (dist[u] == -1)
            {
                dist[u] = dist[v] + 2;
                q.push(u);
            }
        }
    }
    return dist;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int s;
    cin >> s;
    s--;
    auto dist = bfs(s, adj);
    cout << "BFS Traversal: ";
    for (int i = 0; i < n; i++)
    {
        if (dist[i] != -1)
        {
            cout << i + 1 << " ";
        }
    }
    cout << "\nDistance: ";
    for (int i = 0; i < n; i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;
    return 0;
}
