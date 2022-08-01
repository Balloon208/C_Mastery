#include <iostream>
#include <queue>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL); 
	
	priority_queue<int,vector<int>,greater<int>> q; // 최소 힙 정의

	int n;
	int console;

	cin >> n;

	for(int i=0; i<n; i++)
    {
        cin >> console;

        if(console==0)
        {
            if(!q.empty())
            {
                cout << q.top() << '\n';
                q.pop();
            }
            else
            {
                cout << 0 << '\n';
            }
        }
        else q.push(console);
    }
}
