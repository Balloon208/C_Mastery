#include <stdio.h>

int main()
{
	int arr[101][101]={0, }, m,n,x,y, max=0, ka=0;

    scanf("%d %d %d %d", &m, &n, &x, &y);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    for(int i=0; i<=n-y; i++)
    {
        for(int j=0; j<=m-x; j++)
        {
            for(int k=0; k<y; k++)
            {
                for(int l=0; l<x; l++)
                {
                    ka+=arr[k+i][l+j];
                }
            }
            if(ka>max) max=ka;
            ka=0;
        }
    }

    printf("%d", max);


}
