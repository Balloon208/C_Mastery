// 힌트 : https://www.youtube.com/watch?v=0bqfTzpWySY

#include <stdio.h>

struct user
{
    char name[11];
    int score[4];
    int rank[4];
};

int main()
{
	int n, m;

	struct user arr[100]={0, };

	scanf("%d", &n);

	for(int i=0; i<n; i++)
    {
        scanf("%s %d %d %d", &arr[i].name, &arr[i].score[1], &arr[i].score[2], &arr[i].score[3]);
    }

    for(int k=1; k<=3; k++)
    {
        for(int i=0; i<n; i++)
        {
            arr[i].rank[k]=1;
            for(int j=0; j<n; j++)
            {
                if(arr[i].score[k] < arr[j].score[k]) arr[i].rank[k]++;
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        if(arr[i].rank[1]==1) printf("%s %d %d", arr[i].name, arr[i].rank[2], arr[i].rank[3]);
    }

}
