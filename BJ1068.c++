#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[51];
bool visited[51];
int result=0, removenum;

void dfs(int start)
{
    visited[start]=true; // 해당 지점 방문 처리

    if(graph[start].size()==0) result++; // 만약 리프 노드면 결과값 추가
    else // 연결된 노드가 있을 경우 재귀를 통해 리프 노드를 탐색한다.
    {
        for(int i=0; i<graph[start].size(); i++)
        {
            int next = graph[start][i];

            if(next==removenum) // 만약 다음 노드가 삭제되었다면
            {
                if(graph[start].size()==1) result++; // 만약 일자형 노드라면 바로 종료되므로 리프 노드를 하나 추가해주는 코드
                
                continue; // 해당 그래프 탐색을 건너뜀
            }
            else if(visited[next]!=true) // 삭제되지 않았고, 방문하지 않았으면 재귀한다.
            {
                dfs(next);
            }
        }
    }
}

int main()
{
    int n, num, start;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        cin >> num;
        if(num==-1) start=i;
        else
        {
            graph[num].push_back(i);
        }
    }

    cin >> removenum; // 삭제할 노드

    if(removenum==start) result=0; // 지우는 노드가 시작 노드이면 0
    else dfs(start);

    cout << result;
}
