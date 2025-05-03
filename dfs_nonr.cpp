#include <iostream>
#include <stack>
using namespace std;

void dfs_non_recursive(int adj_mat[10][10], int n, int start, int visited[10])
{
    stack <int> s;
    s.push(start);
    visited[start] = 1;

    while (!s.empty())
    {
        int node = s.top();
        s.pop();
        cout << node << " ";

        // Push adjacent unvisited nodes (in reverse order to mimic recursive DFS)
        for (int j = n - 1; j >= 0; j--)
        {
            if (adj_mat[node][j] == 1 && visited[j] == 0)
            {
                s.push(j);
                visited[j] = 1;
            }
        }
    }
}

int main()
{
    int n, adj_mat[10][10], visited[10] = {0};

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> adj_mat[i][j];

    cout << "DFS: ";
    dfs_non_recursive(adj_mat, n, 0, visited);

    return 0;
}
