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
