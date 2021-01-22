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
    int exists;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            exists = edgeExists(graph, i, j);
            if (!exists && i != j && prob() < 0.5)
            {
                vector<edge> ed = createEdge(i, j);
                graph[i].appendEdge(ed[0]);
                graph[j].appendEdge(ed[1]);
            }
        }
    }
}

void printGraph(vector<node> graph)
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

node findMinFromNode(vector<node> closed, node node)
{
}

node findMinEdgeFromGraph(vector<node> closed)
{
    //this routine finds the min cost edge that emerges from closed set to outside of the set.
    node Gmin, nMin;
    Gmin.cost = INT32_MIN;
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
    node GnodeMin;
    vector<node> closed;
    closed.push_back(startNode);
    while (1)
    {
        GnodeMin = findMinEdgeFromGraph(closed);
        if (GnodeMin.nodeNum)
        {
            closed.push_back(GnodeMin);
        }
        else
        {
            break;
        }
    }

    //print closed.
    for (auto node : closed)
    {
        cout << node.nodeNum;
    }
}

int main()
{
    node n;
    if (n.nodeNum)
    {
        cout << "sex";
    }
    else
    {
        cout << "fuck" << endl;
        cout << INT32_MAX << endl;
    }
}
