//신발끈 공식 문제.

// https://namu.wiki/w/%EC%8B%A0%EB%B0%9C%EB%81%88%20%EA%B3%B5%EC%8B%9D

#include <stdio.h>

double jeoldae(double a)
{
    	if(a>=0) return a;
	    else return -a;
}

int main()
{
	    double arr[10005], brr[10005], s=0;
    	int i, n;
	    scanf("%lld", &n);
	    for(i=0;i<n;i++)
    	{
		        scanf("%lf %lf", &arr[i], &brr[i]);
    	}
	    arr[n]=arr[0], brr[n]=brr[0];
	    for(i=0;i<n;i++)
	    {
		        s+=arr[i]*brr[i+1];
		        s-=brr[i]*arr[i+1];
	    }
	    printf("%.1lf", jeoldae(s)/2);
}