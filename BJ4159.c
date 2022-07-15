/*

오답 코드

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    if(*(int*)a > *(int*)b) return 1;
    else if(*(int*)a < *(int*)b) return -1;
    else return 0;
}

void road(int n)
{
    int arr[1500]={0, };
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), compare);

    for(int i=1; i<=n; i++)
    {
        if(arr[i-1]+200<arr[i] || arr[0]!=0 || arr[n-1]<1222)
        {
            printf("IMPOSSIBLE\n");
            return;
        }
    }
    printf("POSSIBLE\n");
    return;

}

int main()
{
    int n;

    while(1)
    {
        scanf("%d", &n);
        if(n==0) return 0;
        else road(n);
    }
}

틀린 이유 : 왕복의 경우를 생각하지 못함 (여행을 완료하려면 오는것까지 되어야하므로,
            마지막 주유소와 도착지점 사이의 거리가 200이하가 아닌 100이하가 되어야한다.

*/

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    if(*(int*)a > *(int*)b) return 1;
    else if(*(int*)a < *(int*)b) return -1;
    else return 0;
}

void road(int n)
{
    int arr[1500]={0, };
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), compare); // 주유소 위치를 오름차순으로 정리

    for(int i=1; i<=n; i++)
    {
        if(arr[i-1]+200<arr[i] || arr[n-1]<1322) // 이전 주유소와 현재 주유소와의 거리가 200보다 크거나, 도착지점과 마지막 주유소 거리가 100 이상일때 ('왕복'이므로)
        {
            printf("IMPOSSIBLE\n");
            return;
        }
    }
    printf("POSSIBLE\n");
    return;

}

int main()
{
    int n;

    while(1)
    {
        scanf("%d", &n);
        if(n==0) return 0;
        else road(n);
    }
}