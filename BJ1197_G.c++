// 개념 참고글 : https://4legs-study.tistory.com/111
// 최소 스패닝 트리 (크루스갈)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ver, e;
int parent[10001];
vector<pair<int, pair<int, int>>> v;


int Find(int x)
{
    if(parent[x]==x) return x;
    else return parent[x] = Find(parent[x]);
}

void unions(int a, int b)
{
    a = Find(a);
    b = Find(b);

    if(a!=b) parent[b]=a;
}

void solve()
{
    cin >> ver >> e;

    int fn, ln, cost;
    int ans=0;
    for(int i=0; i<e; i++)
    {
        cin >> fn >> ln >> cost;
        v.push_back(make_pair(cost, make_pair(fn, ln)));
    }

    sort(v.begin(), v.end()); // 낮은 값부터 채워주는 형식이므로 sort 해준다.

    for(int i=1; i<=ver; i++)
    {
        parent[i]=i;
    }

    for(int i=0; i<e; i++)
    {
        if(Find(v[i].second.first)!=Find(v[i].second.second)) // 둘의 부모가 다르다면 서로 이어주어야함 (안이어져 있으니)
        {
            unions(v[i].second.first, v[i].second.second);
            ans += v[i].first;
        }
    }

    cout << ans;
}



int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    solve();

    return 0;
}
