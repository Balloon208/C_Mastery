#include <stdio.h>


void fibo(int n)
{
    int num1 = 0;
    int num2 = 1;

        for(int i=0; i<n; i++) // �̹� �ι��� ������ �������Ƿ� n-2�� �ݺ��Ѵ�.
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
