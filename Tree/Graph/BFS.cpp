#include <bits/stdc++.h>
using namespace std;

int graph[5][5] = {0, 1, 1, 1, 0,
                   1, 0, 0, 1, 0,
                   1, 0, 0, 0, 0,
                   1, 1, 0, 0, 1,
                   0, 0, 0, 1, 0};

int color[5] = {0, 0, 0, 0, 0};

void bfs(int s)
{
    s--;
    color[s] = 1; // color the source node as 1

    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u+1 << endl;

        for (int i = 0; i < 5; i++)
        {
            if (graph[u][i] == -1 && color[i] == 0) // if there is a neighboring node that has not been colored yet
            {
                int v = i;
                q.push(v);
            }
        }
    }
}
int main()
{
    bfs(3);

    return 0;
}
