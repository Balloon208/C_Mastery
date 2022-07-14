
// y입력은 대체 왜 준거야 쓰지도 않는데...

#include <stdio.h>

void candy()
{
	char a[401][401]={0, };
	int x, y, c=0;

	scanf("%d %d", &x,&y);
	for(int i=0; i<x; i++)
    {
        scanf("%s", &a[i]);
    }
    for(int i=0; i<x; i++)
    {
        for(int j=0; j<y; j++)
        {
            if(a[i][j]=='o' && ((a[i][j-1]=='>' && a[i][j+1]=='<') || (a[i-1][j]=='v' && a[i+1][j]=='^'))) c++;
        }
    }
    printf("%d\n", c);
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        candy();
    }
}

