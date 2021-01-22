#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class edge
{
public:
    edge(int x = 25, int val = 1000) : node(x), weight(val) {}
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
        cout << "adjecent list rep of vertex: " << static_cast<char>(i + 97) << "\n head";
        for (auto x : adj[i])
        {
            char z = 97 + x.node;
            cout << "->" << z << ", weight: " << x.weight << " ";
        }
        cout << "\n";
    }
}

void initializeFinal(vector<edge> &final, int size)
{
    for (int i = 0; i < size; i++)
    {
        edge g(i, 100);
        final.push_back(g);
    }
    final.at(3).weight = 0;
}

void printVec(vector<edge> set)
{
    for (int i = 0; i < set.size(); i++)
    {
        cout << static_cast<char>(set[i].node + 97) << "\t" << set[i].weight << "\n";
    }
}
edge *getMin(vector<edge> &res)
{
    int max = 1000;
    edge *x = new edge();
    for (auto i : res)
    {
        if (i.weight < max)
        {
            max = i.weight;
            x->node = i.node;
            x->weight = i.weight;
        }
    }
    // cout << "inside min.";
    return x;
}
void printEdge(edge x)
{
    cout << static_cast<char>(x.node + 97) << "->\t" << x.weight << "\n";
}

//function to check if a node exists in res vector or not.
edge *checkNode(vector<edge> res, edge el)
{

    // printEdge(el);
    edge *x1 = new edge();
    edge *x = new edge();
    for (int i = 0; i < res.size(); i++)
    {
        x = &res[i];
        // cout << "Inside loop of checkNode" << endl;
        // printEdge(*x);
        // cout << "Element: ";
        // printEdge(el);
        if (x->node == el.node)
        {
            x1->node = x->node;
            x1->weight = x->weight;
        }
    }
    // cout << "X1 value: ";
    // printEdge(*x1);
    return x1;
}

void eraseEl(vector<edge> &res, edge x)
{
    for (int i = 0; i < res.size(); i++)
    {
        if (res[i].node == x.node)
        {
            res.erase(res.begin() + i);
            res.resize(res.size());
            break;
        }
    }
}

vector<edge> updateRes(vector<edge> &res, edge update)
{
    for (int i = 0; i < res.size(); i++)
    {
        edge *x = &res[i];
        // printEdge(*x);
        // printEdge(update);
        if (x->node == update.node)
        {
            x->weight = update.weight;
        }
    }
    // // cout << "updated res:" << endl;
    // printVec(res);
    return res;
}

void dijkstra(vector<edge> adj[], int V)
{
    vector<edge> res;
    vector<edge> final;
    initializeFinal(res, V);
    int count = 0;
    while (!res.empty())
    {
        cout << "Iteration : " << count++ << endl;
        edge *min = NULL;
        min = getMin(res);
        cout << "Element to be popped: ";
        printEdge(*min);
        eraseEl(res, *min);
        vector<edge> adjMin = adj[min->node];
        edge *rem = NULL;
        for (auto el : adjMin)
        {
            // cout << "Inside loop of adjMin." << endl;
            rem = checkNode(res, el);
            // if (rem != NULL)
            // {
            //     cout << "Got rem value:" << endl;
            //     printEdge(*rem);
            // }
            if (rem->weight != 1000 && el.weight + min->weight < rem->weight)
            {
                rem->weight = el.weight + min->weight;
                // cout << "New rem value: " << endl;
                // printEdge(*rem);
            }
            //write function to update res.
            res = updateRes(res, *rem);
        }
        cout << "Elements in res of size: " << res.size() << endl;
        printVec(res);
        final.push_back(*min);
    }
    // printVec(res);
    cout << "Final distance vector." << endl;
    printVec(final);
}

int main()
{
    int V = 6;
    vector<edge> adj[V];
    addEdge(adj, 0, 1, 5);
    addEdge(adj, 0, 2, 1);
    addEdge(adj, 1, 3, 6);
    addEdge(adj, 2, 3, 4);
    addEdge(adj, 2, 4, 9);
    addEdge(adj, 3, 5, 3);
    addEdge(adj, 4, 5, 2);
    // showGraph(adj, V);
    dijkstra(adj, V);

    return 0;
}