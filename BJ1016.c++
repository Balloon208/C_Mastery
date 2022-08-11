#include <iostream>

using namespace std;

int main()
{
    int number[1000001]={0, };

    long long a, b;
    int result=0;

    cin >> a >> b;

    for(long long i=2; i*i<=b; i++) // 에라토스테네스의 체의 응용
    {
        long long n=a/(i*i);

        if(a%(i*i)) n++; // 제곱수의 경우엔 1을 올려서 계산 해야함 (if: a=4 -> n=1 이기 때문에 n++)

        while(n*i*i<=b)
        {
            number[(n*i*i)-a]++;
            n++;
        }
    }

    for(int i=0; i<=b-a; i++)
    {
        if(number[i]==0) result++;
    }

    cout << result;
}
