// program to simulate kruskal minumim spannig tree algorithm
#include <iostream>
#include <vector>
#include <ctime>
#include <limits>
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

class Kedge
{
public:
    Kedge(){};
    int n1, n2, cost;
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

void printGraph(vector<node> graph)
{
    for (auto node : graph)
    {
        cout << node.nodeNum << "\t";
    }
}

Kedge findMinEdgeFromGraph(vector<node> graph, vector<node> closed)
{
    edge minEdge;
    for (auto node : graph)
    {
        findMinEdgeFromNode(closed, node.edges);
    }
}

void kruskal(vector<node> graph)
{
    vector<node> closed;
    node n1, n2;
    Kedge k1;
    while (1)
    {
        k1 = findMinEdgeFromGraph(graph, closed);
        if (k1)
        {
            for (auto node : graph)
            {
                if (node.nodeNum == k1.n1)
                {
                    n1 = node;
                }
                if (node.nodeNum == k1.n2)
                {
                    n2 = node;
                }
                if (!inClosed(n1))
                {
                    closed.push_back(n1);
                }
                else
                {
                    closed.push_back(n2);
                }
            }
        }
        else
        {
            break;
        }
    }
}