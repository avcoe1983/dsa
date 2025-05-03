#include <iostream>   //BFS RECURSIVE
using namespace std;

void bfs_recursive(int adj_mat[10][10], int n, int queue[10], int &front, int &rear, int visited[10])
{
    if (front == rear)
        return;

    int node = queue[front++];
    cout << node << " ";
 
    for (int j = 0; j < n; j++)
    {
        if (adj_mat[node][j] == 1 && visited[j] == 0)
        {
            queue[rear++] = j;
            visited[j] = 1;
        }
    }

    bfs_recursive(adj_mat, n, queue, front, rear, visited);
}

int main()
{
    int n, adj_mat[10][10], visited[10] = {0}, queue[10], front = 0, rear = 0;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> adj_mat[i][j];

    visited[0] = 1;
    queue[rear++] = 0;

    cout << "BFS: ";
    bfs_recursive(adj_mat, n, queue, front, rear, visited);

    return 0;
}
