// 다음은 이 글을 보고 도움을 얻어 풀었다. https://norux.me/10

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) // qsort 에서 쓸 정렬 함수
{
    if(*(int*)a > *(int*)b) return 1;
    else if(*(int*)a < *(int*)b) return -1;
    else return 0;
}

int main()
{
    int arr[1000001]={0, }, n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), compare); // qsort 정렬

    for(int i=0; i<n; i++)
    {
        printf("%d\n", arr[i]);
    }
}
