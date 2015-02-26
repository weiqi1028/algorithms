class Graph {
    int numOfNodes;
    vector<vector<int>> adj;
public:
    Graph(int V) {
        numOfNodes = V;
        for (int i = 0; i < V; i++) {
            vector<int> temp;
            adj.push_back(temp);
        }
    }

    ~Graph() {}

    void addEdge(int v, int u) {
        adj[v].push_back(u);
    }

    Graph reverse() {
        Graph g(numOfNodes);
        for (int i = 0; i < numOfNodes; i++) {
            for (int j = 0; j < adj[i].size(); j++) {
                g.adj[adj[i][j]].push_back(i);
            }
        }
        return g;
    }

    void traverse(int v, vector<bool> &visited) {
        visited[v] = true;
        for (int i = 0; i < adj[v].size(); i++) {
            if (!visited[adj[v][i]])
                traverse(adj[v][i], visited);
        }
    }

    bool isStronglyConnected() {
        vector<bool> visited;
        for (int i = 0; i < numOfNodes; i++)
            visited.push_back(false);
        traverse(0, visited);
        for (int i = 0; i < visited.size(); i++) {
            if (!visited[i])
                return false;
        }
        for (int i = 0; i < visited.size(); i++)
            visited[i] = false;
        Graph g = reverse();
        g.traverse(0, visited);
        for (int i = 0; i < visited.size(); i++) {
            if (!visited[i])
                return false;
        }
        return true;
    }

    void dfsPrint(int v, vector<bool> &visited) {
        visited[v] = true;
        cout << v << " ";
        for (int i = 0; i < adj[v].size(); i++) {
            if (!visited[adj[v][i]])
                dfsPrint(adj[v][i], visited);
        }
    }

    void fillStack(int v, vector<bool> &visited, std::stack<int> &s) {
        visited[v] = true;
        for (int i = 0; i < adj[v].size(); i++) {
            if (!visited[adj[v][i]])
                fillStack(adj[v][i], visited, s);
        }
        s.push(v);
    }

    // print all the strongly connected components, each SCC is a line.
    void printStronglyConnectedComponents() {
        std::stack<int> s;
        vector<bool> visited;
        for (int i = 0; i < numOfNodes; i++)
            visited.push_back(false);
        for (int i = 0; i < numOfNodes; i++) {
            if (!visited[i])
                fillStack(0, visited, s);
        }
        for (int i = 0; i < numOfNodes; i++)
            visited[i] = false;
        Graph g = reverse();
        while (!s.empty()) {
            int cur = s.top();
            s.pop();
            if (!visited[cur]) {
                g.dfsPrint(cur, visited);
                cout << endl;
            }
            
        }
    }
};


int _tmain(int argc, _TCHAR* argv[])
{
    Graph g1(5);
    g1.addEdge(0, 1);
    g1.addEdge(1, 2);
    g1.addEdge(2, 3);
    g1.addEdge(3, 0);
    g1.addEdge(2, 4);
    g1.addEdge(4, 2);
    g1.isStronglyConnected() ? cout << "Yes\n" : cout << "No\n";
    g1.printStronglyConnectedComponents();

    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.isStronglyConnected() ? cout << "Yes\n" : cout << "No\n";
    g2.printStronglyConnectedComponents();

    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
    g.isStronglyConnected() ? cout << "Yes\n" : cout << "No\n";
    g.printStronglyConnectedComponents();

	return 0;
}