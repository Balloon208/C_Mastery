#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int,int>> timeset;
priority_queue<int, vector<int>, greater<int>> endtime;

int main()
{
    int n, size=0, result=0;
    cin >> n;
    
    for(int i=0; i<n; i++)
    {
        int a, b;
        cin >> a >> b;
        timeset.push_back({a, b});
    }
    
    sort(timeset.begin(), timeset.end());
    
    for(int i=0; i<timeset.size(); i++)
    {
    	// 강의실을 빌려야함!
        endtime.push(timeset[i].second);
        // 하지만 재사용 가능한 강의실이 있으면 강의실이 더 필요없다.
        if(endtime.top() <= timeset[i].first) endtime.pop();
        
    }
    
    cout << endtime.size();
}