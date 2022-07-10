// 제한 메모리가 작으므로 숫자를 입력받아 추가하는 방식을 선택함.

#include <stdio.h>

int main()
{
    int arr[10001]={}, n, a;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &a);
        arr[a] += 1; // 해당 숫자가 입력된 횟수가 추가된다.
    }

    for(int i=1; i<=10000; i++) // 내림차순으로 해당 숫자가 입력된 만큼 출력
    {
        while(arr[i]!=0)
        {
            printf("%d\n", i);
            arr[i]--;
        }
    }
}
