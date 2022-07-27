/*
    r=1 -> 1(1)
r=2 -> 1 1(2)
r=3 -> 1 1 1(3)
r=4 -> 1 2 1(3)
r=5 -> 1 2 1 1(4)
r=6 -> 1 2 2 1(4)
r=7 -> 1 2 2 1 1(5)
r=8 -> 1 2 2 2 1(5)
r=9 -> 1 2 3 2 1(5)
r=10 -> 1 2 3 2 1 1(6)
r=11 -> 1 2 3 2 2 1(6)
r=12 -> 1 2 3 3 2 1(6)
r=13 -> 1 2 3 3 2 1 1(7)
r=14 -> 1 2 3 3 2 2 1(7)
r=15 -> 1 2 3 3 3 2 1(7)
r=16 -> 1 2 3 4 3 2 1(7)
r=17 -> 1 2 3 4 3 2 1 1(8)
r=18 -> 1 2 3 4 3 2 2 1(8)
r=19 -> 1 2 3 4 3 3 2 1(8)
r=20 -> 1 2 3 4 4 3 2 1(8)
r=21 -> 1 2 3 4 4 3 2 1 1(9)
r=22 -> 1 2 3 4 4 3 2 2 1(9)
r=23 -> 1 2 3 4 4 3 3 2 1(9)
r=24 -> 1 2 3 4 4 4 3 2 1(9)
r=25 -> 1 2 3 4 5 4 3 2 1(9)
r=26 -> 1 2 3 4 5 4 3 2 1 1(10)
r=27 -> 1 2 3 4 5 4 3 2 2 1(10)
r=28 -> 1 2 3 4 5 4 3 3 2 1(10)
r=29 -> 1 2 3 4 5 4 4 3 2 1(10)
r=30 -> 1 2 3 4 5 5 4 3 2 1(10)


(n번)
2번
2번
3번
3번
4번
4번
.
.
.
*/

#include <stdio.h>
#include <stdlib.h>

void solution()
{
    long long start, finish, r, cnt=3, recall=2;
    scanf("%lld %lld", &start, &finish);
    r=finish-start;

    if(r<=2){printf("%lld\n", r); return;} // 2이하의 경우는 r번 이므로 r을 출력

    r-=2;

    while(1)
    {
        for(long long i=0; i<2; i++, cnt++) // 2번씩 반복
        {
            if(recall>=r){printf("%lld\n", cnt); return;} // 만약 n이 recall보다 작다면 해당 cnt를 출력 후 종료
            else r-=recall;
            
            /*for(int j=0; j<recall; j++)
            {
                if(r==1){printf("%d\n", cnt); return;}  오답 사유 : 시간 초과 -> 한번에 계산 하도록함.
                else r--;
            }*/
            
        }
        recall++; // 2번 반복이 끝나면 n이 1 추가된다.
    }


}

int main()
{
    long long t;
    scanf("%lld",&t);
    for(int i=0; i<t; i++)
    {
        solution();
    }
}
