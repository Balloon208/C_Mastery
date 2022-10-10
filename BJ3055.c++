#include <iostream>
#include <queue>

using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
char arr[51][51]; // 맵
int wdeep[51][51]; // 물 깊이
int pdeep[51][51]; // 고슴도치 깊이
bool wvisited[51][51]; // 물 방문처리
bool pvisited[51][51]; // 고슴도치 방문 처리
int fx, fy; // 도착 지점
int r, c;
queue<pair<int, int>>p;
queue<pair<int, int>>w;

void wbfs() // 물에 관하여 BFS 실행
{
    while(!w.empty())
    {
        int x=w.front().first;
        int y=w.front().second;
        wvisited[x][y]=true;
        
        w.pop();
        for(int i=0; i<4; i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            // 범위 내이며, 방문하지 않았고, .타일일 경우
            if(nx>=0 && nx<r && ny>=0 && ny<c && wvisited[nx][ny]==false && arr[nx][ny]=='.')
            {
                wdeep[nx][ny]=wdeep[x][y]+1;
                wvisited[nx][ny]=true;
                w.push(make_pair(nx,ny));
            }
        }
    }
}

void pbfs() // 고슴도치에 관하여 bfs 실행
{
    while(!p.empty())
    {
        int x=p.front().first;
        int y=p.front().second;
        pvisited[x][y]=true;
        
        p.pop();
        for(int i=0; i<4; i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            
            // 범위 내이며, 방문하지 않았고, X타일이 아니며, 잠기지 않는 깊이 일 경우
            if(nx>=0 && nx<r && ny>=0 && ny<c && pvisited[nx][ny]==false && arr[nx][ny]!='X' && (wdeep[nx][ny]-1>pdeep[x][y] || wdeep[nx][ny]==0))
            {
                pdeep[nx][ny]=pdeep[x][y]+1;
                pvisited[nx][ny]=true;
                p.push(make_pair(nx,ny));
            }
        }
    }
}

void input()
{
    cin >> r >> c;
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            cin >> arr[i][j];
            
            if(arr[i][j]=='S') p.push(make_pair(i,j));
            if(arr[i][j]=='*') w.push(make_pair(i,j));
            if(arr[i][j]=='D')
            {
                fx=i;
                fy=j;
            }
        }
    }
}

void output()
{
    /*for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            cout << pdeep[i][j];
        }
        cout << '\n';
    }*/
    if(pdeep[fx][fy]==0) cout << "KAKTUS";
    else cout << pdeep[fx][fy];
}

void solve()
{
    input();
    wbfs();
    pbfs();
    output();
}

int main()
{
    solve();
}