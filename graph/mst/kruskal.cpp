// program to simulate kruskal minumim spannig tree algorithm
#include <iostream>
#include <vector>
#include <ctime>
#include <limits>
using namespace std;

class edge
{
public:
    edge(int node = 999, int cost = 999, int v = 0) : node(node), cost(cost), v(v){};
    friend ostream &operator<<(ostream &out, const edge edge)
    {
        out << "Node: " << edge.node << ", Cost: " << edge.cost << " v: " << edge.v << endl;
        return out;
    }
    int node, cost, v;
};

class node
{
public:
    node(){};
    node(int x) : nodeNum(x){};
    void appendEdge(edge edge)
    {
        edges.push_back(edge);
    }
    void PrintNode()
    {
        for (auto edge : edges)
        {
            cout << edge;
        }
    }
    int nodeNum, cost;
    vector<edge> edges;
};

class Kedge
{
public:
    Kedge(){};
    friend ostream &operator<<(ostream &out, const Kedge edge)
    {
        out << "Node1: " << edge.n1 << ", Cost: " << edge.cost << " Node2: " << edge.n2 << endl;
        return out;
    }
    int n1, n2, cost;
};

void printRandomGraph(vector<node> graph)
{
    for (auto node : graph)
    {
        cout << "Adj list of node: " << node.nodeNum << endl;
        for (auto edge : node.edges)
        {
            cout << "\t" << edge;
        }
    }
}

void printGraph(vector<node> graph)
{
    for (auto node : graph)
    {
        cout << node.nodeNum << "\t";
    }
}

void markVisited(vector<node> &graph, Kedge Gmin)
{
    for (int i = 0; i < graph.size(); i++)
    {
        node *node = &graph[i];
        if (node->nodeNum == Gmin.n1 || node->nodeNum == Gmin.n2)
        {
            for (int j = 0; j < node->edges.size(); j++)
            {
                edge *edge = &node->edges[j];
                if (edge->node == Gmin.n1 || edge->node == Gmin.n2)
                {
                    edge->v = 1;
                }
            }
        }
    }
}

Kedge findMinEdgeFromNode(node node)
{
    Kedge Nmin;
    Nmin.cost = INT32_MAX;
    Nmin.n1 = node.nodeNum;
    for (auto edge : node.edges)
    {
        if (edge.cost < Nmin.cost && edge.v == 0)
        {
            Nmin.n2 = edge.node;
            Nmin.cost = edge.cost;
        }
    }
    return Nmin;
}

Kedge findMinEdgeFromGraph(vector<node> graph)
{
    Kedge minEdge, GminEdge;
    GminEdge.cost = INT32_MAX;
    for (auto node : graph)
    {
        minEdge = findMinEdgeFromNode(node);
        if (GminEdge.cost > minEdge.cost)
        {
            GminEdge = minEdge;
        }
    }
    markVisited(graph, GminEdge);
    cout << "after mark:" << endl;
    // printRandomGraph(graph);
    return GminEdge;
}

void kruskal(vector<node> graph)
{
    vector<node> closed;
    node n1, n2;
    Kedge k1;
    while (1)
    {
        k1 = findMinEdgeFromGraph(graph);
        cout << k1;
        printRandomGraph(graph);
        break;
    }
}

vector<node> initializeGraph()
{
    node n0, n1, n2, n3, n4, n5, n6, n7;
    n0.nodeNum = 0;
    n1.nodeNum = 1;
    n2.nodeNum = 2;
    n3.nodeNum = 3;
    n4.nodeNum = 4;
    n5.nodeNum = 5;
    n6.nodeNum = 6;
    // n7.nodeNum = 7;
    edge e;
    e.node = 0;
    e.cost = 7;
    n1.appendEdge(e);
    e.cost = 5;
    n3.appendEdge(e);

    e.node = 1;
    e.cost = 7;
    n0.appendEdge(e);
    e.cost = 9;
    n3.appendEdge(e);
    e.cost = 8;
    n2.appendEdge(e);
    e.cost = 7;
    n4.appendEdge(e);

    e.node = 2;
    e.cost = 8;
    n1.appendEdge(e);
    e.cost = 5;
    n4.appendEdge(e);

    e.node = 3;
    e.cost = 5;
    n0.appendEdge(e);
    e.cost = 9;
    n1.appendEdge(e);
    e.cost = 15;
    n4.appendEdge(e);
    e.cost = 6;
    n5.appendEdge(e);

    e.node = 4;
    e.cost = 7;
    n1.appendEdge(e);
    e.cost = 5;
    n2.appendEdge(e);
    e.cost = 15;
    n3.appendEdge(e);
    e.cost = 8;
    n5.appendEdge(e);
    e.cost = 9;
    n6.appendEdge(e);

    e.node = 5;
    e.cost = 6;
    n3.appendEdge(e);
    e.cost = 8;
    n4.appendEdge(e);
    e.cost = 11;
    n6.appendEdge(e);

    e.node = 6;
    e.cost = 11;
    n5.appendEdge(e);
    e.cost = 9;
    n4.appendEdge(e);

    vector<node> g;
    g.push_back(n0);
    g.push_back(n1);
    g.push_back(n2);
    g.push_back(n3);
    g.push_back(n4);
    g.push_back(n5);
    g.push_back(n6);

    return g;
}

node getNode(vector<node> graph, int nodeNum)
{
    node n;
    for (auto node : graph)
    {
        if (node.nodeNum == nodeNum)
        {
            n = node;
        }
    }
    return n;
}

int checkCycle(node n, node parent, vector<node> &visited, vector<node> graph)
{
    // cout << "visited at this iteration:" << endl;
    // printRandomGraph(visited);
    int cycle = 0, check = 0;
    node curr;
    for (auto node : visited)
    {
        if (node.nodeNum == n.nodeNum)
        {
            // cout << "cycle found at node: " << node.nodeNum << endl
            //      << "parent node being: " << parent.nodeNum << endl;
            // printRandomGraph(visited);
            cycle = 1;
            return cycle;
        }
    }
    if (!cycle)
    {
        visited.push_back(n);
        for (auto edge : n.edges)
        {
            if (edge.node != parent.nodeNum)
            {
                // cout << "calling checkCycle at " << edge.node << endl;
                curr = getNode(graph, edge.node);
                check = checkCycle(curr, n, visited, graph);
                if (check)
                {
                    break;
                }
            }
        }
    }
    return check;
}

void detectCycle(vector<node> graph)
{
    vector<node> visited;
    int res;
    for (int i = 0; i < graph.size(); i++)
    {
        visited.clear();
        node n = graph[i];
        cout << "starting node: " << n.nodeNum << endl;
        node parent = n;
        res = checkCycle(n, parent, visited, graph);
        cout << "The result is: " << res << endl;
    }
}

int main()
{
    vector<node> graph = initializeGraph();
    printRandomGraph(graph);
    // detectCycle(graph);
    kruskal(graph);
}