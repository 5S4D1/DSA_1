#include <bits/stdc++.h>
using namespace std;

int graph[4][4] = {
    0, 1, 0, 1,
    0, 0, 1, 0,
    1, 1, 0, 0,
    0, 1, 0, 0};

int color[4] = {0, 0, 0, 0};

void dfs(int k)
{
    cout << "source: " << k << endl;
    color[k] = 1;
    stack<int> s;
    s.push(k);

    while (!s.empty())
    {
        int u = s.top();
        s.pop();
        cout << u << " ";
        for (int i = 0; i < 4; i++)
        {
            if (graph[u][i] == 1 && color[i] == 0)
            {
                s.push(i);
                color[i] = 1;
            }
        }
    }
}

int main()
{
    dfs(0);

    return 0;
}