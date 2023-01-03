#include <iostream>
#include <vector>
#include <algorithm>
#define NUMBER 1000050
#define ll long long

using namespace std;

ll arr[NUMBER]={};
ll tree[4*NUMBER];

ll init(ll s, ll e, ll node)
{
    if(s==e) return tree[node] = arr[s];
    ll mid = (s+e)/2;
    // 왼쪽 노드 : node * 2, 오른쪽 노드 : node * 2 +1
    return tree[node] = init(s,mid,node*2) + init(mid+1,e,node*2 + 1);
}

ll sum(ll s, ll e, ll node, ll left, ll right)
{
    // 구간 합이 범위 밖에 있는 경우
    if(left > e || right < s) return 0;
    // 구간 합이 범위 안에 있는 경우
    if(left <= s && right >= e) return tree[node]; // ex : s=3, e=5, l=2, r=7
    // 그렇지 않으면 분할한다.
    ll mid = (s+e)/2;
    return sum(s,mid,node*2,left,right) + sum(mid+1,e,node*2 + 1,left,right);
}

// index : 수정할 위치
// dif : 수정할 값
void update(ll s, ll e, ll node, ll index, ll diff)
{
    // 범위 밖에 있는 경우
    if(index < s || index > e) return;
    // 범위 안에 있으면, 계산하면서 내려가기.
    tree[node] += diff;
    if(s==e) return;
    ll mid = (s+e)/2;
    update(s,mid,node*2,index,diff);
    update(mid+1,e,node*2 + 1,index,diff);
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ll n, m, k, a, b, c;
    cin >> n >> m >> k;
    for(ll i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    init(0, n-1, 1); // 트리의 초기화
    for(ll i=0; i<m+k; i++)
    {
        cin >> a >> b >> c;
        if(a==1)
        {
            ll change = c - arr[b-1];
            arr[b-1]=c; // 트리 값 업데이트
            update(0, n-1, 1, b-1, change); // 트리 누적 합 업데이트
        }
        else if(a==2)
        {
            cout << sum(0, n-1, 1, b-1, c-1) << '\n';
        }
    }
}
