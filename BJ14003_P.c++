    /*
    논리

    A. v이 비어있다면 num[i]를 push한다.

    B-1) v의 마지막 값보다 num[i]가 크면 push한다.

    B-2) 아니라면 v의 lower_bound(v.begin(), v.end(), num[i])의 값을 num[i]로 바꿔준다.

    관련 링크 : https://tjdahr25.tistory.com/19
    */

    #include <iostream>
    #include <algorithm>
    #include <vector>

    using namespace std;

    int n;
    int num[1000001];
    int indexarr[1000001];

    void solve()
    {
        int a;
        vector<int> v;
        for(int i=0; i<n; i++)
        {
            cin >> num[i];
            if(v.size()==0 || v[v.size()-1]<num[i])
            {
                v.push_back(num[i]);
                indexarr[i]=v.size()-1;
            }
            else
            {
                int left = 0;
                int right = v.size()-1;
                while(left < right)
                {
                    int mid = (left+right)/2;
                    if(v[mid]>=num[i]) right=mid;
                    else left = mid+1;
                }
                v[left]=num[i];
                indexarr[i]=left;
            }
        }

        cout << v.size() << '\n';

        vector<int> Answer;
        int findindex = v.size()-1;
        for(int i=n-1; i>=0; i--)
        {
            if(indexarr[i]==findindex)
            {
                findindex--;
                Answer.push_back(num[i]);
            }
        }

        for(int i=Answer.size()-1; i>=0; i--)
        {
            cout << Answer[i] << " ";
        }
    }

    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        cin >> n;
        solve();
    }
