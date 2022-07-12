/*

해결 방법: 확인할 데이터가 많으므로 binary search(이분 탐색)을 이용한다.
또한, 오름차순으로 정렬할 숫자도 많으므로 정렬은 qsort를 이용한다.

*/

#include <stdio.h>
#include <stdlib.h>

int sorting(const void *a, const void *b)
{
    if(*(int*)a > *(int*)b) return 1;
    else if(*(int*)a < *(int*)b) return -1;
    else return 0;
}

int binsearch(int arr[], int n, int key)
{
    int low, high, mid;

    low = 0;
    high = n-1;

    while(low<=high)
    {
        mid = (low+high)/2;
        if(key==arr[mid])
        {
            return 1;
        }
        else if(key < arr[mid])
        {
            high = mid-1;
        }
        else if(key > arr[mid])
        {
            low = mid+1;
        }
    }
    return 0;
}

void findletter()
{
    int n, arr[1000001]={0, }, key;

    // 넣을 숫자 입력

    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // 이분 탐색을 위해 오름차순 정렬

    qsort(arr, n, sizeof(int), sorting);

    // 확인할 숫자 입력
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &key);
        printf("%d\n", binsearch(arr,n,key)); // 이분 탐색으로 탐사
    }
}


int main()
{
    int k;
    scanf("%d", &k);
    for(int i=0; i<k; i++) // Testcase
    {
        findletter();
    }

    return 0;
}

