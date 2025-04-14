/* AC 29ms */

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <algorithm>

const int MAX_N = 1e5 + 10;

struct limit_t
{
    uint64_t l, r;
    uint64_t x, y, k;
};

int n, m;
limit_t lim[MAX_N];
char strs[MAX_N];

int limit_cmp(limit_t &a, limit_t &b)
{
    if(a.l != b.l)
    {
        return a.l > b.l;
    }
    return a.r < b.r;
}

void fill_str(char *str, uint64_t x, uint64_t y, uint64_t k)
{
    uint64_t len = x + y;
    uint64_t l0, m0, r0s;

    if (y == 0)
    {
        memset(str, '0', len);
        return ;
    }
    if (k == 0)
    {
        memset(str, '1', y);
        memset(str + y, '0', x);
        return ;
    }
    if (k == x * y)
    {
        memset(str, '0', x);
        memset(str + x, '1', y);
        return ;
    }

    l0 = k / y;
    m0 = k % y;
    r0s = l0 + y;
    memset(str, '0', l0);
    memset(str + l0, '1', y);
    memset(str + r0s, '0', len - r0s);

    if (m0 != 0)
    {
        str[r0s] = '1';
        str[r0s - m0] = '0';
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    bool flag = true;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %llu %llu %llu", &(lim[i].l), &(lim[i].r), &(lim[i].x), &(lim[i].y), &(lim[i].k));
        lim[i].l--;
        if (lim[i].x + lim[i].y != lim[i].r - lim[i].l ||
            lim[i].x * lim[i].y < lim[i].k)
        {
            flag = false;
        }
    }
    if (flag == false)
    {
        printf("-1\n");
        return 0;
    }

    std::sort(lim, lim + m, limit_cmp);
    memset(strs, '0', sizeof(strs));
    if(m != 0)
    {
        fill_str(strs + lim[0].l, lim[0].x, lim[0].y, lim[0].k);
    }
    for(int i = 1; i < m; i++)
    {
        uint64_t remx = lim[i].x  - lim[i - 1].x;
        uint64_t remy = lim[i].y  - lim[i - 1].y;
        uint64_t ln = lim[i - 1].l - lim[i].l;
        uint64_t rn = lim[i].r - lim[i - 1].r;
        
        // 计算k的最小值
        uint64_t mink = lim[i - 1].k;
        if(rn < remx)
        {
            mink += (remx - rn) * lim[i - 1].y;
        }
        if(lim[i].k < mink)
        {
            flag = true;
            break;
        }

        uint64_t xl_max = std::min(remx, ln);
        uint64_t xl_min = 0;
        if (rn < remx)
        {
            xl_min = remx - rn;
        }
        flag = false;
        for (uint64_t xl = xl_min; xl <= xl_max; xl++)
        {
            uint64_t yl = ln - xl;
            uint64_t xr = remx - xl;
            uint64_t yr = remy - yl;

            mink = xl * lim[i - 1].y + lim[i - 1].x * yr + lim[i - 1].k + xl * yr;
            uint64_t max_kl = xl * yl;
            if(mink <= lim[i].k && lim[i].k <= mink + max_kl + xr * yr)
            {
                uint64_t remk = lim[i].k - mink;
                if(max_kl > remk)
                {
                    fill_str(strs + lim[i].l, xl, yl, remk);
                    fill_str(strs + lim[i - 1].r, xr, yr, 0);
                }
                else
                {
                    fill_str(strs + lim[i].l, xl, yl, max_kl);
                    fill_str(strs + lim[i - 1].r, xr, yr, remk - max_kl);
                }
                flag = true;
                break;
            }
        }
        if(flag == false)
        {
            break;
        }
    }
    if (flag == false)
    {
        printf("-1\n");
    }
    else
    {
        strs[n] = '\0';
        printf("%s\n", strs);
    }

    return 0;
}

/*

100000 57
340 99276 49554 49383 1225129599
891 98898 49108 48900 1202289142
933 97940 48611 48397 1177719446
1229 97525 48236 48061 1160317514
1327 96253 47535 47392 1128394746
1411 95894 47308 47176 1117873762
1710 95356 46892 46755 1097734543
2069 95133 46606 46459 1083221421
2326 94637 46214 46098 1066342451
4342 93297 44529 44427 990546304
4413 91559 43653 43494 949380280
4845 90895 43096 42955 925688655
5527 90440 42509 42405 900647787
6340 90271 42016 41916 879475276
8963 90239 40690 40587 824880117
9554 90236 40380 40303 812301522
9610 90119 40289 40221 808834561
10283 88151 38931 38938 757016843
10598 87865 38628 38640 744723568
10763 84716 36938 37016 683050628
12057 84125 35987 36082 647980462
12123 83821 35806 35893 640977194
12214 83029 35358 35458 625742411
12255 82251 34944 35053 611326130
12405 81947 34714 34829 603236972
12944 81665 34288 34434 588708897
13214 81602 34113 34276 582736399
13335 80631 33559 33738 564556272
13726 79943 33028 33190 546377588
15487 79686 32036 32164 513643208
15722 78611 31382 31508 492991529
16082 78415 31119 31215 484188813
16368 77423 30460 30596 465544473
16447 76920 30183 30291 456322417
16613 76275 29772 29891 444861515
16881 75851 29436 29535 434249168
18707 75368 28251 28411 400040297
18939 74518 27706 27874 384724732
19086 73950 27363 27502 374110688
19222 73932 27287 27424 371915647
19344 73908 27210 27355 370026869
19587 73899 27078 27235 366397380
20384 73560 26504 26673 351035456
21000 73547 26191 26357 342445041
21336 73341 25914 26092 335772486
22028 72509 25128 25354 316503335
22802 71861 24397 24663 299147946
23073 71790 24240 24478 295226842
23647 70701 23408 23647 275935649
24066 70364 23034 23265 267226332
24328 69749 22604 22818 256954384
24659 69565 22326 22581 251162012
25345 69261 21829 22088 240366406
25604 69198 21662 21933 236896629
28172 68765 20172 20422 205982344
28655 68198 19654 19890 196113702
28833 68120 19533 19755 193645358

*/