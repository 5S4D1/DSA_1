/*
    The Maze of Mysteries - Finding Paths  with Treasures
    Explore the maze, avoid walls (1)
    Pathway (0)
    collecting the Treasure on the way (3)
    ends at  the Exit (2)
*/
#include <bits/stdc++.h>
using namespace std;
int maze[5][5] = {0, 1, 1, 0, 2,
                  0, 1, 1, 0, 1,
                  0, 1, 1, 0, 1,
                  0, 1, 0, 0, 0,
                  0, 0, 0, 0, 1};

int visited[5][5] = {0, 0, 0, 0, 0,
                     0, 0, 0, 0, 0,
                     0, 0, 0, 0, 0,
                     0, 0, 0, 0, 0,
                     0, 0, 0, 0, 0};

void dfs(int row, int col)
{
    // Check the Boundary
    if (row < 0 || row > 4 || col < 0 || col > 4)
        return;

    cout << row << " , " << col << endl;
    // exit point finder
    if (maze[row][col] == 2)
        cout << "We are in the exit" << endl;

    // color for visited
    visited[row][col] = 1;
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
    queue <pair<int, int>> q;
    
    // Check the Boundary of maze
    if (row < 0 || row > 4 || col < 0 || col > 4)
        return;
    cout << row << " , " << col << endl;
    if(maze[row][col] == 2)
        cout << "We are in the exit" << endl;
    
    // color for visited
    visited[row][col] = 1;
    // → move to right
    if (maze[row][col + 1] != 1 && visited[row][col + 1] == 0)
    {
        q.push(make_pair(row,col + 1));
    }
    // ← move to left
    if(maze[row][col-1] != 1 && visited[row][col-1] == 0)
    {
        q.push(make_pair(row,col - 1));
    }
    // ↓ move to down
    if (maze[row + 1][col] != 1 && visited[row + 1][col] == 0)
    {
        q.push(make_pair(row + 1,col));
    }
    // ↑ move to up
    if (maze[row - 1][col] != 1 && visited[row - 1][col] == 0)
    {
        q.push(make_pair(row - 1,col));
    }
    
    bfs(q.front().first,q.front().second);
    q.pop();
    
    visited[row][col] = 0;
}

int main()
{
    //dfs(3, 0);
    bfs(3,0);

    return 0;
}