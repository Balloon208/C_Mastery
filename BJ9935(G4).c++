#include <iostream>
#include <vector>
#include <string>

using namespace std;

string s, bomb;
//놀랍게도, vector는 pop 연산이 가능하며, deque처럼 쓸수도 있다. 
//push_front(V)를 하려면 insert(begin(),V)을 대신 호출하면 된다.
//따라서, stack처럼 쓰기 위하여 vector를 들고오게 되었다.

vector<char> v;
int main()
{
    cin >> s >> bomb;
    int size_s = (int)s.size();
    int size_bomb = (int)bomb.size();

    for(int i=0; i<size_s; i++)
    {
        v.push_back(s[i]);

        if((int)v.size()>=size_bomb) // 이때까지 들고온 글자가 폭탄길이보다 크면?
        {
            int booming=true;
            for(int j=0; j<size_bomb; j++)
            {
                if(v[v.size()-size_bomb+j]!=bomb[j]) // v.size()는 점점 커지므로, 폭발에 따라 커지고 작아진다.
                {
                    booming=false;
                    break;
                }
            }

            if(booming) // 문자열 폭발!
            {
                for(int j=0; j<size_bomb; j++)
                {
                    v.pop_back();
                }
            }
        }
    }

    if(v.empty()) cout << "FRULA";
    else
    {
        for(int i=0; i<(int)v.size(); i++)
        {
            cout << v[i];
        }
    }
}
