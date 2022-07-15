/*
    c언어 입출력 그냥 나가 죽자;;
    c : 1200ms
    c++ : 800~900ms
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
