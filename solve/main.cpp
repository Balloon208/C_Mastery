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

// O(n)���� Ǯ������ٸ�, B(ranking)���� Ŀ���ٸ� TLE�� ������ ����. ���� �̺� Ž������ Ǯ���ش�.
int query(int index, int target, int start, int end)
{
    if(start==end) return start; // �ظ� �����ϹǷ� ���� ó���� �� �ʿ� ����.
    int mid = (start+end)/2;

    if(target<=tree[index*2]) // ���� ���� ������ Ʈ���� �Ʒ����� ���� �� ���� ���� ���ֱ� ���� ã�ư���.
    {
        return query(index*2, target, start, mid);
    }
    else // ���� �ִٸ�, �ش� �������� ���� Ʈ���� �������� ���� �� ���� �ִ��� Ȯ���Ѵ�.
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
            update(1, favor, -1, 1, MAXN); // �ϳ� �����Ƿ� ������Ʈ ���ش�
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
    input();
}
