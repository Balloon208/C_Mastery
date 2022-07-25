#include <stdio.h>
#include <string.h>

int q[100000]={0, }, s[100000]={0, };

int quit = 0;

int qaddlocate=0, qremovelocate=0, slocate=0;

void command()
{
    int n;

    char str[20]={0, };

    scanf("%s", str);

    // 선형 queue

    if(strcmp(str, "qpush")==0)
    {
        if(qaddlocate>=100000) printf("queue가 가득 찼습니다.\n\n");
        else
        {
            scanf("%d", &n);
            printf("queue에 %d을(를) 추가 했습니다.\n\n", n);
            q[qaddlocate]=n;
            qaddlocate++;
        }
    }
    else if(strcmp(str, "qpop")==0)
    {
        if(qaddlocate<=qremovelocate)
        {
            printf("queue가 비어있습니다.\n\n");
        }
        else
        {
            printf("queue의 front인 %d을(를) 삭제 했습니다\n\n", q[qremovelocate]);
            q[qremovelocate]=0;
            qremovelocate++;
        }
    }
    else if(strcmp(str, "qfront")==0)
    {
        if(qaddlocate<=qremovelocate)
        {
            printf("queue가 비어있습니다.\n\n");
        }
        else
        {
            printf("queue의 front : %d\n\n", q[qremovelocate]);
        }
    }
    else if(strcmp(str, "qback")==0)
    {
        if(qaddlocate<=qremovelocate)
        {
            printf("queue가 비어있습니다.\n\n");
        }
        else
        {
            printf("queue의 back : %d\n\n", q[qaddlocate-1]);
        }
    }
    else if(strcmp(str, "qsize")==0) printf("queue의 size : %d\n\n", qaddlocate-qremovelocate);
    else if(strcmp(str, "qempty")==0) printf("queue의 empty : %d\n\n", qaddlocate==qremovelocate);

    // stack

    else if(strcmp(str, "spush")==0)
    {
        if(slocate>=100000) printf("stack이 가득 찼습니다.\n\n");
        else
        {
            scanf("%d", &n);
            printf("stack에 %d을(를) 추가 했습니다.\n\n", n);
            s[slocate]=n;
            slocate++;
        }
    }
    else if(strcmp(str, "spop")==0)
    {
        if(slocate==0)
        {
            printf("stack이 비어있습니다.\n\n");
        }
        else
        {
            printf("stack의 front인 %d을(를) 삭제 했습니다\n\n", s[slocate-1]);
            s[slocate-1]=0;
            slocate--;
        }
    }
    else if(strcmp(str, "stop")==0)
    {
        if(slocate==0)
        {
            printf("stack이 비어있습니다.\n\n");
        }
        else
        {
            printf("stack의 top : %d\n\n", s[slocate-1]);
        }
    }
    else if(strcmp(str, "ssize")==0) printf("stack의 size : %d\n\n", slocate);
    else if(strcmp(str, "sempty")==0) printf("stack의 empty : %d\n\n", slocate==0);

    // quit

    else if(strcmp(str, "quit")==0) quit=1;

    // unknown command

    else
    {
        printf("알수 없는 명령어입니다.\n\n");
    }
}

int main()
{
    while(quit==0)
    {
        printf("명령어를 입력하세요 : ");
        command();
    }
}
