/* #include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <math.h>

using namespace std;

int solution()
{
    int building[1001]={};
    int buildinglink[1001]={};
    int time[1001]={};
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
        buildinglink[ln]++;
    }

    cin >> d;

    int maximum, result=0;
    for(int i=1; i<=n; i++)
    {
        maximum=0; // 최대치 초기화
        for(int j=1; j<=n; j++)
        {
            if(buildinglink[j]==0) // 차수가 0일때
            {
                buildinglink[j]--; // 방문 처리

                cout << "차수 0 노드 : " << j << " / 크기 : " << graph[j].size() << " / 시간 : " << building[j] << " 연결노드 : ";

                for(int l=0; l<graph[j].size(); l++) // 연결된 개수 만큼 반복
                {
                    cout << graph[j][l] << " ";

                    q.push(graph[j][l]); // 연결된 노드를 큐에 넣음

                    if(maximum<building[j]) maximum=building[j]; // 이번에 건설 할 차례에 가장 오래 걸리는 것을 찾는 과정
                }

                if(j==d)
                {
                    return time[i-1]+building[j]; // 해당 건물이 도착지라면, 이전까지 지은 시간과 본인을 짓는 시간을 더함.
                }
                cout << '\n';
            }
        }

        while(!q.empty()) // 해당 노드의 링크(차수)를 줄임.
        {
            buildinglink[q.front()]--;
            q.pop();
        }

        time[i]=time[i-1]+maximum; // i번째로 건설하는데 걸리는 시간은 이전에 건설하는 시간 + 이번에 건설할 때 가장 오래 걸리는 시간
        cout << i << "회 시간 : " << time[i] << '\n';
    }
}

int main()
{
    int t;

    cin >> t;
    for(int i=0; i<t; i++)
    {
        cout << solution() << "!!";
    }
}

*/

#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <math.h>

using namespace std;

int solution()
{
    int building[1001]={};
    int buildinglink[1001]={};
    int time[1001]={};
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
        buildinglink[ln]++;
    }

    cin >> d;

    int maximum, result=0;
    for(int i=1; i<=n; i++)
    {
        maximum=0; // 최대치 초기화
        for(int j=1; j<=n; j++)
        {
            if(buildinglink[j]==0) // 차수가 0일때
            {
                buildinglink[j]--; // 방문 처리

                for(int l=0; l<graph[j].size(); l++) // 연결된 개수 만큼 반복
                {
                    q.push(graph[j][l]); // 연결된 노드를 큐에 넣음

                    if(maximum<building[j]) maximum=building[j]; // 이번에 건설 할 차례에 가장 오래 걸리는 것을 찾는 과정
                }

                if(j==d)
                {
                    return time[i-1]+building[j]; // 해당 건물이 도착지라면, 이전까지 지은 시간과 본인을 짓는 시간을 더함.
                }
            }
        }

        while(!q.empty()) // 해당 노드의 링크(차수)를 줄임.
        {
            buildinglink[q.front()]--;
            q.pop();
        }

        time[i]=time[i-1]+maximum; // i번째로 건설하는데 걸리는 시간은 이전에 건설하는 시간 + 이번에 건설할 때 가장 오래 걸리는 시간
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

