#include <iostream>
#define MAXN 1000001

using namespace std;

int n;
int tree[MAXN*4];

void update(int index, int target, int amount, int start, int end)
{
    if(target < start || target > end) return;

    tree[index]+=amount;
    if(start==end) return;

    int mid = (start+end)/2;
    update(index*2, target, amount, start, mid);
    update(index*2+1, target, amount, mid+1, end);
}

// O(n)으로 풀어버린다면, B(ranking)값이 커진다면 TLE가 무조건 난다. 따라서 이분 탐색으로 풀어준다.
int query(int index, int target, int start, int end)
{
    if(start==end) return start; // 해를 보장하므로 예외 처리는 할 필요 없다.
    int mid = (start+end)/2;

    if(target<=tree[index*2]) // 왼쪽 보다 작으면 트리의 아래쪽을 가서 더 작은 값을 빼주기 위해 찾아간다.
    {
        return query(index*2, target, start, mid);
    }
    else // 뺄수 있다면, 해당 범위까지 빼고 트리의 오른쪽을 가서 더 뺄수 있는지 확인한다.
    {
        return query(index*2+1, target-tree[index*2], mid+1, end);
    }

}

void input()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int mode;
        cin >> mode;
        if(mode == 1)
        {
            int ranking;
            cin >> ranking;
            int favor = query(1, ranking, 1, MAXN);
            cout << favor << '\n';
            update(1, favor, -1, 1, MAXN); // 하나 뺐으므로 업데이트 해준다
        }
        else
        {
            int nodenum, amount;
            cin >> nodenum >> amount;
            update(1, nodenum, amount, 1, MAXN);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    input();
}
