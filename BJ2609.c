#include <stdio.h>

int main()
{
    int a, b, result;
    scanf("%d %d", &a, &b);
    for(int i=1; i<=10000; i++) // 가장 크게 나눠지는 최대공약수
    {
        if(a%i==0 && b%i==0) result=i;
    }
    printf("%d\n", result);
    printf("%d", result * (a/result * b/result)); // 최소공배수 = 최대공약수 * 최대공약수로 나눈 A * 최대공약수로 나눈 B
}
