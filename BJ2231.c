#include <stdio.h>
#include <string.h>

int main()
{
    int a;
    scanf("%d", &a);
    for(int i=1; i<a; i++) // 1부터 a미만 까지 분해합이 있는지 찾는다!
    {
        // 분해합 = 본인 + 자릿수의 합

        int solon = i; // 자릿수 더하기
        int num = i; // 본인.

        while(solon>0)
        {
            num+=solon%10;
            solon/=10;
        }
        if(num==a)
        {
            printf("%d", i);
            return 0;
        }
    }
    printf("0");
}
