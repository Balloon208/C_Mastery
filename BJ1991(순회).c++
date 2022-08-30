#include <iostream>
#include <vector>

using namespace std;

struct node{
    char left;
    char right;
};

vector<node> graph(26);

void preorder(char node)
{
    if(node=='.') return;

    printf("%c", node);
    preorder(graph[node].left);
    preorder(graph[node].right);
}

void inorder(char node)
{
    if(node=='.') return;

    inorder(graph[node].left);
    printf("%c", node);
    inorder(graph[node].right);
}

void postorder(char node)
{
    if(node=='.') return;

    postorder(graph[node].left);
    postorder(graph[node].right);
    printf("%c", node);
}

int main()
{
    int n;
    char rt, l, r;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> rt >> l >> r;
        graph[rt].left=l;
        graph[rt].right=r;
    }
    preorder('A');
    cout << '\n';

    inorder('A');
    cout << '\n';

    postorder('A');
}
