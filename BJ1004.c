/*

출발 or 도착점이 원 안에 있다 -> 무조건 진입/이탈을 해야한다.

(원의 중점과 출발 || 도착점 사이의 거리 < 반지름) -> 원 안에 있다.
(원의 중점과 출발 || 도착점 사이의 거리 > 반지름) -> 원 안에 없다.

단, 출발, 도착점 둘다 원안에 있을경우, 진입/이탈이 필요하지 않으므로 무시한다.

결론

-> 원의 중점과 출발점 '또는' 도착점의 거리 < 반지름 -> 진입/이탈 횟수 + 1
-> 예외 : 원의 중점과 출발점 '그리고' 도착점의 거리 < 반지름 -> 무시


*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    long long a;
    int k, n, sx, sy, fx, fy, px, py, pr, c;
    scanf("%d", &k);
    for(int i=0; i<k; i++)
    {
        c=0;
        scanf("%d %d %d %d", &sx, &sy, &fx, &fy); // 시작 지점, 도착 지점 설정
        scanf("%d", &n);
        for(int j=0; j<n; j++) // 식 : (x축과의 거리)^2 + (y축과의 거리)^2 = 반지름^2
        {
            scanf("%d %d %d", &px, &py, &pr); // 행성의 정보 입력
            if(pow(abs(px-sx), 2) + pow(abs(py-sy), 2) < pow(pr, 2) && pow(abs(px-fx), 2) + pow(abs(py-fy), 2) < pow(pr, 2)) continue; // 시작지점과 도착지점이 모두 안에 있는 경우
            else if(pow(abs(px-sx), 2) + pow(abs(py-sy), 2) < pow(pr, 2) || pow(abs(px-fx), 2) + pow(abs(py-fy), 2) < pow(pr, 2)) c++; // 시작지점과 도착지점 중 하나만 안에 있는 경우
        }
        printf("%d\n", c);
    }
}