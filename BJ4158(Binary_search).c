/*
    이분탐색으로 풀이 (오름차순으로 주어졌고, 빠르게 비교해야 하므로)
*/

#include <stdio.h>
#include <stdlib.h>

int Binarysearch(int key, int barr[], int b)
{
    int low, high, mid;

    low=0;
    high = b-1;

    while(low<=high)
    {
        mid = (low+high)/2;
        if(key==barr[mid])
        {
            return 1;
        }
        else if(key<barr[mid])
        {
            high = mid-1;
        }
        else if(key>barr[mid])
        {
            low = mid+1;
        }
    }
    return 0;
}

void CDCompare(int a, int b)
{
    int aarr[1000001], barr[1000001], c=0, key;

    for(int i=0; i<a; i++)
    {
        scanf("%d", &aarr[i]);
    }
    for(int i=0; i<b; i++)
    {
        scanf("%d", &barr[i]);
    }
    for(int i=0; i<a; i++)
    {
        key=aarr[i];
        if(Binarysearch(key, barr, b)) c++;
    }
    printf("%d\n", c);

}

int main()
{
    int a, b;
    while(1)
    {
        scanf("%d %d", &a, &b);
        if(a==0 && b==0) return 0;
        else CDCompare(a, b);
    }
}