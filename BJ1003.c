#include <stdio.h>

long long int zero=0, one=0;
long long int dzero[41]={0, }, done[41]={0, };

void fibonacci(int i)
{
    dzero[i] = dzero[i-2]+dzero[i-1];
    done[i] = done[i-2]+done[i-1];
}

int main()
{
    int t, n;

    dzero[0]=1;
    done[0]=0;
    dzero[1]=0;
    done[1]=1;
    for(int i=2; i<=40; i++)
    {
        fibonacci(i);
    }

    scanf("%d", &t);

    for(int i=0; i<t; i++)
    {
        scanf("%d", &n);
        printf("%lld %lld\n", dzero[n], done[n]);
    }
}

