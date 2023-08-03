#include <iostream>
#include <stack>
using namespace std;

bool isCyclic(int a[][10], int source, int visited[], int parent[])
{
    stack<int> s;
    s.push(source);
    visited[source] = 1;
    parent[source] = -1;
    while (!s.empty())
    {
        int current = s.top();
        s.pop();
        for (int i = 0; i < 10; i++)
        {
            if (a[current][i] == 1)
            {
                if (visited[i] == 0)
                {
                    visited[i] = 1;
                    parent[i] = current;
                    s.push(i);
                }
                else if (parent[current] != i)
                {
                    return true;
                }
            }
        }
    }
    return false;
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
    int parent[10] = {0};
    bool cyclic = false;
    for (int i = 0; i < vertices; i++)
    {
        if (visited[i] == 0)
        {
            cyclic = isCyclic(a, i, visited, parent);
            if (cyclic)
            {
                break;
            }
        }
    }
    if (cyclic)
    {
        cout << "Graph contains a cycle." << endl;
    }
    else
    {
        cout << "Graph does not contain a cycle." << endl;
    }
    return 0;
}
