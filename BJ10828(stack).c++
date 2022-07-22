#include <iostream>
#include <stdio.h>
#include <stack>

using namespace std;

int N, a;
string s;
stack<int> stac;

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
            stac.push(a);
        }
        else if(s=="pop")
        {
            if(!stac.empty())
            {
                cout << stac.top() << '\n';
                stac.pop();
            }
            else cout << -1 << '\n';
        }
        else if(s=="size")
        {
            cout << stac.size() << '\n';
        }
        else if(s=="empty")
        {
            cout << stac.empty() << '\n';
        }
        else if(s=="top")
        {
            if(!stac.empty()) cout << stac.top() << '\n';
            else  cout << -1 << '\n';
        }
    }

    return 0;
}
