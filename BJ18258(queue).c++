/*

오답 코드
이유 : 시간초과
설명 : endl은 출력 버퍼를 비우기 때문에 시간이 오래걸린다.
대책 방안 : endl 대신 '\n'을 집어넣자.

#include <iostream>
#include <queue>

using namespace std;

int N, a;
string s;

queue<int> q;

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin >> N;

    for(int i=0; i<N; i++)
    {
        cin >> s;

        if(s=="push")
        {
            cin >> a;
            q.push(a);
        }
        else if(s=="pop")
        {
            if(!q.empty())
            {
                cout << q.front() << endl;
                q.pop();
            }
            else cout << "-1" << endl;
        }
        else if(s=="size")
        {
            cout << q.size() << endl;
        }
        else if(s=="empty")
        {
            cout << q.empty() << endl;
        }
        else if(s=="front")
        {
            if(!q.empty()) cout << q.front() << endl;
            else  cout << "-1" << endl;
        }
        else if(s=="back")
        {
            if(!q.empty()) cout << q.back() << endl;
            else  cout << "-1" << endl;
        }
    }

    return 0;
}

*/

#include <iostream>
#include <queue>

using namespace std;

int N, a;
string s;
queue<int> q;

int main()
{
    cin.tie(NULL); // 고속 입출력을 위해 사용
    cin.sync_with_stdio(false); // 고속 입출력을 위해 사용

    cin >> N;

    for(int i=0; i<N; i++)
    {
        cin >> s;

        if(s=="push")
        {
            cin >> a;
            q.push(a);
        }
        else if(s=="pop")
        {
            if(!q.empty())
            {
                cout << q.front() << '\n';
                q.pop();
            }
            else cout << -1 << '\n';
        }
        else if(s=="size")
        {
            cout << q.size() << '\n';
        }
        else if(s=="empty")
        {
            cout << q.empty() << '\n';
        }
        else if(s=="front")
        {
            if(!q.empty()) cout << q.front() << '\n';
            else  cout << -1 << '\n';
        }
        else if(s=="back")
        {
            if(!q.empty()) cout << q.back() << '\n';
            else  cout << -1 << '\n';
        }
    }

    return 0;
}
