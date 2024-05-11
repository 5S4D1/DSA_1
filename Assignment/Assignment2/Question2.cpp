/*
    The Maze of Mysteries - Finding Paths  with Treasures
    - Explore the maze, avoid walls (1)
    - Pathway (0)
    - Collecting the Treasure on the way (3)
    - Ends at  the Exit (2)
    - DFS
    - BFS
    Author: Sheikh Sadi
    © https://github.com/5S4D1
*/
#include <bits/stdc++.h>
using namespace std;
int maze[5][5] = {0, 1, 2, 0, 0,
                  0, 0, 0, 1, 0,
                  0, 3, 1, 0, 0,
                  0, 1, 0, 1, 0,
                  0, 0, 0, 0, 0};

int visited[5][5] = {0, 0, 0, 0, 0,
                     0, 0, 0, 0, 0,
                     0, 0, 0, 0, 0,
                     0, 0, 0, 0, 0,
                     0, 0, 0, 0, 0};

queue<int> r; // queue for row
queue<int> c; // queue for column

void dfs(int row, int col)
{
    // Check the Boundary
    if (row < 0 || row > 4 || col < 0 || col > 4)
        return;

    // color for visited
    visited[row][col] = 1;

    // exit point finder
    if (maze[row][col] == 2)
    {

        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (visited[i][j] == 1)
                    cout << "(" << i << "," << j << ") ";
                if (maze[i][j] == 3 && visited[i][j] == 1)
                {
                    cout << "found the Treasure! ";
                }
            }
        }
        cout << "We are in the exit!\n"
             << endl;
    }

    // → move to right
    if (maze[row][col + 1] != 1 && visited[row][col + 1] == 0)
    {
        dfs(row, col + 1);
    }
    // ← move to left
    if (maze[row][col - 1] != 1 && visited[row][col - 1] == 0)
    {
        dfs(row, col - 1);
    }
    // ↓ move to down
    if (maze[row + 1][col] != 1 && visited[row + 1][col] == 0)
    {
        dfs(row + 1, col);
    }
    // ↑ move to up
    if (maze[row - 1][col] != 1 && visited[row - 1][col] == 0)
    {
        dfs(row - 1, col);
    }
    visited[row][col] = 0;
}

void bfs(int row, int col)
{
    r.push(row);
    c.push(col);

    while (!r.empty())
    {
        row = r.front();
        col = c.front();
        r.pop();
        c.pop();
        // Check the Boundary of maze
        if (row < 0 || row > 4 || col < 0 || col > 4)
            continue;

        // Check if visited
        if (visited[row][col] == 1)
            continue;

        cout << "(" << row << "," << col << ") ";

        if (maze[row][col] == 3)
        {
            cout << "found the Treasure! ";
        }

        // color for visited
        visited[row][col] = 1;

        if (maze[row][col] == 2)
        {
            cout << " We are in the exit!" << endl;
            visited[row][col] = 0;
            break;
        }
        // ↑ move to up
        if (maze[row - 1][col] != 1 && visited[row - 1][col] == 0)
        {
            r.push(row - 1);
            c.push(col);
        }
        // → move to right
        if (maze[row][col + 1] != 1 && visited[row][col + 1] == 0)
        {
            r.push(row);
            c.push(col + 1);
        }
        // ↓ move to down
        if (maze[row + 1][col] != 1 && visited[row + 1][col] == 0)
        {
            r.push(row + 1);
            c.push(col);
        }
        // ← move to left
        if (maze[row][col - 1] != 1 && visited[row][col - 1] == 0)
        {
            r.push(row);
            c.push(col - 1);
        }
    }
}

int main()
{
    cout << "DFS for all passible path :" << endl;
    dfs(0, 0);

    cout << "\n=============================" << endl;

    cout << "BFS for shortest path :" << endl;
    bfs(4, 0);

    return 0;
}