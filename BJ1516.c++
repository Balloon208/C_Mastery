// BJ1005와 매우 흡사한 위상 정렬 문제.

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <math.h>

using namespace std;

int n;
int building[1001]={0,};
int buildinglink[1001]={0,};
vector <int> buildtime[1001];
vector<int> graph[1001];
queue<int> q;

void solution()
{
    for(int i=1; i<=1000; i++)
    {
        for(int j=1; j<=1000; j++)
        {
            if(buildinglink[j]==0) // 차수가 0이라면
            {
                if(!buildtime[j].empty())building[j] += *max_element(buildtime[j].begin(), buildtime[j].end()); // j건물을 짓는데 가장 오래 걸리는 시간을 더함

                buildinglink[j]--; // 방문 처리 (차수 -1)
                for(int l=0; l<graph[j].size(); l++)
                {
                    q.push(graph[j][l]);
                }

                while(!q.empty())
                {
                    buildtime[q.front()].push_back(building[j]); // 해당 시간을 넣음
                    buildinglink[q.front()]--;
                    q.pop();
                }
            }
        }
    }
}

int main()
{
    int node;
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> building[i];
        while(1)
        {
            cin >> node;
            if(node==-1) break;
            else
            {
                graph[node].push_back(i); // 해당 건물을 그래프에 넣는다.
                buildinglink[i]++; // 차수 추가
            }
        }
    }

    solution();

    for(int i=1; i<=n; i++)
    {
        printf("%d\n", building[i]);
    }
}
