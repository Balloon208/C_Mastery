#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void dfs(int start, vector<int>graph[], bool visited[])
{
    visited[start] = true; // 해당 지점 방문
    cout << start << " "; // 출력
    for(int i=0; i<graph[start].size(); i++) // 해당 지점과 연결되어 있는 간선의 수만큼 반복
    {
        int next = graph[start][i]; // 다음 으로 조사 할 것은 graph[start][0], graph[start][1]...
        if(visited[next]==false) dfs(next, graph, visited); // 방문 하지 않았다면 재귀적으로 찾는다. (깊이 우선적으로 탐색하게 된다.)
    }
}

int main()
{
    int n, m, s, fn, ln;

    cin >> n >> m >> s;

    bool dfsvisited[1001];
    vector<int> dfsgraph[1001];

    for(int i=0; i<m; i++)
    {
        cin >> fn >> ln;

        dfsgraph[fn].push_back(ln);
        dfsgraph[ln].push_back(fn);
    }

    for(int i=1; i<=n; i++)
    {
        sort(dfsgraph[i].begin(), dfsgraph[i].end()); // 낮은것 부터 순차적으로 접근 해야하므로 sort 해준다.
    }

    dfs(s, dfsgraph, dfsvisited);
}

#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void dfs(int start, vector<int>graph[], bool visited[])
{
    visited[start] = true; //  해당 지점을 방문한다.
    cout << start << " "; // 출력
    for(int i=0; i<graph[start].size(); i++) // 해당 지점과 연결되어 있는 간선의 수 만큼 반복
    {
        int next = graph[start][i]; // 가장 숫자가 낮은 간선을 찾음
        if(visited[next]==false) dfs(next, graph, visited); // 방문하지 않았다면 재귀함수로 돌림.
    }
}

void bfs(int start, vector<int>graph[], bool visited[])
{

    /* ex :      1
             2      3
           4 5 6   7  8

           queue -> 1 -> 2, 3 -> 3, 4, 5, 6, -> 4, 5, 6, 7, 8 -> 5, 6, 7, 8 -> 6, 7, 8 ...
    */
    queue<int> q;
    q.push(start); // 시작 지점을 큐에 넣음
    visited[start]=true; // 해당 지점을 방문한다.

    while(!q.empty()) // 큐가 빌 때 까지
    {
        int x=q.front();
        q.pop(); // 큐를 비우고
        cout << x << " "; // 출력
        for(int i=0; i<graph[x].size(); i++) // 해당 지점과 연결되어 있는 간선만큼 반복
        {
            int y = graph[x][i]; // 가장 숫자가 낮은 간선을 찾음

            if(!visited[y]) // 방문하지 않았다면
            {
                q.push(y); // 해당 지점을 큐에 넣고
                visited[y]=true; // 방문 처리를 함
            }
        }
    }
}

int main()
{
    int n, m, s, fn, ln;

    cin >> n >> m >> s;

    bool dfsvisited[1001];
    bool bfsvisited[1001];
    vector<int> dfsgraph[1001];
    vector<int> bfsgraph[1001];

    for(int i=0; i<m; i++)
    {
        cin >> fn >> ln;

        dfsgraph[fn].push_back(ln);
        dfsgraph[ln].push_back(fn);
        bfsgraph[fn].push_back(ln);
        bfsgraph[ln].push_back(fn);
    }

    for(int i=1; i<=n; i++)
    {
		sort(dfsgraph[i].begin(), dfsgraph[i].end());
		sort(bfsgraph[i].begin(), bfsgraph[i].end());
	}

    dfs(s, dfsgraph, dfsvisited);
    cout << '\n';
    bfs(s, bfsgraph, bfsvisited);
}
