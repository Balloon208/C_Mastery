#include <iostream>

/*
0 = 0 (0)
1 = 1->0 (1)
2 = 2 (0)
3 = 3->1->0 (2)
4 = 4->2 (1)
5 = 5->3->1->0 (3)
6 = 6->4->2 (2)
7 = 7->5->3->1->0 (4)
8 = 8->6->4->2 (3)
(최대한의 경우의 수를 구함)

f(x) =
if(a==0 || a==2) 영향 없으므로 continue;
if 홀수 : ((n+1)/2)를 XOR연산
if 짝수 : ((n-2)/2)를 XOR연산
*/

using namespace std;

int main()
{
    int n, a, result;
    cin >> n;
    result = 0;
    while (n--)
    {
        cin >> a;
        if(a==0 || a==2) continue;
        else if(a&1) result ^= ((a+1)/2);
        else result ^= ((a-2)/2);
    }
    cout << (result ? "koosaga" : "cubelover");
}