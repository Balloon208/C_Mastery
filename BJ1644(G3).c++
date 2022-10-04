#include <iostream>
#include <math.h>
#define MAX 4000000

using namespace std;

bool prime[MAX+1];
int arr[1000001];
int cnt=0; // 소수의 개수

int solve() // 연속되는 숫자이므로 작으면 오른쪽 포인터를 움직이고, 크거나 같으면 왼쪽 포인터를 움직인다.
{
    int n, result=0;
    cin >> n;
    int lp=0, rp=1;
    int sum=arr[lp];

    while(1)
    {
        if(rp>cnt) return result; // 소수의 개수를 초과하면 종료한다.

        if(sum<n)
        {
            sum+=arr[rp]; // 누적합을 해주고
            rp++; // 포인터를 이동해준다.
        }
        else
        {
            if(sum==n) result++; // 만약 같은 경우에는 만들수 있는 경우가 하나 생기는 것이다.
            sum-=arr[lp]; // 뒤에 있는 숫자를 빼주고
            lp++; // 포인터를 옮겨준다
        }
    }
}

int main()
{
    // 에라토스테네스의 체를 만드는 과정
    
    for(int i=2; i<=2000; i++) // 2,000*2,000 = 4,000,000
    {
        if(prime[i]==true) continue;

        for(int j=2; i*j<=MAX+1; j++)
        {
            prime[i*j]=true;
        }
    }

    for(int i=2; i<=MAX; i++)
    {
        if(!prime[i])
        {
            arr[cnt]=i;
            cnt++;
        }
    }

    /*for(int i=0; i<cnt; i++)
    {
        cout << arr[i] << " ";
    }*/

    cout << solve();
}
