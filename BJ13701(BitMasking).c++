/*
    참고 : https://rebro.kr/63
    
    원소 추가 : A = A|(1<<k);
    원소 삭제 : A = A & ~(1 << k);
    원소 포함 여부 확인 : if(A & (1<<k));
    원소 토글 : A = A^=(1<<k);
    
    여기서 content = 1<<k 부분을 나타낸다.
*/

#include <cstdio>

int arr[(1<<25)/32]; // 8MB = 2^25, int = 32bit.

int main()
{
    int num;
    while(~scanf("%d", &num))
    {
        int where = num/32;
        int content = 1 << (num%32);
        if(!(arr[where] & content))
        {
            arr[where] |= content;
            printf("%d ", num);
        }
    }
    return 0;
}
