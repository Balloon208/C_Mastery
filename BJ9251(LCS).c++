/*
ASAG
SWAG

  0 A S A G
0 0 0 0 0 0
S 0 0 1 1 1
W 0 0 1 1 1
A 0 0 1 2 2
G 0 0 1 2 3
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int dp[1001][1001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string a, b;
    cin >> a >> b;
    for(int i=1; i<=a.length(); i++)
    {
        for(int j=1; j<=b.length(); j++)
        {
            if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout << dp[a.length()][b.length()];
}
