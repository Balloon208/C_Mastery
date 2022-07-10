#include <stdio.h>

int main()
{
    long long a;
    int n, x, y;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        a=1;
        scanf("%d %d", &x, &y);
        for(int j=0; j<x; j++) // nCr을 곱하면서 나누는 연산을 동시에 한다. (long long 범위를 넘어섬)
        {
            // nCr = n!/r!(n-r)! = 1 * (n!/(n-r)!) / r!

            a*=y-j; // n!/(n-r)! 을 곱함
            a/=1+j; // r! 을 나눔
        }
        printf("%lld\n", a);
    }
}
