/*

5 2
15 0
55 1
115 1 
155 2
515 2
555 0
1115 2
1155 0
1515 0
1555 1
5115 0
5155 1
5515 1
5555 2


arr[0][2] = arr[1][1]+arr[2][1]
arr[1][2] = arr[2][1]+arr[0][1]
arr[2][2] = arr[0][1]+arr[1][1]

   1 2 3 4 5 6 7 8 9
0 0 1 1 3
1 0 1 1 3
2 1 0 2 2

*/

#include <iostream>
#define mod 1000000007

using namespace std;

int dp[4][2022]{};

void dpset()
{
    dp[0][1]=0;
    dp[1][1]=0;
    dp[2][1]=1;
    for(int i=2; i<=1515; i++)
    {
        dp[0][i]=(dp[1][i-1]+dp[2][i-1])%mod;
        dp[1][i]=(dp[0][i-1]+dp[2][i-1])%mod;
        dp[2][i]=(dp[0][i-1]+dp[1][i-1])%mod;
    }
}

int main()
{
    dpset();
    int n;
    cin >> n;

    cout << dp[0][n];
}
