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

int main()
{
    int n, q;
    char sub[10] = "0red";
    
    scanf("%d %d", &n, &q);
    scanf("%s %s", str[0] + 1, str[1] + 1);

    while (q--)
    {
        printf("%lld\n", tree[0][0].red - tree[1][0].red);
    }
    return 0;
}

/*

5 2
redar
adade
5 4

*/