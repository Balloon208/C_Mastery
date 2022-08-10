#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <math.h>

using namespace std;

int solution()
{
    int building[1001]={};
    int buildinglink[1001]={};
    vector<int> time[1001]={};
    vector<int> graph[1001]={};
    queue<int> q;

    int n, k, d;
    cin >> n >> k;
    for(int i=1; i<=n; i++)
    {
        cin >> building[i];
    }
    for(int i=1; i<=k; i++)
    {
        int fn, ln;
        cin >> fn >> ln;
        graph[fn].push_back(ln);
        buildinglink[ln]++; // 연결된 차수 추가
    }

    cin >> d;

    for(int i=1; i<=1000; i++)
    {
        for(int j=1; j<=1000; j++)
        {
            if(buildinglink[j]==0) // 차수가 0이라면
            {
                if(!time[j].empty())building[j] += *max_element(time[j].begin(), time[j].end()); // j건물을 짓는데 가장 오래 걸리는 시간을 더함

                buildinglink[j]--; // 방문 처리 (차수 -1)
                for(int l=0; l<graph[j].size(); l++)
                {
                    q.push(graph[j][l]); // 연결된 노드를 큐에 넣음
                }

                while(!q.empty())
                {
                    time[q.front()].push_back(building[j]); // 차수가 0인 노드의 시간을 큐에 담긴(연결된) 노드에 넣음
                    buildinglink[q.front()]--; // 큐에 들어간 차수를 줄임
                    q.pop();
                }
                if(j==d) return building[j];
            }
        }
    }
}

int main()
{
    int t;

    cin >> t;
    for(int i=0; i<t; i++)
    {
        cout << solution() << '\n';
    }
}

