

// 크루스칼 최소 스패닝 트리

#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#define MAX 100001

using namespace std;

int parent[MAX];
vector<pair<int,int>>X; // 좌표, n번째
vector<pair<int,int>>Y;
vector<pair<int,int>>Z;
vector<tuple<int,int,int>>P; // 거리, 행성1, 행성2

int Find(int x)
{
    if(parent[x]==x) return x;
    else return parent[x]=Find(parent[x]);
}

bool Union(int a, int b)
{
    a=Find(a);
    b=Find(b);
    
    if(a==b) return false;
    else
    {
        parent[a]=b;
        return true;
    }
}

int main()
{
    int n, x, y, z;
    int ans=0;
    
    cin >> n;
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
        cin >> x >> y >> z;
        // 좌표 삽입
        X.push_back(make_pair(x,i));
        Y.push_back(make_pair(y,i));
        Z.push_back(make_pair(z,i));
    }
    
    // 좌표 정렬(오름차순)
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    sort(Z.begin(), Z.end());
    
    for(int i=0;i<n-1;i++)
    {
        P.push_back({X[i+1].first-X[i].first,X[i].second,X[i+1].second});
        P.push_back({Y[i+1].first-Y[i].first,Y[i].second,Y[i+1].second});
        P.push_back({Z[i+1].first-Z[i].first,Z[i].second,Z[i+1].second});
    }
    
    // 크루스칼을 이용하기 위해 거리를 정렬해준다
    
    sort(P.begin(), P.end());
    
    // 크루스칼 최소 스패닝 트리 구하기 시작.
    for(int i=0;i<P.size();i++)
    {
        int dist=get<0>(P[i]);
        int fn=get<1>(P[i]);
        int ln=get<2>(P[i]);
        if(Union(fn, ln)) ans+=dist;
    }
    
    cout << ans;
}