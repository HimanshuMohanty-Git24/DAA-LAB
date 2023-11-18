#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <functional>

using namespace std;

class Graph
{
private:
    unordered_map<int, vector<int>> adjList;

public:
    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void dfs(int start, unordered_map<int, int> &distance, unordered_map<int, int> &predecessor)
    {
        unordered_set<int> visited;

        function<void(int, int)> dfsVisit = [&](int vertex, int dist)
        {
            visited.insert(vertex);
            distance[vertex] = dist;

            for (int neighbor : adjList[vertex])
            {
                if (visited.find(neighbor) == visited.end())
                {
                    predecessor[neighbor] = vertex;
                    dfsVisit(neighbor, dist + 1);
                }
            }
        };

        dfsVisit(start, 0);
    }

    void printAdjList()
    {
        cout << "Adjacency List:\n";
        for (const auto &entry : adjList)
        {
            cout << entry.first << ": ";
            for (int neighbor : entry.second)
            {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g;

    for (int i = 2; i <= 10; ++i)
    {
        for (int j = i + 1; j <= 10; ++j)
        {
            if (j == i + 1 || j % i == 0)
            {
                g.addEdge(i, j);
            }
        }
    }

    int startVertex = 10;
    unordered_map<int, int> distance, predecessor;
    g.dfs(startVertex, distance, predecessor);

    g.printAdjList();

    cout << "\nDFS Results:\n";
    cout << "Vertex\tDistance\tPredecessor\n";
    for (const auto &entry : distance)
    {
        int vertex = entry.first;
        int dist = entry.second;
        int pred = (vertex == startVertex) ? -1 : predecessor[vertex];

        cout << vertex << "\t" << dist << "\t\t" << pred << endl;
    }

    return 0;
}