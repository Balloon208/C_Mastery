#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int max(int n1, int n2)
{
    return n1>n2?n1:n2;
}

int n, limit;
int Weight[100], Value[100];
int dp[101][100001]; // 일반적인 방법으로는 시간 초과가 나버리므로 메모이제이션을 해줌.

int solution(int i, int w)
{
    if(dp[i][w]>0) return dp[i][w];
    if(i==n) return 0;


    int n1=0, n2=0;

    if(w+Weight[i]<=limit) n1=Value[i]+solution(i+1, w+Weight[i]); // 포함됨 (가치 증가, 다음 물건으로 재귀)
    n2=solution(i+1, w); // 미포함됨 (다음 물건으로 넘어감)

    return dp[i][w] = max(n1, n2);
}

int main()
{

    scanf("%d %d", &n, &limit);

    for(int i=0; i<n; i++)
    {
        scanf("%d %d", &Weight[i], &Value[i]);
    }
    printf("%d", solution(0, 0));
}