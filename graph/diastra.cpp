#include <iostream>
#include <vector>
using namespace std;

class edge
{
public:
    edge(int x, int val) : node(x), weight(val) {}
    int node, weight;
};

void addEdge(vector<edge> adj[], int u, int v, int weight)
{
    edge x(v, weight);
    edge y(u, weight);
    adj[u].push_back(x);
    adj[v].push_back(y);
}

void showGraph(vector<edge> adj[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "adjecent list rep of vertex: " << i << "\n head";
        for (auto x : adj[i])
        {
            cout << "->" << x.node << ", weight: " << x.weight << " ";
        }
        cout << "\n";
    }
}

int main()
{
    int V = 5;
    vector<edge> adj[V];
    addEdge(adj, 0, 1, 2);
    addEdge(adj, 0, 4, 3);
    addEdge(adj, 1, 2, 5);
    addEdge(adj, 1, 3, 1);
    addEdge(adj, 1, 4, 2);
    addEdge(adj, 2, 3, 99);
    addEdge(adj, 3, 4, 45);
    showGraph(adj, V);
    return 0;
}