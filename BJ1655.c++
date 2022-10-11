// hint : https://yabmoons.tistory.com/478

#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> minq;
priority_queue<int> maxq;
int arr[100010];

int main()
{
    int n, num, cnt=0;
    cin >> n;
    
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    
    for(int i=0; i<n; i++)
    {
        if(maxq.size()>minq.size()) minq.push(-arr[i]);
        else maxq.push(arr[i]);

        if(!maxq.empty() && !minq.empty() && maxq.top()> -minq.top())
        {
            int x= maxq.top();
            int y= -minq.top();

            maxq.pop();
            minq.pop();

            maxq.push(y);
            minq.push(-x);
        }

        cout << maxq.top() << '\n';
    }
}
