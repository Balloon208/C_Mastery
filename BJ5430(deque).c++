#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <deque>

using namespace std;

void solution()
{
    deque<int> dq;
    int n, number, R=0;
    char command[100001]={};

    scanf("\n%s", command);
    scanf("\n%d", &n);

    if(n==0) scanf("\n[]"); // 0 이면 이 형태
    else if(n==1) // 1 이면 이 형태
    {
        scanf("\n[%d]", &number);
        dq.push_back(number); // 뒤로 내보냄으로써 입력된 순서대로 넣어짐
    }
    else // 2 이상이면 이 형태
    {
        scanf("\n[%d", &number);
        dq.push_back(number);
        for(int i=1; i<n-1; i++)
        {
            scanf(",%d", &number);
            dq.push_back(number);
        }
        scanf(",%d]", &number);
        dq.push_back(number);
    }

    for(int i=0; i<strlen(command); i++)
    {
        if(command[i]=='R') R = 1-R; // 1-1=0, 1-0=1 
        else if(command[i]=='D')
        {
            if(dq.empty()) {printf("error\n"); return;} // 비어있으면 비울수 없으므로 에러 발생
            else
            {
                if(R==0) dq.pop_front(); // 맨 앞을 비움
                else if(R==1) dq.pop_back(); // 반대 상태면 맨 뒤를 비움
            }
        }
    }

    printf("[");
    if(!dq.empty())
    {
        if(R==0)
        {
            for(int i=0; i<dq.size()-1; i++) printf("%d,", dq[i]); // 맨 앞부터 출력

            printf("%d", dq[dq.size()-1]); // 마지막은 , 없이 출력
        }
        else if(R==1)
        {
            for(int i=dq.size()-1; i>0; i--) printf("%d,", dq[i]); // 반대 상태면 맨 뒤부터 출력

            printf("%d", dq[0]); // 마지막은 , 없이 출력
        }
    }
    printf("]\n");

    return;
}

int main()
{
    int t;
    scanf("%d", &t);

    for(int i=0; i<t; i++) solution();
}
