#include <iostream>
#include <stack>

using namespace std;

stack<pair<int, int>> s;
long long ans;
int arr[500005];

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    for(int i=0; i<n; i++)
    {
        int cnt=1;

        while(!s.empty() && s.top().first <= arr[i])
        {
            // stack이 비어있으면 왼쪽을 볼 가능성이 존재하지 않으므로, 바로 push 해준다
            // 만약 stack이 비어있지 않다면, 나보다 작은 녀석들의 가능성으로 모두 없애준다.

            // 나와 같은 숫자 인경우
            // 중복을 카운팅 하며 pop한다.
            if(s.top().first == arr[i])
            {
                cnt += s.top().second;
                ans += s.top().second;
                s.pop();
            }
            else // 나보다 작은 놈일 경우엔, 답만 더해준다.
            {
                ans += s.top().second;
                s.pop();
            }
        }
        if(!s.empty()) ans++; // 비어있지 않는 한, 본인의 왼쪽을 볼 수 있다.
        s.push(make_pair(arr[i], cnt)); // 본인의 높이와 개수를 stack에 넣는다.
    }
    cout << ans;
}
