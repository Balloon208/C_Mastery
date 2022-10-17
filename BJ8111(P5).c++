/*
    블로그에서 얻은 힌트 ( https://nanyoungkim.tistory.com/m/121 )

    어떤 수 x 가 N의 배수인지 확인하려면 (x mod N) 이 0인지 확인할 수도 있겠지만
    x가 계속 커지는 걸 방지하기 위해 (x mod N) mod N이 0인지 확인하면 된다.
    modular 연산의 성질에 의해 (x mod N) 는 (x mod N) mod N와 같기 때문이다.

    그래서 x 대신 "현재의 수 cur에 0또는 1을 붙이고 N으로 나눈 나머지"를 고려하면 된다.

    cur = 1이라면 node[0]은 10%N. node[1] = 11%N이 된다.
    
    
    이후 아이디어
    
    이후 역순으로 출력을 해야하므로 부모를 찾아 거슬러 올라가며 거꾸로 출력하게 한다.
*/

#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

int n;
pair<int, char> arr[20001];
bool visited[20001];

void bfs()
{
    memset(visited, false, sizeof(visited));// 그래프 초기화

    queue<int> q;
    q.push(1); // 첫글자는 1부처

    arr[1].first = -1; // 부모 노드
    arr[1].second = '1'; // 최대 100자리 이므로 string 으로 받아준다

    visited[1]=true;

    while(!q.empty())
    {
        int tmp = q.front();
        q.pop();

        //자식 노드 2개, 가지치기, 0과 1을 붙일 수 있음 (힌트를 얻은 부분)
        int node[2];
        node[0] = (tmp*10 + 0)%n;
        node[1] = (tmp*10 + 1)%n;

        for(int i=0; i<2; i++)
        {
            if(visited[node[i]]==true) continue;

            arr[node[i]].first = tmp; // qnahfmf wjwkdgksek
            arr[node[i]].second = i + '0'; // 0 또는 1의 숫자를 char 형으로 저장

            if(node[i]==0) return; // 나누어 떨어졌다!

            visited[node[i]]=true;
            q.push(node[i]);
        }
    }
}

void Printing(int parent)
{
    if(parent==-1) return;
    Printing(arr[parent].first);
    cout << arr[parent].second;
}

void solve()
{
    cin >> n;
    if(n==1)
    {
        cout << 1 << '\n';
        return;
    }

    bfs();

    Printing(0);

    cout << '\n';

}
int main()
{
    int t;
    cin >> t;
    for(int i=0; i<t; i++)
    {
        solve();
    }
}
