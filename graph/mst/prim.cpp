// program to simulate prim minumim spannig tree algorithm
#include <iostream>
#include <vector>
#include <ctime>
#include <limits>
// #include <bits/stdc++.h>
using namespace std;

class edge
{
public:
    edge(int node = 999, int cost = 999) : node(node), cost(cost){};
    friend ostream &operator<<(ostream &out, const edge edge)
    {
        out << "Node: " << edge.node << ", Cost: " << edge.cost << endl;
        return out;
    }
    int node, cost;
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

double prob()
{
    double prob = static_cast<double>(rand() % 100) / 100;
    return prob;
}

int edgeExists(vector<node> graph, int i, int j)
{
    int exists = 0;
    node ni = graph[i];
    for (auto edge : ni.edges)
    {
        if (edge.node == j)
        {
            exists = 1;
        }
    }
    return exists;
}

vector<edge> createEdge(int i, int j)
{
    int cost = 1 + rand() % 10;
    vector<edge> ed(2);
    ed[0].node = j;
    ed[0].cost = cost;
    ed[1].node = i;
    ed[1].cost = cost;
    return ed;
}

void createRandomGraph(vector<node> &graph, int size)
{
    cout << "creating random graph." << endl;
    int exists;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            exists = edgeExists(graph, i, j);
            if (!exists && i != j && prob() < 0.1)
            {
                vector<edge> ed = createEdge(i, j);
                graph[i].appendEdge(ed[0]);
                graph[j].appendEdge(ed[1]);
            }
        }
    }
}

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

vector<node> initializeGraph(int size)
{
    vector<node> graph(size);
    for (int i = 0; i < graph.size(); i++)
    {
        graph[i].nodeNum = i;
    }
    return graph;
}

int nodeInClosed(vector<node> closed, int nodeNUM)
{
    int x = 0;
    for (auto node : closed)
    {
        if (node.nodeNum == nodeNUM)
        {
            x = 1;
            break;
        }
    }
    return x;
}

edge findMinEdgeFromNode(vector<node> closed, node node)
{
    // cout << "inside FindFromNode";
    int x;
    edge minEdge;
    minEdge.cost = INT32_MAX;
    for (auto edge : node.edges)
    {
        x = nodeInClosed(closed, edge.node);
        if (!x && minEdge.cost > edge.cost)
        {
            minEdge = edge;
        }
    }
    return minEdge;
}

edge findMinEdgeFromGraph(vector<node> closed)
{
    // cout << "inside FindEdgeFromGraph";
    //this routine finds the min cost edge that emerges from closed set to outside of the set.
    edge Gmin, nMin;
    Gmin.cost = INT32_MAX;
    for (auto node : closed)
    {
        nMin = findMinEdgeFromNode(closed, node);
        if (Gmin.cost > nMin.cost)
        {
            Gmin = nMin;
        }
    }
    return Gmin;
}

void prim(vector<node> graph, node startNode)
{
    cout << "inside prim";
    edge GEdgeMin;
    node addNode;
    vector<node> closed;
    int spanCost = 0;
    closed.push_back(startNode);
    int i = 0;
    while (1)
    {
        cout << "Iteration: " << i++ << endl;
        cout << endl;
        GEdgeMin = findMinEdgeFromGraph(closed);
        if (GEdgeMin.node != 999)
        {
            spanCost += GEdgeMin.cost;
            for (auto node : graph)
            {
                if (node.nodeNum == GEdgeMin.node)
                {
                    addNode = node;
                }
            }
            closed.push_back(addNode);
        }
        else
        {
            break;
        }
        for (auto node : closed)
        {
            cout << node.nodeNum << "\t";
        }
        cout << endl;
    }

    //print closed.
    cout << "Final Closed Set after algorithm: " << endl;
    for (auto node : closed)
    {
        cout << node.nodeNum << "\t";
    }
    cout << endl
         << "Span cost: " << spanCost << endl;
}

int main()
{
    srand(time(0));
    int size = 10;
    vector<node> graph = initializeGraph(size);
    vector<edge> ed = createEdge(0, 2);
    createRandomGraph(graph, size);
    printRandomGraph(graph);
    node startNode = graph[0];
    prim(graph, startNode);
}
