#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int visited[101][101];
char map[101][101];
int graph[101][101];

int n, m;

int dx[4]={1, 0, -1, 0};
int dy[4]={0, 1, 0, -1};

// 오른쪽, 아래, 왼쪽, 위

void bfs(int x, int y)
{
    visited[x][y]=1;
    graph[x][y]=1;

    queue<pair<int, int>> q; // 정수 2개를 큐에 담는다
    q.push(make_pair(x, y)); // 큐에 넣기

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for(int i=0; i<4; i++) // 해당 주위를 탐색한다.
        {
            int nextX = x + dx[i];
            int nextY = y + dy[i];

            if(0<=nextX && nextX<n && 0<=nextY && nextY < m) // 미로 범위
            {
                if(map[nextX][nextY]=='1'&&visited[nextX][nextY]==0) // 길이 있고, 방문되지 않았다면
                {
                    graph[nextX][nextY]=graph[x][y] + 1; // 거리를 추가하고
                    visited[nextX][nextY]=1; // 방문 처리를 한 후
                    q.push(make_pair(nextX, nextY)); // 해당 좌표를 큐에 넣는다
                }
            }
        }
    }
}

int main()
{
    int n1, n2;

    cin >> n >> m;

    for(int i=0; i<n; i++)
    {
        cin >> map[i];
    }

    bfs(0, 0); // 0,0 부터 간다.

    cout << graph[n-1][m-1];
}