/*
#include <stdio.h>

int main()
{
    int a, c=0, num=1;
    scanf("%d", &a);
    for(int i=a; i>=1; i--)
    {
        num*=i;
        while(num%10==0)
        {
            c++;
            num/=10;
        }
    }
    printf("%d", c);

}

해당 코드로 1~30을 입력해보니, 5의 배수면 +1, 25의 배수이면 +2을 했다. 이후 오답을 했으나
계산기를 통하여 125의 배수면 +3 하는 사실을 알고 이를 수정함.

결론 : n!의 0의 개수 -> n/5 + n/5^2 + a/5^3 + ...
*/



#include <stdio.h>

int main()
{
    int a, c=0;
    long long num=1;
    scanf("%d", &a);
    printf("%d", a/5 + a/25 + a/125);

}
