// BJ7576의 3차원 버전

#include <iostream>
#include <string.h>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

queue<tuple<int, int, int>> q;

int n, m, h;
int arr[101][101][101]={0, };
int deep[101][101][101]={0, };
bool visited[101][101][101]={0, };

int dx[6]={1, 0, -1, 0, 0, 0};
int dy[6]={0, 1, 0, -1, 0, 0};
int dz[6]={0, 0, 0, 0, 1, -1};

void bfs()
{
    while(!q.empty())
    {
        int x=get<0>(q.front());
        int y=get<1>(q.front());
        int z=get<2>(q.front());

        visited[z][y][x]=true;
        q.pop();
        for(int i=0; i<6; i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            int nz=z+dz[i];

            if(0<=nx && nx<n && 0<=ny && ny<m && 0<=nz && nz<h)
            {
                if(arr[nz][ny][nx]==0 && visited[nz][ny][nx]==false)
                {
                    visited[nz][ny][nx]=true;
                    arr[nz][ny][nx]=1;
                    deep[nz][ny][nx]=deep[z][y][x]+1;
                    q.push(make_tuple(nx, ny, nz));
                }
            }
        }
    }
}

int main()
{
    int result = 0;

    cin >> n >> m >> h;

    for(int i=0; i<h; i++)
    {
        for(int j=0; j<m; j++)
        {
            for(int k=0; k<n; k++)
            {
                cin >> arr[i][j][k];
                if(arr[i][j][k]==1)
                {
                    deep[i][j][k]=1;
                    q.push(make_tuple(k, j, i)); // x, y, z를 큐에 집어넣음
                }
            }
        }
    }

    bfs();

    /*
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<m; j++)
        {
            for(int k=0; k<n; k++)
            {
                cout << arr[i][j][k] << " ";
            }
            cout << '\n';
        }
    }
    */

    for(int i=0; i<h; i++)
    {
        for(int j=0; j<m; j++)
        {
            for(int k=0; k<n; k++)
            {
                if(arr[i][j][k]==0)
                {
                    cout << -1;
                    return 0;
                }
            }
        }
    }

    for(int i=0; i<h; i++)
    {
        for(int j=0; j<m; j++)
        {
            for(int k=0; k<n; k++)
            {
                result=max(result, deep[i][j][k]);
            }
        }
    }

    cout << result-1;
}
