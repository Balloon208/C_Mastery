/*
1 CY
2 SK
3 CY
4 SK
5 SK
6 SK
7 SK
ㅡㅡㅡㅡㅡㅡㅡ
8 CY
9 SK
10 CY
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
	
	if(a%7==1 || a%7==3) printf("CY");
	else printf("SK");
}
