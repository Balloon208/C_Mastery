/*

1 발견 -> 0으로 바꿈 => 해당 좌표 기준 상하좌우로 있는지 확인 -> 발견시 이동후 재확인 -> 없을 때까지, 없으면 다음 구간 확인

*/

int arr[51][51]={}; // 배추밭

#include <stdio.h>

void findbachew(int a, int b)
{
    arr[a][b]=0; // 해당자리 0으로
    
    // 주변에 있으면 좌표 이동
    if(arr[a][b+1]==1) findbachew(a, b+1); 
    if(arr[a][b-1]==1) findbachew(a, b-1); 
    if(arr[a+1][b]==1) findbachew(a+1, b);
    if(arr[a-1][b]==1) findbachew(a-1, b);
    return; // 주변에 있는 구역 전부 검색 완료시 리턴.
}

int main()
{
    int t, n, m, k, x, y, c;
    scanf("%d", &t);
    for(int i=0; i<t; i++)
    {
        c=0;
        scanf("%d %d %d", &m, &n, &k); // 가로, 세로, 배추 개수 받기
        for(int j=0; j<k; j++)
        {
            scanf("%d %d", &x, &y); // 배추 위치 입력
            arr[x][y]=1;
        }

        // 모든 배열을 검사한다.
        
        for(int j=0; j<m; j++)
        {
            for(int l=0; l<n; l++)
            {
                if(arr[j][l]==1)
                {
                    findbachew(j, l); // 배추가 있다면 주변에 있는 모든 배추를 없앤다. (한 구역을 전부 없앤다.)
                    
                    c++; // 배추흰지렁이 수 증가.
                }
            }
        }
        printf("%d\n", c);
    }
}