/*
note

16

27-6-6+1


27

42-10-6+1

dp[1][1]=0
dp[i][j]=dp[i-1][j]-dp[i][j-1]-dp[i-1][j-1]-arr[i][j];
결과값 = dp[x2][y2]-dp[x1-1][y2]-dp[x2][y1-1]+dp[x1-1][y1-1];
*/

#include <iostream>

using namespace std;

int arr[1025][1025]={0,};
int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin >> k;
            arr[i][j]=arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1]+k;
        }
    }

    /*
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
    */


    int x1, x2, y1, y2;
    for(int i=0; i<m; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        //cout << arr[x2][y2] << " " << arr[x1-1][y2] << " " << arr[x2][y1-1] << " " << arr[x1-1][y1-1] << " = ";
        cout << arr[x2][y2]-arr[x1-1][y2]-arr[x2][y1-1]+arr[x1-1][y1-1] << '\n';
    }
}
