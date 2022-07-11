#include <stdio.h>

int main()
{
    char a[51]={};
    char answer[51]={}; // 출력할 문자열
    int xline=0;
    
    scanf("%s", a);

    for(int i=0; a[i]!='\0'; i++)
    {
        if(a[i]=='X' && a[i+1]=='X' && a[i+2]=='X' && a[i+3]=='X'){answer[i] = 'A'; answer[i+1] = 'A'; answer[i+2] = 'A'; answer[i+3] = 'A'; i+=3;} // XXXX면 AAAA
        else if(a[i]=='X' && a[i+1]=='X'){answer[i] = 'B'; answer[i+1] = 'B'; i++;} // XX(비어있음) 이면 BB
        else if(a[i]=='.') answer[i]='.'; // . 이면 .
        else // 다른 경우는 -1 출력
        {
            printf("-1");
            return 0;
        }
    }

    for(int i=0; answer[i]!='\0'; i++)
    {
        printf("%c", answer[i]);
    }
}
