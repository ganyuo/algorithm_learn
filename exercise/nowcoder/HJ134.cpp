#include <stdio.h>
#include <string.h>
#include <stdint.h>

const int MAX_N = 2e5 + 10;

struct node_t
{
    uint64_t lz, rz;
    uint64_t sum;
};

node_t tree[4 * MAX_N];
char str[MAX_N];

inline node_t merge_node(const node_t &left, uint64_t llen, const node_t &right, uint64_t rlen)
{
    node_t merge;
    merge.sum = left.sum + right.sum;
    merge.sum += llen * rlen;
    merge.sum -= left.rz * right.lz;
    merge.lz = left.lz;
    if(left.lz == llen)
    {
        merge.lz += right.lz;
    }
    merge.rz = right.rz;
    if(right.rz == rlen)
    {
        merge.rz += left.rz;
    }
    return merge;
}

void build_tree(uint64_t root, uint64_t left, uint64_t right)
{
    if(right - left == 1)
    {
        if(str[left] == '0')
        {
            tree[root].sum = 0;
            tree[root].lz = 1;
            tree[root].rz = 1;
        }
        else
        {
            tree[root].sum = 1;
            tree[root].lz = 0;
            tree[root].rz = 0;
        }
        return;
    }
    uint64_t mid = (left + right) / 2;
    build_tree(root << 1, left, mid);
    build_tree((root << 1) + 1, mid, right);
    tree[root] = merge_node(tree[root << 1], mid - left, tree[(root << 1) + 1], right - mid);
}

node_t quest(uint64_t root, uint64_t left, uint64_t right, uint64_t ql, uint64_t qr)
{
    if(left == ql && right == qr)
    {
        return tree[root];
    }
    uint64_t mid = (left + right) / 2;
    if(qr <= mid)
    {
        return quest(root << 1, left, mid, ql, qr);
    }
    else if(mid <= ql)
    {
        return quest((root << 1) + 1, mid, right, ql, qr);
    }
    else
    {
        node_t lans = quest(root << 1, left, mid, ql, mid);
        node_t rans = quest((root << 1) + 1, mid, right, mid, qr);
        return merge_node(lans, mid - ql, rans, qr - mid);
    }
}

int main()
{
    int n, q;
    uint64_t ql, qr;

    scanf("%d %s", &n, str);
    // fgets(str, MAX_N, stdin);
    scanf("%d", &q);
    build_tree(1, 0, n);
    for(int i = 0; i < q; i++)
    {
        scanf("%d %d", &ql, &qr);
        node_t ans = quest(1, 0, n, ql - 1, qr);
        printf("%llu\n", ans.sum);
    }
    return 0;
}