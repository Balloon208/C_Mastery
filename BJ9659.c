/*

1 SK
2 CY
3 SK
4 CY
5 SK
6 CY
7 SK
8 CY

9655 문제의 범위 확장 문제 -> 범위가 long long이므로 바꿔줌.

*/

#include <stdio.h>

int main()
{
	long long a;
	scanf("%lld", &a);
	
	if(a%2==1) printf("SK");
	else printf("CY");
}
