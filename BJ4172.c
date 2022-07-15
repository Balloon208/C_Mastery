#include <stdio.h>
#include <math.h>

// 이 또한 재귀로 돌린다면 시간복잡도가 끔찍하므로 DP를 이용해 푼다.

int arr[1000001]={0, };

int main()
{
    int n;
    
    arr[0]=1;
    
    for(int i=1; i<=1000000; i++)
    {
        int sqrtNum = i - sqrt(i); // sqrt(i)
        int logNum = (int)log(i); // log(i)
        int sinNum = (int)(i * sin(i) * sin(i)); // i*{sin^2(i)}
        
        arr[i] = (arr[sqrtNum] + arr[logNum] + arr[sinNum]) % 1000000;
    }
    while(1)
    {
        scanf("%d", &n);
        
        if(n==-1) return 0;
        
        printf("%d\n", arr[n]);
    }
}

