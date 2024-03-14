#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

priority_queue<pair<long long, pair<int, int>>> pq; // 비용, 노드, 포장
long long cost[10010][21];
long long n, m, k, a, b, t;
vector<pair<int, int>> v[10010];

long long dijkstra(int start)
{
    int cnode, nnode; // current node, next node
    long long ccost;
    long long ncost;
    long long min_c = -1;

    // init
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<21; j++)
        {
            cost[i][j]=-1;
        }
    }

    cost[start][0]=0;
    pq.push({-0, {start, 0}});

    while(!pq.empty())
    {
        ccost = -pq.top().first;
        cnode = pq.top().second.first;
        int cnt = pq.top().second.second;
        pq.pop();

        if(ccost > cost[cnode][cnt]) // 현재 계산값이 더 크면 패스
        {
            continue;
        }

        for(int i=0; i<v[cnode].size(); i++)
        {
            nnode = v[cnode][i].first;
            ncost = v[cnode][i].second + ccost;

            if(cnt < k) // 포장도로가 남아있으면 비용이 0이 추가 되니 본인 노드의 값으로 가본다
            {
                if(cost[nnode][cnt+1] == -1) // 초기화값이면
                {
                    cost[nnode][cnt+1] = ccost;
                    pq.push({-ccost, {nnode, cnt+1}});
                }
                if(cost[nnode][cnt+1] > ccost) // 더 싸다면
                {
                    cost[nnode][cnt+1] = ccost;
                    pq.push({-ccost, {nnode, cnt+1}});
                }
            }

            if(cost[nnode][cnt] > ncost || cost[nnode][cnt] == -1)
            {
                cost[nnode][cnt] = ncost;
                pq.push({-ncost, {nnode, cnt}});
            }
        }
    }

    min_c = cost[n][0];

    for(int i=1; i<=k; i++)
    {
        if(cost[n][i] == -1) continue;
        min_c = min(min_c, cost[n][i]);
    }

    return min_c;
}


int main()
{
    cin >> n >> m >> k;

    for(int i=0; i<m; i++)
    {
        cin >> a >> b >> t;
        v[a].push_back({b, t});
        v[b].push_back({a, t});
    }

    long long res = dijkstra(1);

    cout << res;
}