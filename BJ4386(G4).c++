// 크루스칼 최소 스패닝 트리

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

vector<pair<double, double>>v;
vector<pair<double, pair<int,int>>>edge;
int n;
int parent[101];
double Answer = 0;

int Find(int x)
{
    if(x==parent[x]) return x;
    else return parent[x] = Find(parent[x]);
}

void Union(int x, int y)
{
    x=Find(x);
    y=Find(y);
    
    parent[y]=x;
}

void solution()
{
    for(int i=0; i<v.size(); i++) // 하나의 별
    {
        double x1=v[i].first;
        double y1=v[i].second;
        
        for(int j=i+1; j<v.size(); j++) // 그 별보다 뒤에 있는 별
        {
            double x2=v[j].first;
            double y2=v[j].second;
            
            double dist = sqrt(pow(x1-x2,2)+pow(y1-y2,2)); // 거리를 구하여
            
            edge.push_back(make_pair(dist,make_pair(i,j))); // 크루스갈에 이용할 vector에 거리, 별 번호를 넣는다.
        }
    }
    
    for(int i=0; i<n; i++)
    {
        parent[i]=i; //부모 초기화
    }
    
    sort(edge.begin(), edge.end()); // 최소 스패닝 트리(크루스칼) 이므로 낮은 것부터 거리가 낮은 것부터 방문 해야함
    
    // 크루스칼 을 이용한 최소 스패닝 트리
    
    for(int i=0; i<edge.size(); i++)
    {
        double cost = edge[i].first;
        int node1 = edge[i].second.first;
        int node2 = edge[i].second.second;
        
        if(!(Find(node1)==Find(node2)))
        {
            Union(node1, node2);
            Answer+=cost;
        }
    }
    
    cout << Answer;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << fixed;
    cout.precision(2); // 소숫점 맞추기
    
    cin >> n;
    for(int i=0; i<n; i++)
    {
        double a, b;
        cin >> a >> b;
        v.push_back(make_pair(a,b));
    }
    
    solution();
}