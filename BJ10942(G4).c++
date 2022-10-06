// a(팰린드롬)b 에서 a==b 이면 a~b는 팰린드롬 으로 실행 하기전에 미리 처리한다.

#include <iostream>
#include <vector>

using namespace std;

vector<int>v;
int dp[2001][2001]={};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    
    v.push_back(0); // 백터에 초기값 넣기..? (이해 완료 X)
    for(int i=0; i<n; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }
    
    // 길이가 1일때
    for(int i=1; i<=n; i++)
    {
        dp[i][i]=1;
    }
    // 길이가 2일때
    for(int i=1; i<n; i++)
    {
        if(v[i]==v[i+1]) dp[i][i+1] = 1;
    }
    // 길이가 3이상일때
    for(int i=2; i<n; i++) // 길이 = i+1
    {
        for(int j=1; j<=n-i; j++) // 왼쪽
        {
            // 양옆이 같고, 그 전까지가 팰린드롬 이라면 이 역시 팰린드롬.
            if(v[j]==v[i+j] && dp[j+1][i+j-1]==1) dp[j][i+j]=1;
        }
    }
    
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int f, l;
        cin >> f >> l;
        cout << dp[f][l] << '\n';
    }
}