// this program will generate random graphs with random costs and print them
// the representation would be of an adjency list

#include <iostream>
#include <vector>
#include <ctime>
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
    int nodeNum;
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
            if (!exists && i != j && prob() > 0.5)
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
            cout << edge;
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

int main()
{
    srand(time(0));
    // cout << prob();
    vector<node> graph = initializeGraph(4);
    vector<edge> ed = createEdge(0, 2);
    createRandomGraph(graph, 4);
    // graph[0].appendEdge(ed[0]);
    // graph[2].appendEdge(ed[1]);
    // ed = createEdge(0, 3);
    // graph[0].appendEdge(ed[0]);
    // graph[3].appendEdge(ed[1]);
    // ed = createEdge(1, 2);
    // graph[1].appendEdge(ed[0]);
    // graph[2].appendEdge(ed[1]);
    printGraph(graph);
}