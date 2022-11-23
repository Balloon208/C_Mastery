#include <iostream>
#include <algorithm>

/*
0
1 1
1 2 2 
1 3 5 5
1 4 9 14 14 
1 5 14 28 42 42
1 6 20 48 90 132 132
*/

long long dp[31][31]={0,}; // dp[w][f];

using namespace std;

void init()
{
    for(int i=1; i<=30; i++)
    {
        dp[i][0]=1;
    }

    for(int i=1; i<=30; i++)
    {
        for(int j=1; j<=30; j++)
        {
            if(i<j) break;
            else dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
}

int main()
{
    init();
    int n;
    while(1)
    {
        cin >> n;
        if(n==0) break;
        cout << dp[n][n] << '\n';
    }
}
