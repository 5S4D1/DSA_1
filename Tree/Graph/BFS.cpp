/*
    Breadth First Search
*/

#include <bits/stdc++.h>
#include <queue>
using namespace std;

int graph[5][5] = {0, 1, 1, 1, 0,
                   1, 0, 0, 1, 0,
                   1, 0, 0, 0, 0,
                   1, 1, 0, 0, 1,
                   0, 0, 0, 1, 0};

int color[5] = {0, 0, 0, 0, 0};

void bfs(int s)
{
    int d[5];
    int p[5] = {-1};
    color[s] = 1; // color the source node as 1
    d[s] = 0;

    // create a queue
    queue<int> q;
    q.push(s);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for (int i = 0; i < 5; i++)
        {
            // if there is a neighboring node that has not been colored yet
            if (graph[u][i] == 1 && color[i] == 0) 
            {
                color[i] = 1;
                d[i] = d[u] + 1;
                p[i] = u;
                q.push(i);
            }
        }
        color[u] = 2; // color the node as 2
    }
    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "distancen of " << i << " is = " << d[i] << endl;
    }
    for (int i = 0; i < 5; i++)
    {
        cout << "parent of " << i << " is = " << p[i] << endl;
    }
}
int main()
{
    bfs(3);

    return 0;
}
