#include <stdio.h>
#include <string.h>

int main()
{
    char a[6];
    int length, c;
    while(1)
    {
        c=0;
        scanf("%s", a);
        length=strlen(a);
        if(length == 1 && a[0]=='0') return 0;
        for(int i=0; i<length/2; i++) // 홀수자리면 중간의 숫자는 무시해도 됨
        {
            if(a[i]!=a[length-1-i]) c++; // ex) 1,5 2,4 or 1,4 2,3 비교했을때 다르면 c추가.
        }
        if(c==0) printf("yes\n"); // 다르지 않으면 yes
        else printf("no\n");
    }
}
