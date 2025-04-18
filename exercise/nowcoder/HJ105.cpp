/* 超时，要用线段树优化 */

#include <stdio.h>
#include <string.h>
#include <stdint.h>

const int MAX_N = 2e5 + 10;

struct node_t
{
    uint64_t r, e, d;
    uint64_t re, ed, red;
};

char str[2][MAX_N];
node_t tree[2][MAX_N * 4];
int k;

void init_node(int root, int ind)
{
    memset(&tree[k][root], 0, sizeof(node_t));
    if(str[k][ind] == 'r')
    {
        tree[k][root].r = 1;
    }
    else if(str[k][ind] == 'e')
    {
        tree[k][root].e = 1;
    }
    else if(str[k][ind] == 'd')
    {
        tree[k][root].d = 1;
    }
}

void update_node(int root, int left, int right)
{

}

void build(int root, int left, int right)
{
    if (right - left == 1)
    {
        init_node(root, left);
    }
    int mid = (left + right) / 2;
    build(root * 2, left, mid);
    build(root * + 1, mid, right);
    update_node(root, root * 2, root * 2 + 1);
}

int main()
{
    int n, q;
    char sub[10] = "0red";

    scanf("%d %d", &n, &q);
    scanf("%s %s", str[0] + 1, str[1] + 1);

    while (q--)
    {
        printf("%lld\n", tree[0][1].red - tree[1][1].red);
    }
    return 0;
}

/*

5 2
redar
adade
5 4

*/