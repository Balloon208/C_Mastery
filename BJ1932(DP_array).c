// 힌트 : https://www.youtube.com/watch?v=0bqfTzpWySY

#include <stdio.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
	int DP[501][501]={0, }; // 삼각형

	int h, mx;
	scanf("%d", &h); // 높이 입력

	// 일반 삼각형을 입력받음
	for(int i=1; i<=h; i++)
    {
        for(int j=1; j<=i; j++)
        {
            scanf("%d", &DP[i][j]);
        }
    }

    int mx=-99999999;

    // DP 삼각형 (합)
    for(int i=2; i<=h; i++)
    {
        for(int j=1; j<=i; j++)
        {
            if(j==0) DP[i][j]+=DP[i-1][j]; // 맨 왼쪽의 경우 자신의 위쪽을 더함
            else if(j==i) DP[i][j]+=DP[i-1][j-1]; // 맨 오른쪽의 경우 자신의 위쪽을 더함
            else DP[i][j]+=max(DP[i-1][j-1], DP[i-1][j]); // 중간의 경우 자신 아래와 자신의 왼쪽중 큰것을 더함.
        }
    }

    for(int i=1; i<=h; i++)
    {
        if(mx<DP[h][i]) mx=DP[h][i]; // 맨 아래쪽에서 최대를 구한다.
    }

    printf("%d", mx);
}
