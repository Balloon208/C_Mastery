#include <iostream>
#include <algorithm>

using namespace std;

int dp[1000001];

void solve(int n)
{
    for(int i=1; i<=1000000; i++)
    {
        dp[i]=i;
    }
    for(int i=2; i<=1000000; i++)
    {
        if(i%2==0) dp[i]=min(dp[i], dp[i/2]);
        if(i%3==0) dp[i]=min(dp[i], dp[i/3]);
        dp[i] = min(dp[i], dp[i-1])+1;
    }
    
    cout << dp[n]-1 << '\n';
    
    while(n)
    {
        cout << n << " ";
        if(dp[n] == dp[n-1]+1) n--;
        else if(n%2==0 && dp[n] == dp[n/2]+1) n/=2;
        else if(n%3==0 && dp[n] == dp[n/3]+1) n/=3;
    }
}
int main()
{
    int n;
    cin >> n;
    solve(n);
}