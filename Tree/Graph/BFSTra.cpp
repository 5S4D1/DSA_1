#include <bits/stdc++.h>
using namespace std;

int graph[4][4] = {
    0, 1, 0, 1,
    0, 0, 1, 0,
    1, 1, 0, 0,
    0, 1, 0, 0};

int color[4] = {0, 0, 0, 0};

void bfs(int s)
{
    cout << "source: " << s << endl;
    color[s] = 1;
    queue<int> q;
    q.push(s);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int i = 0; i < 4; i++)
        {
            if (graph[u][i] == 1 && color[i] == 0)
            {
                color[i] = 1;
                q.push(i);
            }
        }
    }
}

int main()
{
    bfs(0);

    return 0;
}