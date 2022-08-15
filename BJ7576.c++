#include <iostream>
#include <string.h>
#include <queue>
#include <algorithm>

using namespace std;

queue<pair<int, int>> q;

int n, m;
int arr[1001][1001]={0, };
int deep[1001][1001]={0, };
bool visited[1001][1001]={0, };

int dx[4]={1, 0, -1, 0};
int dy[4]={0, 1, 0, -1};

void bfs()
{
    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        visited[y][x]=true; // 방문 처리
        q.pop();
        for(int i=0; i<4; i++)
        {
            // 다음 좌표 구하기
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(0<=nx && nx<n && 0<=ny && ny<m) // 범위 내에 속할 경우
            {
                if(arr[ny][nx]==0 && visited[ny][nx]==false) // 토마토가 있고, 방문하지 않았다면.
                {
                    visited[ny][nx]=true; // 방문처리
                    arr[ny][nx]=1; // 토마토가 익고
                    deep[ny][nx]=deep[y][x]+1; // 그래프의 깊이는 이전에 비해 1 증가
                    q.push(make_pair(nx, ny)); // 해당 지점에서 다시 찾아보기 위해 큐에 집어 넣음
                }
            }
        }
    }
}

int main()
{
    int result = 0;

    cin >> n >> m;

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> arr[i][j];
            if(arr[i][j]==1)
            {
                deep[i][j]=1;
                q.push(make_pair(j, i)); // x, y를 큐에 집어넣음
            }
        }
    }

    bfs();

    /*
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }*/

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(arr[i][j]==0)
            {
                cout << -1;
                return 0;
            }
        }
    }

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            result=max(result, deep[i][j]);
        }
    }

    cout << result-1;
}
