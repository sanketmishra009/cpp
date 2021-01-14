#include <iostream>
#include <vector>
using namespace std;

// class edge
// {
// public:
//     edge(int x, int val) : node(x), weight(val) {}
//     int node, weight;
// }

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void showGraph(vector<int> adj[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "adjecent list rep of vertex: " << i << "\n head";
        for (auto x : adj[i])
        {
            cout << "->" << x;
        }
        cout << "\n";
    }
}

int main()
{
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    showGraph(adj, V);
    return 0;
}