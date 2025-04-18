/* AC */

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
    tree[k][root].r = tree[k][left].r + tree[k][right].r;
    tree[k][root].e = tree[k][left].e + tree[k][right].e;
    tree[k][root].d = tree[k][left].d + tree[k][right].d;
    tree[k][root].re = tree[k][left].re + tree[k][right].re + tree[k][left].r * tree[k][right].e;
    tree[k][root].ed = tree[k][left].ed + tree[k][right].ed + tree[k][left].e * tree[k][right].d;
    tree[k][root].red = tree[k][left].red + tree[k][right].red + tree[k][left].r * tree[k][right].ed + tree[k][left].re * tree[k][right].d;
}

void build(int root, int left, int right)
{
    if (right - left == 1)
    {
        init_node(root, left);
        return;
    }
    int mid = (left + right) / 2;
    build(root * 2, left, mid);
    build(root * 2 + 1, mid, right);
    update_node(root, root * 2, root * 2 + 1);
}

void update(int root, int left, int right, int ind)
{
    if (right - left == 1)
    {
        init_node(root, left);
        return;
    }
    int mid = (left + right) / 2;
    if(ind < mid)
    {
        update(root * 2, left, mid, ind);
    }
    else
    {
        update(root * 2 + 1, mid, right, ind);
    }
    update_node(root, root * 2, root * 2 + 1);
}

int main()
{
    int n, q;
    char sub[10] = "0red";

    scanf("%d %d", &n, &q);
    scanf("%s %s", str[0], str[1]);

    k = 0;
    build(1, 0, n);
    k = 1;
    build(1, 0, n);

    while (q--)
    {
        int ind;
        char temp;

        scanf("%d", &ind);
        ind--;
        temp = str[0][ind];
        str[0][ind] = str[1][ind];
        str[1][ind] = temp;

        k = 0;
        update(1, 0, n, ind);
        k = 1;
        update(1, 0, n, ind);

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