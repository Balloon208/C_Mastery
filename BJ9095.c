/*
1 -> 1
2 -> 2
3 -> 4
4 -> 7
5 -> 13 
       1+1+1+1+1 1+1+1+2 1+1+2+1 1+2+1+1 2+1+1+1
       2+2+1 2+1+2 1+2+2 3+1+1 1+3+1 1+1+3 2+3 3+2.

*/

#include <stdio.h>

int main()
{
    int dp[11]={0, };

    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    dp[3]=4;

    for(int i=4; i<=10; i++)
    {
        dp[i]=dp[i-3]+dp[i-2]+dp[i-1];
    }

    int t, n;

    scanf("%d", &t);
    for(int i=0; i<t; i++)
    {
        scanf("%d", &n);
        printf("%d\n", dp[n]);
    }
}


