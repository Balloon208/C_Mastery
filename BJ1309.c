/* 1 -> 3
2 -> 7
3 -> 17
4 -> 41

DP[i]=DP[i-1]*2 + DP[i-2]

*/

#include <stdio.h>

int main()
{
    int dp[100001]={0, }, n;

    dp[1]=3;
    dp[2]=7;
    for(int i=3; i<=100000; i++)
    {
        dp[i]=(dp[i-1]*2 +dp[i-2])%9901;
    }

    scanf("%d", &n);
    printf("%d", dp[n]);
}
