#include <stdio.h>
#include <math.h>

int bin_search(int arr[], int n, int key)
{
    int high, low, mid;
    low=0;
    high=n-1;

    while(low<=high)
    {
        mid=(low+high)/2;
        if(key==arr[mid]) return mid+1; // 0번 배열부터 검사하므로 1을 더해줌
        else if(key<arr[mid]) high=mid-1;
        else if(key>arr[mid]) low=mid+1;
    }
    return -1;
}

int main()
{
   int arr[1000000];
   int n,q, number;

   scanf("%d", &n);
   for(int i=0; i<n; i++)
   {
       scanf("%d", &arr[i]);
   }
   scanf("%d", &q);
   for(int i=0; i<q; i++)
   {
       scanf("%d", &number);
       printf("%d ", bin_search(arr, n, number));
   }
}

