/*

[100000][100000]의 배열은 구현 불가
-> 규칙을 찾아서 풀어야 함.

참고 데이터

1 2 3 4 5 (1의 배수)
2 4 6 8 10 (2의 배수)
3 6 9 12 15 (3의 배수)
4 8 12 16 20 (4의 배수)
5 10 15 20 25 (5의 배수)

힌트를 받은 사이트 : https://hyeo-noo.tistory.com/64#--%--%EC%BD%--%EB%--%-C%--%EC%--%A-%EB%AA%--

*/

#include <iostream>
#define min(a, b) (a < b ? a : b)

using namespace std;

long long N, K;

long long lownum(long long mid)
{
    long long cnt = 0;
    for(int i=1; i<=N; i++)
    {
        // i행은 i의 배수의 집합
        // 만약 mid/i 가 더 클 경우에는 행 증가, 아닐경우 열 증가.
        cnt += min(N, (long long)mid/i);
        if(i > mid) break;
    }
    return cnt;
}

void solution()
{
    long long low = 0;
    long long high = N*N;
    long long mid;
    long long result = 0;

    while(low <= high)
    {
        mid = (high+low)/2;
        if(lownum(mid) < K) low = mid + 1;
        else
        {
            result = mid;
            high = mid - 1;
        }
    }

    cout << result;
}

int main()
{
    cin >> N >> K;
    solution();
}