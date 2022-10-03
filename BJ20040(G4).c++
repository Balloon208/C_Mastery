#include <iostream>

using namespace std;

int parent[500000];
int result=0;
int cnt=0;

int Find(int x)
{
    if(parent[x]==x) return x;
    else return parent[x]=Find(parent[x]);
}
bool Union(int na, int nb)
{
    int pa=Find(na); // 부모 노드를 찾고
    int pb=Find(nb); // 부모 노드를 찾고

    if(pa==pb) return true; // 부모가 같은가?
    parent[pb]=pa; // 아니면 합치자
    return false;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;

    for(int i=0; i<n; i++)
    {
        parent[i]=i; // 부모 초기화
    }
    for(int i=1; i<=m; i++)
    {
        int fn, ln;
        cin >> fn >> ln;

        if(Union(fn, ln) && result==0) result = i; // 단 한번만 result 값이 바뀜
    }

    cout << result;
}
