#include <stdio.h>

int main()
{
    int dp[100001], max, n;

    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &dp[i]);
    }

    max=dp[0];

    for(int i=1; i<n; i++)
    {
        /*
        이전 숫자가 0보다 크고 이전 숫자와 현재 숫자를 더한것이 0보다 크면 연산함
        (이전 자리가 음수라면 계산하지 않고 새로 넣는 것이 훨씬 높으므로)
        (둘의 합이 음수라면 초기화 시키는게 훨씬 큼)
        */
        if(dp[i-1] > 0 && dp[i] + dp[i-1] > 0) dp[i] += dp[i-1]; // DP 점화식 => DP[i-1]+DP[i]

        if(max < dp[i])
        {
            max = dp[i];
        }
    }
    printf("%d", max);
}

// 참고 힌트 : https://mygumi.tistory.com/97
