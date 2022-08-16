#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[501][501];
int dp[501][501];

int dx[4]={1, 0, -1, 0};
int dy[4]={0, 1, 0, -1};

int dfs(int y, int x)
{
   if(dp[y][x]) return dp[y][x]; // 이미 계산한 결과가 있다면 결과는 같으므로 해당 값을 반환한다.

   // 아닐 경우

   dp[y][x]=1;

   for(int i=0; i<4; i++)
   {
        int ny=y+dy[i];
        int nx=x+dx[i];

        if(ny<0 || ny>=n || nx<0 || nx>=n) continue; // 범위값을 벗어났을 때
        if(arr[ny][nx]<=arr[y][x]) continue; // 숫자가 작을 때

        dp[y][x] = max(dp[y][x], dfs(ny, nx)+1); // 해당 방문의 dp가 다음 방문보다 크다면 가장 큰 깊이가 아니므로 유지함.
   }

   return dp[y][x];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int result=0;

	cin >> n;

	for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            result=max(result, dfs(i, j));
        }
    }

    cout << result;
}
