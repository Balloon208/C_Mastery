#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> graph[50001];
int parent[50001], level[50001];

void makegraph()
{
    int n, s, e;
    cin >> n;
    for(int i=0; i<n-1; i++)
    {
        cin >> s >> e;
        graph[e].push_back(s);
        graph[s].push_back(e);
    }
}

void maketree(int node, int pnode) // dfs
{
    parent[node]=pnode;
    level[node]=level[pnode]+1;

    for(int i=0; i<graph[node].size(); i++)
    {
        int child=graph[node][i];
        if(child==pnode) continue; // 부모노드라면 들어가지 않는다.

        maketree(child, node);
    }
}

int lca(int a, int b)
{
    if(level[a]<level[b]) swap(a,b); // 항상 a > b이다.

    while(level[a]!=level[b]) // 레벨을 같게 만들자
    {
        a=parent[a];
    }

    while(a!=b) // 같은 부모를 찾을때 까지 거슬러 올라가자
    {
        a=parent[a];
        b=parent[b];
    }
    return a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    makegraph();
    maketree(1, 0);

    int a, b, t;
    cin >> t;
    for(int i=0; i<t; i++)
    {
        cin >> a >> b;
        cout << lca(a,b) << '\n';
    }
}
