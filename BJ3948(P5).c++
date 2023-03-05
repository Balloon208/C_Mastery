/*
    참고 문헌 : https://nicotina04.tistory.com/75 (지그제그 순열)
    경우의 수를 Z(n) 이라 하자,
    Z(n) = 2*E(n, n) 이다.
    E(n, k) = E(n, k-1), E(n-1, n-k);
*/

#include <iostream>

using namespace std;

long long int dp[21][21]={};

long long zigzag(int n, int k)
{
    if(n==0 && k==0) return 1;
    if(k==0) return 0;

    if(dp[n][k] > 0) return dp[n][k];
    else return dp[n][k] = zigzag(n,k-1) + zigzag(n-1, n-k);
}

void init()
{
    dp[0][0]=1;
}

int main()
{
    init();
    int n, k;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> k;
        if(k==1) cout << "1" << '\n';
        else cout << zigzag(k, k)*2 << '\n';
    }
}
