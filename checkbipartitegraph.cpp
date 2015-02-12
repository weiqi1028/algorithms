/************************************************************************************
A Bipartite Graph is a graph whose vertices can be divided into two independent sets,
U and V such that every edge (u, v) either connects a vertex from U to V or a vertex
from V to U. In other words, for every edge (u, v), either u belongs to U and v to V,
or u belongs to V and v to U. We can also say that there is no edge that connects
vertices of same set.

1. Assign RED color to the source vertex (putting into set U).
2. Color all the neighbors with BLUE color (putting into set V).
3. Color all neighbor’s neighbor with RED color (putting into set U).
4. This way, assign color to all vertices such that it satisfies all the constraints of
m way coloring problem where m = 2.
5. While assigning colors, if we find a neighbor which is colored with same color as
current vertex, then the graph cannot be colored with 2 vertices (or graph is not Bipartite)

Time Complexity of the above approach is same as that Breadth First Search. In above
implementation is O(V^2) where V is number of vertices. If graph is represented using
adjacency list, then the complexity becomes O(V+E).
************************************************************************************/

bool checkBipartite(GraphNode *root) {
    if (root == NULL)
        return true;
    std::queue<GraphNode *> q;
    q.push(root);
    std::map<GraphNode *, int> visited;
    visited[root] = 0;
    while (!q.empty()) {
        GraphNode *cur = q.front();
        q.pop();
        int value = visited[cur];
        for (int i = 0; i < cur->neighbors.size(); i++) {
            GraphNode *neigh = cur->neighbors[i];
            if (visited.find(neigh) == visited.end()) {
                if (value == 0)
                    visited[neigh] = 1;
                else
                    visited[neigh] = 0;
                q.push(neigh);
            }
            else {
                if (visited[neigh] == value)
                    return false;
            }
        }
    }
    return true;
}