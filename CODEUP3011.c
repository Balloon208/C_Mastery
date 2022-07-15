// 아이디어 : 버블 정렬이 실행된 숫자가 나오면 1 추가.

#include <stdio.h>

int bsa[1001];
int n, i, j, temp, t=0, sw=0;
int main()
{
    scanf("%d", &n);
    for (i=1; i<=n; i++)
    {
        scanf("%d", &bsa[i]);
    }

    for(i=1; i<n; i++) // 버블 정렬
    {
        for(j=1; j<n; j++)
        {
            if(bsa[j]>bsa[j+1]) // 숫자가 옮겨짐
            {
                sw=1;
                temp = bsa[j];
                bsa[j] = bsa[j+1];
                bsa[j+1] = temp;
            }
        }
        if(sw==1) t++; // 옮겨짐이 감지되면 해당 숫자는 옮겨졌으므로 1 추가
        sw=0;
    }

    printf("%d", t);
    return 0;
}
