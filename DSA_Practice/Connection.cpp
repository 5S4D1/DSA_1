#include <bits/stdc++.h>
#include <stack>
using namespace std;

int graph[4][4] = {
    {0, 1, 0, 1},
    {0, 0, 1, 0},
    {1, 1, 0, 0},
    {0, 1, 0, 0}};

int color[4] = {0, 0, 0, 0};
char vertex[4] ={'A', 'B', 'C', 'D'};

int main()
{
    cout<<"Connection of each vertex: "<< endl;
    for(int i = 0; i<4; i++)
    {
        cout<<vertex[i]<<" : ";
        for(int j = 0; j<4; j++)
        {
            if(graph[i][j])
                cout<<vertex[j]<<" ";
        }
        cout<<endl;
    }
}