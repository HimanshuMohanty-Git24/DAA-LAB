#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int u, v, weight;
    bool operator<(Edge const &other)
    {
        return weight < other.weight;
    }
};

int n, m;
vector<Edge> edges;
vector<int> parent;
vector<int> rank;

void make_set(int v)
{
    parent[v] = v;
    rank[v] = 0;
}

int find_set(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
}

int main()
{
    cin >> n >> m;
    parent.resize(n + 1);
    rank.resize(n + 1);
    for (int i = 1; i <= n; i++)
        make_set(i);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    sort(edges.begin(), edges.end());

    int cost = 0;
    cout << "Edge Cost\n";
    for (Edge e : edges)
    {
        if (find_set(e.u) != find_set(e.v))
        {
            cost += e.weight;
            cout << e.u << "--" << e.v << " " << e.weight << "\n";
            union_sets(e.u, e.v);
        }
    }
    cout << "Total Weight of the Spanning Tree: " << cost << "\n";

    return 0;
}
