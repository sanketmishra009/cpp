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
    int V = 6;
    vector<edge> adj[V];
    vector<edge> res;
    vector<edge> sSet;

    // set inf status to nodes.
    for (int i = 0; i < V; i++)
    {
        edge x(i, 100);
    }

    addEdge(adj, 0, 1, 5);
    addEdge(adj, 0, 2, 1);
    addEdge(adj, 1, 3, 6);
    addEdge(adj, 2, 3, 4);
    addEdge(adj, 2, 4, 9);
    addEdge(adj, 3, 5, 3);
    addEdge(adj, 4, 5, 2);
}