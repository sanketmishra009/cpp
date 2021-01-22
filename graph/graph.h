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