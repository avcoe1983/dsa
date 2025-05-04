#include <iostream>
using namespace std;

class Graph {
private:
    int vertices;
    int **adjMatrix;

public:
    Graph(int v) {
        vertices = v;
        adjMatrix = new int*[vertices];
        for (int i = 0; i < vertices; i++) {
            adjMatrix[i] = new int[vertices];
            for (int j = 0; j < vertices; j++)
                adjMatrix[i][j] = 0;
        }
    }

    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // For an undirected graph
    }

    void dfsRecursive(int vertex, bool visited[]) {
        visited[vertex] = true;
        cout << vertex << " ";

        for (int i = 0; i < vertices; i++) {
            if (adjMatrix[vertex][i] == 1 && !visited[i]) {
                dfsRecursive(i, visited);
            }
        }
    }

    void performDFS(int startVertex) {
        bool *visited = new bool[vertices];
        for (int i = 0; i < vertices; i++)
            visited[i] = false;

        dfsRecursive(startVertex, visited);
        delete[] visited;
    }

    ~Graph() {
        for (int i = 0; i < vertices; i++)
            delete[] adjMatrix[i];
        delete[] adjMatrix;
    }
};

int main() {
    int v, e;
    cout << "Enter number of vertices: ";
    cin >> v;

    Graph graph(v);

    cout << "Enter number of edges: ";
    cin >> e;
    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v);
    }

    int startVertex;
    cout << "Enter starting vertex for DFS: ";
    cin >> startVertex;

    cout << "DFS Traversal: ";
    graph.performDFS(startVertex);

    return 0;
}
