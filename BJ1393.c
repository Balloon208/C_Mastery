/*

오답 노트

- 잘못된 코드 -
#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, x, y, xs, ys, rx, ry, i, j;
    int min = 1000000;

    scanf("%d %d", &a, &b);
    scanf("%d %d %d %d", &x, &y, &xs, &ys);

    int maxnum;

    for(i=1; i<=xs; i++)
    {
        if(xs%i == 0 && ys%i == 0) maxnum=i;
    }


    xs/=maxnum;
    ys/=maxnum;

    int c=0;

    for(i=x, j=y; c<200; i+=xs, j+=ys, c++)
    {
        if(pow(abs(i-a), 2) + pow(abs(j-b), 2) < min)
        {
            min= pow(abs(i-a), 2) + pow(abs(j-b), 2);
            rx=i; ry=j;
        }
    }

    printf("%d %d", rx, ry);

}

- 틀린 이유 : 기울기가 0일 때를 생각 못하여 오답이 났다. 연산 횟수도 조금 모자르다.

*/

#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, x, y, xs, ys, rx, ry, i, j;
    int min = 1000000;

    scanf("%d %d", &a, &b);
    scanf("%d %d %d %d", &x, &y, &xs, &ys);

    int maxnum=0;

    for(i=1; i<=xs; i++)
    {
        if(xs%i == 0 && ys%i == 0) maxnum=i; // y= ax+b 의 a 구하기 (단, a는 정수)
    }

    // 만약 0이라면 적어도 하나는 기울기가 없음

    xs/= maxnum>0? maxnum : 1; // x 증가량 (0일 경우엔 xs 그대로)
    ys/= maxnum>0? maxnum : 1; // y 증가량 (0일 경우엔 ys 그대로)



    int c=0;

    // -100 -100 -> 100 100 까지, 즉 최소 약 201번의 연산을 해야함 -> 무난하게 300회

    for(i=x, j=y; c<=300; i+=xs, j+=ys, c++)
    {
        if(pow(abs(i-a), 2) + pow(abs(j-b), 2) < min) // 거리가 최소거리보다 적으면
        {
            min= pow(abs(i-a), 2) + pow(abs(j-b), 2); // 최소를 해당 거리로 재설정하고
            rx=i; ry=j; // 해당 좌표를 기억한다.
        }
    }

    printf("%d %d", rx, ry);

}
