#include <iostream>   //non recursive
#include <vector>
#include <queue>
using namespace std;

void bfs(int start, vector<int> adj_list[], int n)
{
    vector<bool> visited(n, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS: ";
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adj_list[node])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

int main()
{
    int n, edges;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<int> adj_list[n];

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges (u v) as space-separated pairs:\n";
    for (int i = 0; i < edges; i++) 
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u); // For undirected graph
    }

    bfs(0, adj_list, n); // Start BFS from node 0

    return 0;
}
  