#include <stdio.h>

int main()
{
    int x, y, w, h, min=10000;
    scanf("%d %d %d %d", &x, &y, &w, &h);

    if(x<(double)w/2) // 왼쪽 까지의 거리 < 오른쪽까지의 거리
    {
        if(min>x) min=x;
    }
    else // 왼쪽 까지의 거리 > 오른쪽까지의 거리
    {
        if(min>w-x) min=w-x;
    }
    if(y<(double)h/2) // 위쪽 까지의 거리 > 아래쪽까지의 거리
    {
        if(min>y) min=y;
    }
    else // 위쪽 까지의 거리 < 아래쪽까지의 거리
    {
        if(min>h-y) min=h-y;
    }
    printf("%d", min);
}
