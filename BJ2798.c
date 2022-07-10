#include <stdio.h>

int main()
{
    int arr[101]={}, n, m, max=0, sum;
    scanf("%d %d", &n, &m);
    
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    // 모든 경유의 수 찾기 
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            for(int k=j+1; k<n; k++)
            {
                sum = arr[i] + arr[j] + arr[k]; // 세 수의 합
                if(sum>max && sum<=m) max=sum;
            }
        }
    }
    printf("%d\n", max);
    return 0;
}
