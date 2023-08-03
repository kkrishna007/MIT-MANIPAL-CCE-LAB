#include <iostream>
#include <stack>
using namespace std;

void DFS(int a[][10], int source, int visited[])
{
    stack<int> s;
    s.push(source);
    visited[source] = 1;
    while (!s.empty())
    {
        int current = s.top();
        s.pop();
        for (int i = 0; i < 10; i++)
        {
            if (a[current][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                s.push(i);
            }
        }
    }
}

int main()
{
    int vertices, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << "Enter the number of edges: ";
    cin >> edges;
    int a[10][10] = {0};
    int u, v;
    cout << "Enter the edges: " << endl;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;
        a[u - 1][v - 1] = 1;
    }
    int visited[10] = {0};
    DFS(a, 0, visited);
    bool connected = true;
    for (int i = 0; i < vertices; i++)
    {
        if (visited[i] == 0)
        {
            connected = false;
            break;
        }
    }
    if (connected)
    {
        cout << "Graph is connected." << endl;
    }
    else
    {
        cout << "Graph is not connected." << endl;
    }
    return 0;
}
