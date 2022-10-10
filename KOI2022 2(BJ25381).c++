/*

오답 코드 (58점)
이유 : 검사조건을 특수하게 걸었기 때문에(B 감지 -> C 감지를 큐가 비어있을때만) 시간초과가 났다.

#include <iostream>
#include <queue>

using namespace std;

int result=0;
queue<pair<char, int>> q;
bool alock=true, block=true;
string s;

void removebc()
{
    while(block)
    {
        while(!q.empty()) q.pop();
        block=false;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='B' && q.empty())
            {
                q.push(make_pair('B', i));
            }
            if(s[i]=='C' && !q.empty() && q.front().second<i)
            {
                s[i]='0';
                s[q.front().second]='0';
                q.pop();
                result++;
                block=true;
            }
        }
    }
}

void removeac()
{
    while(alock==true)
    {
        while(!q.empty()) q.pop();
        // cout << '!';
        alock=false;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='A' && q.empty())
            {
                q.push(make_pair('A', i));
            }
            if(s[i]=='B' && !q.empty() && q.front().second<i)
            {
                s[i]='0';
                s[q.front().second]='0';
                q.pop();
                result++;
                alock=true;
            }
        }
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> s;
    removebc();
    removeac();

    cout << result;
}
*/

// 해결 방안 : 기존에서 한번에 전체를 받는 코드는 작성이 힘들다.
// 따라서 한번에 전체를 받을 수 있도록 역순으로 돌려서 코드를 다시 짰다.

#include <iostream>
#include <queue>

using namespace std;

int result=0;
queue<pair<char, int>> q;
bool alock=true, block=true;
string s;

void removebc()
{
    while(block)
    {
        while(!q.empty()) q.pop();
        block=false;
        for(int i=s.length()-1; i>=0; i--)
        {
            if(s[i]=='C')
            {
                q.push(make_pair('C', i));
            }
            if(s[i]=='B' && !q.empty() && q.front().second>i)
            {
                s[i]='0';
                s[q.front().second]='0';
                q.pop();
                result++;
                block=true;
            }
        }
    }
}

void removeac()
{
    while(alock==true)
    {
        while(!q.empty()) q.pop();
        // cout << '!';
        alock=false;
        for(int i=s.length()-1; i>=0; i--)
        {
            if(s[i]=='B')
            {
                q.push(make_pair('B', i));
            }
            if(s[i]=='A' && !q.empty() && q.front().second>i)
            {
                s[i]='0';
                s[q.front().second]='0';
                q.pop();
                result++;
                alock=true;
            }
        }
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    removeac();
    removebc();

    cout << result;
}
