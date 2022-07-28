#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>

using namespace std;

int N, a;
char s[100];
stack<int> stac;

int main()
{
    scanf("%d", &N);

    for(int i=0; i<N; i++)
    {
        scanf("%s", s);
        if(strcmp(s,"push(")==0)
        {
            scanf("%d ", &a);
            scanf(")");
            stac.push(a);
        }
        else if(strcmp(s,"top()")==0)
        {
            if(!stac.empty()) printf("%d\n", stac.top());
            else printf("-1\n");
        }
        else if(strcmp(s,"pop()")==0)
        {
            if(!stac.empty())
            {
                stac.pop();
            }
        }
        else if(strcmp(s,"size()")==0)
        {
            printf("%d\n", stac.size());
        }
        else if(strcmp(s,"empty()")==0)
        {
            if(stac.empty()) printf("true\n");
            else printf("false\n");
        }
    }

    return 0;
}