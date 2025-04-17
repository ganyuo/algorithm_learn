#include <stdio.h>
#include <string.h>
#include <algorithm>

const int MAX_N = 200 + 10;

struct student_t
{
    int id;
    int score;
    char name[32];
};

bool cmp_up(const student_t &a, const student_t &b)
{
    if (a.score == b.score)
    {
        return a.id < b.id;
    }
    return a.score > b.score;
}

bool cmp_down(const student_t &a, const student_t &b)
{
    if (a.score == b.score)
    {
        return a.id < b.id;
    }
    return a.score < b.score;
}

int main()
{
    int n, opt, id = 0;
    student_t stu[MAX_N];

    scanf("%d %d", &n, &opt);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d", stu[i].name, &stu[i].score);
        stu[i].id = id;
        id++;
    }
    if (opt == 0)
    {
        std::sort(stu, stu + n, cmp_up);
    }
    else
    {
        std::sort(stu, stu + n, cmp_down);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%s %d\n", stu[i].name, stu[i].score);
    }
    return 0;
}