#include <iostream>
#include <algorithm>

using namespace std;

int arr[51];
int n, s;

void input()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    cin >> s;
}

void change(int cnt, int where)
{
    int temp = arr[where]; // 가장 큰 수를 저장한다.
    for(int i=where-1; i>=cnt; i--) // 놓을 위치의 숫자까지 오른쪽으로 한칸씩 옮긴다.
    {
        arr[i+1]=arr[i];
        s--; // 이는 교환이 일어났다는 뜻이므로, 남은 교환 횟수를 빼준다.
    }
    arr[cnt]=temp; // 놓을 위치에 가장 큰 수를 넣는다.
}

void solve()
{
    int top, where;
    for(int i=0; (i<n && s>0); i++) // 교환 횟수가 있거나, 배열이 끝날 때까지 반복한다.
    {
        top = 0;
        where = 0;
        for(int j=i; (j<n && j<=s+i); j++) // 남은 교환수의 범위 안에 있어야 한다.
        {
            if(top < arr[j]) // 가장 큰 곳의 수와 위치를 갱신한다.
            {
                top = arr[j];
                where = j;
            }
        }
        change(i, where); // s 범위내에서 가장 큰 것을 찾아 왼쪽으로 배치한다.
        // i는 놓을 위치, where는 범위 내에 존재하는 가장 큰 숫자의 위치 이다.

        /*
       	// 교환 이후 배열의 상태
        for(int i=0; i<n; i++)
        {
            cout << arr[i] << ' ';
        }
    	cout << '\n';
        cout << "left swap : " << s << '\n';
        */
    }

	// 최종 결과 출력
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << ' ';
    }
}

int main()
{
    input();
    solve();

}