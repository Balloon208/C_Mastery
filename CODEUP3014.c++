/*
    c언어 입출력 그냥 나가 죽자;;
    c : 1200ms
    c++ : 800~900ms

    추가 노트 : c언어 scanf는 1000만번 실행에 약 0.9초가 걸리고
    c++ std::cin.tie(NULL);을 이용한 cin 은 1000만번 실행에 약 0.5초가 걸린다.
*/

#include <iostream>

using namespace std;

void preset() // 입출력 시간 줄이기
{ 
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL); 
}

int main(){
    preset();
    
	int n, num;
	int arr[100001]={};

	cin >> n;

	for(int i=0; i<n; i++)
    {
        cin >> num;
        arr[num]++;
    }

    int i=0;

	while(n!=0)
    {
		while(arr[i]!=0)
        {
            cout << i << " ";
            arr[i]--;
            n--;
        }
        i++;
	}

	return 0;
}