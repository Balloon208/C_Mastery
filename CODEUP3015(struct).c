#include <stdio.h>

struct user
{
    char name[11];
    int score;
    int rank;
};

int main()
{
	int n, m;

	struct user arr[100]={0, }; // 구조체 배열

	scanf("%d %d", &n, &m);

	for(int i=0; i<n; i++)
    {
        scanf("%s %d", &arr[i].name, &arr[i].score);
    }


    for(int i=0; i<n; i++)
    {
        arr[i].rank=1;
        for(int j=0; j<n; j++)
        {
            if(arr[i].score < arr[j].score) arr[i].rank++; // 작을 경우에 등수 올림
            else if(arr[i].score == arr[j].score && i > j) arr[i].rank++; // 만약 같을경우, 바꿀 수 배열 > 비교할 수 배열 (뒤에 입력되는)이면 등수 올림
        }
    }

    for(int i=1; i<=m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(arr[j].rank==i) printf("%s\n", arr[j].name);
        }
    }

}
