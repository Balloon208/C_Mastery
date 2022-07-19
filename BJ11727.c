/*
1 -> 1
2 -> 3
3 -> 5
4 -> 11
*/

#include <stdio.h>

int main()
{
    int dp[1001]={0, };

    dp[0]=0;
    dp[1]=1;
    dp[2]=3;
    dp[3]=5;

    for(int i=4; i<=1000; i++)
    {
        dp[i]=(dp[i-2]+dp[i-2]+dp[i-1]) % 10007;
    }

    int n;
    scanf("%d", &n);
    printf("%d\n", dp[n]);
}


