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

    void bfsRecursive(int queue[], bool visited[], int front, int rear) {
        if (front > rear) return; // Base case: Stop when queue is empty

        int vertex = queue[front++];
        cout << vertex << " ";

        for (int i = 0; i < vertices; i++) {
            if (adjMatrix[vertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue[++rear] = i;
            }
        }

        bfsRecursive(queue, visited, front, rear);
    }

    void performBFS(int startVertex) {
        bool *visited = new bool[vertices]();
        int *queue = new int[vertices];

        int front = 0, rear = 0;
        queue[rear] = startVertex;
        visited[startVertex] = true;

        bfsRecursive(queue, visited, front, rear);

        delete[] visited;
        delete[] queue;
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
    cout << "Enter starting vertex for BFS: ";
    cin >> startVertex;

    cout << "BFS Traversal: ";
    graph.performBFS(startVertex);

    return 0;
}
