#include <iostream>
#include <memory.h>

using namespace std;

int dp[501][501][2] = {-1,};
int b[3];

bool win(int f, int s, bool p)
{
    if(dp[f][s][p] != -1) return dp[f][s][p]; // 이미 계산 완료!

    // 계산 안되어있다면 계산한다.
    for(int i=0; i<3; i++)
    {
        if(b[i] <= f && !win(f-b[i], s, !p)) return dp[f][s][p] = true; // 승패를 뒤집어준다.
        if(b[i] <= s && !win(f, s-b[i], !p)) return dp[f][s][p] = true; // 승패를 뒤집어준다.
    }

    return dp[f][s][p]=false;
}

int main()
{
    for(int i=0; i<3; i++)
    {
        cin >> b[i];
    }
    for(int i=0; i<5; i++)
    {
        memset(dp, -1, sizeof(dp));
        int f, s;
        cin >> f >> s;

        if(win(f,s,false)) cout << "A" << '\n';
        else cout << "B" << '\n';
    }
}
