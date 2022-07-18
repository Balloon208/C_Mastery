#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int pluscompare(const void *a, const void *b) // 오름차순 정렬
{
    if(*(int*)a > *(int*)b) return 1;
    else if(*(int*)a < *(int*)b) return -1;
    else return 0;
}

int minuscompare(const void *a, const void *b) // 내림차순 정렬
{
    if(*(int*)a < *(int*)b) return 1;
    else if(*(int*)a > *(int*)b) return -1;
    else return 0;
}


int main()
{
    int minus[100001]={0, }, plus[100001]={0, };
    int m=0, p=0, num, n, min=2000000000, result1, result2;

    scanf("%d", &n);

    for(int i=0; i<n; i++)
    {
        scanf("%d", &num);
        if(num>=0)
        {
            plus[p]=num; // 양수는 양수배열에
            p++;
        }
        else
        {
            minus[m]=num; // 음수는 음수배열에
            m++;
        }
    }

    qsort(plus, p, sizeof(int), pluscompare); // 오름차순 정렬 (1, 2, 3, 4, 5)
    qsort(minus, m, sizeof(int), minuscompare); // 내림차순 정럴(-1, -2, -3, -4, -5)


    // 음수끼리 섞었을때 최소
    if(m>=2)
    {
        min = abs(minus[0]+minus[1]);
        result2 = minus[0];
        result1 = minus[1];
    }

    // 양수(0포함) 끼리 섞었을때 최소
    if(p>=2 && min > plus[0] + plus[1])
    {
        min = plus[0] + plus[1];
        result1=plus[0];
        result2=plus[1];
    }

    int mix;

    // 양수, 음수를 섞었을때 최소

    for(int i=0, j=0; i<p && j<m;)
    {
        mix=plus[i]+minus[j]; // 둘을 섞은 특성값을 구해서
        if(abs(mix)<min) // 그 특성값이 최소보다 작다면
        {
            result1=minus[j]; // 음수
            result2=plus[i]; // 양수
            min=abs(mix); // 특성값 대입
        }

        if(mix<0) i++; // 음수면 다음 양수 배열을 들고옴
        else j++; // 양수면 다음 음수 배열을 들고옴
    }

    printf("%d %d", result1, result2);
}

