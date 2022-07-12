/*
    DP 점화식 : DP = DP-1의 길이 + DP-5의 길이
    
    (주의 : 100의 경우에닌 int 범위를 훌쩍 넘겨버린다.
*/

#include <stdio.h>
#include <stdlib.h>

long long int dp[101]={0, };

int main()
{
    //초기값 지정

    dp[0]=0;
    dp[1]=1;
    dp[2]=1;
    dp[3]=1;
    dp[4]=2;
    dp[5]=2;

    for(int i=6; i<=100; i++)
    {
        dp[i] = dp[i-1] + dp[i-5];
    }

    int t, a;
    scanf("%d", &t);
    for(int i=0; i<t; i++)
    {
        scanf("%d", &a);
        printf("%lld\n", dp[a]);
    }
}
