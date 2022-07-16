/*
1 SK
2 CY
3 SK
4 SK
5 SK
6 SK
7 CY
ㅡㅡㅡㅡㅡㅡㅡ
8 SK
9 CY
10 SK
11 SK
12 SK
.
.
.
*/

#include <stdio.h>

int main()
{
	int a;
	scanf("%d", &a);
	
	if(a%7==2 || a%7==0) printf("CY");
	else printf("SK");
}
