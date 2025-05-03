#include <iostream>    //DFS RECURSIVE
using namespace std;

void dfs(int adj_mat[10][10], int n, int node, int visited[10])
{
    cout << node << " ";
    visited[node] = 1; 

    for (int j = 0; j < n; j++)
    {
        if (adj_mat[node][j] == 1 && visited[j] == 0)
        {
            dfs(adj_mat, n, j, visited);
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
    dfs(adj_mat, n, 0, visited);

    return 0;
}                                                   



