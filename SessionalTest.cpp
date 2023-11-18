#include <bits/stdc++.h>
using namespace std;

vector<int> adj_5719[11];
int d_5719[11];
int p_5719[11];

void addEdge(int u, int v)
{
    adj_5719[u].push_back(v);
    adj_5719[v].push_back(u);
}

void PrintAdjList()
{
    cout << "Adjacency List:\n";
    for (int i = 0; i < 11; i++)
    {
        cout << i << ": ";
        for (int j = 0; j < adj_5719[i].size(); j++)
        {
            cout << adj_5719[i][j] << " ";
        }
        cout << endl;
    }
}
void DFSVisited(int u_5179, bool visited_5719[])
{
    visited_5719[u_5179] = true;

    for (int i = 0; i < adj_5719[u_5179].size(); i++)
    {
        int v_5719 = adj_5719[u_5179][i];
        if (!visited_5719[v_5719])
        {
            d_5719[v_5719] = d_5719[u_5179] + 1;
            p_5719[v_5719] = u_5179;
            DFSVisited(v_5719, visited_5719);
        }
    }
}

void DFS(int start_5719)
{
    bool visited_5719[11];
    for (int i = 0; i < 11; i++)
    {
        visited_5719[i] = false;
        d_5719[i] = INT_MAX;
        p_5719[i] = -1;
    }
    d_5719[start_5719] = 0;
    DFSVisited(start_5719, visited_5719);
}
int main()
{

    for (int i = 2; i <= 10; i++)
    {
        for (int j = 0; j <= 10; j++)
        {
            if (j % i == 0 || j == i + 1)
            {
                addEdge(i, j);
            }
        }
    }
    cout << "Adjacency List:\n";
    PrintAdjList();
    DFS(10);
    cout << endl;
    for (int i = 2; i <= 10; i++)
    {
        cout << "Vertex: " << i << ", Distance: " << d_5719[i] << ", Predecessor: " << p_5719[i] << endl;
    }
    return 0;
}