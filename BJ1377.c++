/*
1 3 4 2 0
0 1 2 3 4
1 2 2 -1 -4 = 3

0 1 2 3 4
0 1 2 3 4
0 0 0 0 0 = 1
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int arr[500001]={};
    int n;
    cin >> n;

    vector<pair<int,int>>v(n);

    for(int i=0; i<n; i++)
    {
        cin >> v[i].first;
        v[i].second=i;
    }

    sort(v.begin(), v.end());

    int ans = -1;

    for(int i=0; i<n; i++)
    {
        if(ans<v[i].second-i) ans=v[i].second-i;
    }

    cout << ans+1;
}
