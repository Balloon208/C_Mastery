#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

char name[500000][20]={};
char answer[500000][20]={};

int cnt=0;

void binsearch(int n, char key[])
{
    int high=n, low=0;
    int mid;

    while(low<=high)
    {
        mid = (high+low)/2;
        if(strcmp(name[mid], key)==0){strcpy(answer[cnt], key); cnt++; return;}
        else if(strcmp(name[mid], key)>0) high=mid-1;
        else if(strcmp(name[mid], key)<0) low=mid+1;
    }
    return;
}

int compare(const void *a, const void *b)
{
    return strcmp((char *)a, (char *)b);
}

int main()
{
	char findname[20];

    int n, m;
    scanf("%d %d", &n, &m);

    for(int i=0; i<n; i++)
    {
        scanf("%s", name[i]); // 이름 받기
    }

    qsort(name, n, sizeof(name[0]), compare); // 이분탐색을 위한 정렬

    for(int i=0; i<m; i++)
    {
        scanf("%s", findname); // 찾을 이름을 입력 받음
        binsearch(n, findname); // 이분탐색으로 찾는다.
    }

    qsort(answer, cnt, sizeof(answer[0]), compare); // 답을 정렬한다.
    
    printf("%d\n", cnt);
    for(int i=0; i<cnt; i++)
    {
        printf("%s\n", answer[i]);
    }
}
