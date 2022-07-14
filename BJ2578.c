#include <stdio.h>

int a[5][5]={0, }, n=0, result=25;

void bingo()
{
    int c=0, p;
    int bingo=0;

    scanf("%d", &p); // 수 입력

    n++; // 숫자 입력했으니 수 추가.

    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            if(a[i][j]==p) a[i][j]=0; // 해당 번호 0(입력)으로 변환
        }
    }

    // 가로줄 검사

    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            if(a[i][j]!=0) c++;
        }
        if(c==0) bingo++;
        c=0;
    }

    // 세로줄 검사

    for(int j=0; j<5; j++)
    {
        for(int i=0; i<5; i++)
        {
            if(a[i][j]!=0) c++;
        }
        if(c==0) bingo++;
        c=0;
    }

    // 대각선 검사

    if(a[0][0]==0 && a[1][1]==0 && a[2][2]==0 && a[3][3]==0 && a[4][4]==0) bingo++;
    if(a[0][4]==0 && a[1][3]==0 && a[2][2]==0 && a[3][1]==0 && a[4][0]==0) bingo++;

    if(bingo>=3 && n < result) result = n; // 3줄 이상(동시에 빙고되서 4줄도 될수 있음)이면 해당값 저장 후 다시는 입력 안되게 함. (입력되면 result < n 이므로)

    return;

}

int main()
{
    int p;
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            scanf("%d", &a[i][j]); // 초기 판 입력
        }
    }

    for(int i=0; i<25; i++)
    {
        bingo(); // 빙고 실행!
    }

    printf("%d", result);
}

