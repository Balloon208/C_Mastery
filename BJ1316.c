#include <stdio.h>

int main()
{
    int n, count = 0, group;
    char a[101];
    int alphabet[26]={0, };
    scanf("%d", &n);

    for(int i=0; i<n; i++)
    {
        group = 1;
        scanf("%s", a);
        for(int j=0; a[j]!='\0'; j++)
        {
            if(alphabet[a[j]-'a'] == 1) // 이미 입력되었다면 group=0 으로 break
            {
                group=0;
                break;
            }
            else
            {
                while(a[j]==a[j+1]) // 연속되는 문자의 끝까지 가르키는 배열 위치 이동
                {
                    j++;
                }
                alphabet[a[j]-'a'] = 1; // 그 문자가 입력되었다 표시
            }
        }
        if(group==1) count++; // break 문을 타지 않았다면 해당 문자열은 조건 만족

        // 배열 초기화
        
        for(int j=0; j<100; j++) a[j]='\0';
        for(int j=0; j<26; j++) alphabet[j]=0;
    }
    printf("%d", count);
}
