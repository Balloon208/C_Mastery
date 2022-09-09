// BJ7662

/*
이중 우선순위 큐를 만들기 위하여 오름차순 큐와 내림차순 큐를 만든다.

오름차순/내림차순 큐의 값이 빠지게 된다면 남은 큐도 빠저야 하므로 map으로 개수를 새어 한 쪽에만 있는 것을 없앤다.


while(!pq_desc.empty() && lef[pq_desc.top()]==0)
{
    pq_desc.pop();
}

*/

#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;

map<int, int> lef;
priority_queue<int, vector<int>, greater<int>>pq_asc;
priority_queue<int, vector<int>>pq_desc;

void solve()
{
    // 초기화 부분
    while(!pq_asc.empty()) pq_asc.pop();
    while(!pq_desc.empty()) pq_desc.pop();
    lef.clear();

    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        char com;
        int num;
        cin >> com >> num;

        if(com == 'I')
        {
            pq_asc.push(num);
            pq_desc.push(num);
            if(lef.count(num)==0) lef[num]=1;
            else lef[num]++;
        }
        else if(com == 'D')
        {
            if(num==1)
            {
                while(!pq_desc.empty() && lef[pq_desc.top()]==0) // 한쪽에만 있을 경우 비움
                {
                    pq_desc.pop();
                }

                if(!pq_desc.empty())
                {
                    lef[pq_desc.top()]--;
                    pq_desc.pop();
                }
            }
            else if(num==-1)
            {
                while(!pq_asc.empty() && lef[pq_asc.top()]==0) // 한쪽에만 있을 경우 비움
                {
                    pq_asc.pop();
                }
                if(!pq_asc.empty())
                {
                    lef[pq_asc.top()]--;
                    pq_asc.pop();
                }
            }
        }
    }

    // 모든 과정이 끝나고 한번더 검사를 함.

    while(!pq_desc.empty() && lef[pq_desc.top()]==0)
    {
        pq_desc.pop();
    }
    while(!pq_asc.empty() && lef[pq_asc.top()]==0)
    {
        pq_asc.pop();
    }
    if(!pq_asc.empty() && !pq_desc.empty()) cout << pq_desc.top() << " " << pq_asc.top() << '\n';
    else cout << "EMPTY" << '\n';

    return;
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
