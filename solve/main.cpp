#include <stdio.h>


void fibo(int n)
{
    int num1 = 0;
    int num2 = 1;

        for(int i=0; i<n; i++) // 이미 두번의 과정을 거쳤으므로 n-2번 반복한다.
        {
            int sum = num1+num2;
            printf("%d ", sum);
            num1=num2;
            num2=sum;
        }


}
int main()
{
  int n;
  scanf("%d", &n);
  fibo(n);
}
