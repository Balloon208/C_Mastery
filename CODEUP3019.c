#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct scadule{
    char name[100];
    int year;
    int month;
    int day;
    int ranking;
};


int main()
{
    struct scadule s[100];

    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++)
    {
        s[i].ranking=1; // 모든 랭킹은 1로 초기화
        scanf("%s %d %d %d", s[i].name, &s[i].year, &s[i].month, &s[i].day);
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i==j) continue;

            if(!(s[i].year==s[j].year)) // year가 다르면
            {
                if(s[i].year>s[j].year) s[i].ranking++;
            }
            else
            {
                if(!(s[i].month==s[j].month)) // month가 다르면
                {
                    if(s[i].month>s[j].month) s[i].ranking++;
                }
                else
                {
                    if(!(s[i].day==s[j].day)) // day가 다르면
                    {
                        if(s[i].day>s[j].day) s[i].ranking++;
                    }
                    else // 문자열 비교
                    {
                        if(strcmp(s[i].name, s[j].name)>0) s[i].ranking++;
                    }
                }
            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(s[j].ranking==i) printf("%s\n", s[j].name); // 1등부터 n등까지 출력
        }
    }
}

