/*
1 발견 -> 0으로 바꿈 => 해당 좌표 기준 상하좌우로 있는지 확인 -> 발견시 이동후 재확인 -> 없을 때까지, 없으면 다음 구간 확인
*/

int sans(const void *a, const void *b)
{
    if(*(int*)a > *(int*)b) return 1;
    else if(*(int*)a < *(int*)b) return -1;
    else return 0;
}


int arr[26][26]={0, }; // 지도
int apartnum[500]={0, };
int c = 0;

#include <stdio.h>
#include <stdlib.h>


void findapart(int a, int b)
{
    arr[a][b]=0; // 해당자리 0으로

    // 주변에 있으면 좌표 이동
    if(arr[a][b+1]==1) {findapart(a, b+1); apartnum[c]++;}
    if(arr[a][b-1]==1) {findapart(a, b-1); apartnum[c]++;}
    if(arr[a+1][b]==1) {findapart(a+1, b); apartnum[c]++;}
    if(arr[a-1][b]==1) {findapart(a-1, b); apartnum[c]++;}
    return; // 주변에 있는 구역 전부 검색 완료시 리턴.
}

int main()
{
    int n=0;

    scanf("%d", &n);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%01d", &arr[i][j]);
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(arr[i][j]==1)
            {
                findapart(i, j); // 거눔ㄹ이 있다면 주변에 있는 모든 건물 없앤다. (한 구역을 전부 없앤다.)
                c++; // 단지수 증가
            }
        }
    }

    qsort(apartnum, c, sizeof(int), sans);

    printf("%d\n", c);
    for(int i=0; i<c; i++)
    {
        printf("%d\n", apartnum[i] + 1);
    }
}
