/*
    DP 점화식 : 현재 계단의 점수 + 최대값(DP-2의 값, DP-3의 값 + 계단 -1의 점수)
    -> score[i] + MAX(dp[i-2] (건너 뛸 때의 경우) , dp[1-3] + score[i-1](연속해서 밟을 때의 경우))
*/

#include <stdio.h>
#include <stdlib.h>

int score[301]={0, };
int dp[301]={0, };

#define MAX(a,b) a>b?a:b

int main()
{
    int a;
    scanf("%d", &a);
    for(int i=1; i<=a; i++)
    {
        scanf("%d", &score[i]);
    }

    //초기값 지정

    dp[0]=0;
    dp[1]=score[1];
    dp[2]=score[1]+score[2];

    for(int i=3; i<=a; i++)
    {
        dp[i] = score[i] + (MAX(dp[i-2], dp[i-3] + score[i-1]));
    }
    printf("%d", dp[a]);
}
