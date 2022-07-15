/*
    배열 입력을 하나 복사 -> 정렬 후 rank[해당 숫자]에 등수 부여 (1부터 부여)
    -> rank[복사한 배열의 값] 이 1 이상이라면(입력 되었다면) 1 줄이고 출력
*/

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) // qsort 정렬
{
    if(*(int*)a > *(int*)b) return 1;
    if(*(int*)a < *(int*)b) return -1;
    else return 0;
}

int main()
{
    int arr[50001]={0, }, comparearr[50001]={0, }, rank[500001]={0, }, n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
        comparearr[i]=arr[i]; // 복사한 배열 (비교에 사용)
    }

    qsort(arr, n, sizeof(int), compare); // arr배열 정렬

    int k=0;
    int ranking=1;
    
    for(int i=1; i<=500000; i++) // 숫자 검사
    {
        if(arr[k]==i) {rank[i]=ranking; k++; ranking++;} // 배열 0번부터 해당 숫자가 기록됨을 감지하면, 그 숫자를 등수에 넣음 
    }

    // rank[복사한 배열의 숫자]가 입력되었다면(1 이상이라면) 입력된 rank를 출력(-1 해서)
    for(int i=0; i<n; i++)
    {
        if(rank[comparearr[i]]>=1) printf("%d ", rank[comparearr[i]] - 1);
    }

}


