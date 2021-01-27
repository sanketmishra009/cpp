#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class edge
{
public:
    edge(int node = INT32_MIN, int cost = INT32_MIN) : node(node), cost(cost){};
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
    n7.nodeNum = 7;
    edge e;
    e.node = 3;
    n0.appendEdge(e);
    n4.appendEdge(e);
    e.node = 1;
    n0.appendEdge(e);
    n2.appendEdge(e);
    e.node = 2;
    // n0.appendEdge(e);
    n1.appendEdge(e);
    n4.appendEdge(e);
    e.node = 0;
    n3.appendEdge(e);
    n1.appendEdge(e);
    // n2.appendEdge(e);
    e.node = 4;
    n3.appendEdge(e);
    n2.appendEdge(e);

    e.node = 5;
    // n6.appendEdge(e);
    n7.appendEdge(e);

    e.node = 6;
    // n5.appendEdge(e);
    n7.appendEdge(e);

    e.node = 7;
    n6.appendEdge(e);
    n5.appendEdge(e);

    vector<node> g;
    g.push_back(n0);
    g.push_back(n1);
    g.push_back(n2);
    g.push_back(n3);
    g.push_back(n4);
    g.push_back(n5);
    g.push_back(n6);
    g.push_back(n7);

    return g;
}

int main()
{
    vector<node> g = initializeGraph();
    printRandomGraph(g);
    detectCycle(g);
}