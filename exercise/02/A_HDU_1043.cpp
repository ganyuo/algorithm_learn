/* time limit exceeded */
#include <stdio.h>
#include <string.h>
#include <stdint.h>

const int MAX_N = 20;
const int MAX_M = 362880 + 10;

struct bfs_node_t
{
    int position;
    int pre;
    char pre_operation;
    unsigned char x_index;
};

int64_t factorial[MAX_N];

int64_t contor_expansion(unsigned char sequence[], int len)
{
    int64_t small, ans = 0;
    for(int i = 0; i < len; i++)
    {
        small = 0;
        for(int j = i - 1; j >= 0; j--)
        {
            if(sequence[i] > sequence[j])
            {
                small++;
            }
        }
        ans += (sequence[i] - small - 1) * factorial[len - i - 1];
    }
    return ans;
}

void reverse_contor_expansion(int64_t position, int len, unsigned char sequence[])
{
    char flag[MAX_N] = {0};
    for(int i = 0; i < len; i++)
    {
        int count = position / factorial[len - i - 1];
        position -= (count * factorial[len - i - 1]);
        for(int j = 1; j <= len; j++)
        {
            if(flag[j] == 0)
            {
                count--;
            }
            if(count < 0)
            {
                sequence[i] = j;
                flag[j] = 1;
                break;
            }
        }
    }
}

bfs_node_t que[MAX_M];
char book[MAX_M];
char operations[MAX_M];

int bfs(unsigned char start[])
{
    unsigned char sequ_buff[MAX_N];
    int operation_len;
    int front = 0, back = 1;
    
    memset(book, 0, sizeof(book));
    que[0].position = contor_expansion(start, 9);
    que[0].pre = -1;
    que[0].pre_operation = '0';
    for(int i = 0; i < 9; i++)
    {
        if(start[i] == 9)
        {
            que[0].x_index = i;
            break;
        }
    }
    if(que[0].position == 0)
    {
        operations[0] = '\0';
        return 0;
    }
    book[que[0].position] = 1;
    while(front < back)
    {
        bfs_node_t temp = que[front];
        reverse_contor_expansion(temp.position, 9, sequ_buff);
        if(temp.x_index >= 3 && temp.pre_operation != 'd') /* up */
        {
            int exchange_index = temp.x_index - 3;
            unsigned char temp_slid = sequ_buff[exchange_index];
            sequ_buff[exchange_index] = 9;
            sequ_buff[temp.x_index] = temp_slid;
            int pos = contor_expansion(sequ_buff, 9);
            sequ_buff[exchange_index] = temp_slid;
            sequ_buff[temp.x_index] = 9;
            if(book[pos] == 0)
            {
                que[back].position = pos;
                que[back].pre = front;
                que[back].pre_operation = 'u';
                que[back].x_index = exchange_index;
                back++;
                book[pos] = 1;
                if(pos == 0)
                {
                    break;
                }
            }
        }
        if(temp.x_index < 6 && temp.pre_operation != 'u') /* down */
        {
            int exchange_index = temp.x_index + 3;
            unsigned char temp_slid = sequ_buff[exchange_index];
            sequ_buff[exchange_index] = 9;
            sequ_buff[temp.x_index] = temp_slid;
            int pos = contor_expansion(sequ_buff, 9);
            sequ_buff[exchange_index] = temp_slid;
            sequ_buff[temp.x_index] = 9;
            if(book[pos] == 0)
            {
                que[back].position = pos;
                que[back].pre = front;
                que[back].pre_operation = 'd';
                que[back].x_index = exchange_index;
                back++;
                book[pos] = 1;
                if(pos == 0)
                {
                    break;
                }
            }
        }
        if(temp.x_index % 3 != 0 && temp.pre_operation != 'r') /* left */
        {
            int exchange_index = temp.x_index - 1;
            unsigned char temp_slid = sequ_buff[exchange_index];
            sequ_buff[exchange_index] = 9;
            sequ_buff[temp.x_index] = temp_slid;
            int pos = contor_expansion(sequ_buff, 9);
            sequ_buff[exchange_index] = temp_slid;
            sequ_buff[temp.x_index] = 9;
            if(book[pos] == 0)
            {
                que[back].position = pos;
                que[back].pre = front;
                que[back].pre_operation = 'l';
                que[back].x_index = exchange_index;
                back++;
                book[pos] = 1;
                if(pos == 0)
                {
                    break;
                }
            }
        }
        if(temp.x_index % 3 != 2 && temp.pre_operation != 'l') /* right */
        {
            int exchange_index = temp.x_index + 1;
            unsigned char temp_slid = sequ_buff[exchange_index];
            sequ_buff[exchange_index] = 9;
            sequ_buff[temp.x_index] = temp_slid;
            int pos = contor_expansion(sequ_buff, 9);
            sequ_buff[exchange_index] = temp_slid;
            sequ_buff[temp.x_index] = 9;
            if(book[pos] == 0)
            {
                que[back].position = pos;
                que[back].pre = front;
                que[back].pre_operation = 'r';
                que[back].x_index = exchange_index;
                back++;
                book[pos] = 1;
                if(pos == 0)
                {
                    break;
                }
            }
        }
        front++;
    }

    if(front < back)
    {
        int j = MAX_M;
        for(int i = back - 1; que[i].pre >= 0; i = que[i].pre)
        {
            j--;
            operations[j] = que[i].pre_operation;
        }
        operation_len = MAX_M - j;
        for(int i = 0; i < operation_len; i++)
        {
            operations[i] = operations[i + j];
        }
        operations[operation_len] = '\0';
        return operation_len;
    }
    return -1;
}

int main()
{
    unsigned char start[MAX_N];
    int operation_len;
    char input;

    factorial[0] = 1;
    for(int i = 1; i < 15; i++)
    {
        factorial[i] = factorial[i - 1] * i;
    }

    while (true)
    {
        for(int i = 0; i < 9; i++)
        {
            while((input = getchar()) != EOF)
            {
                if(input == 'x')
                {
                    start[i] = 9;
                    break;
                }
                else if(input >= '1' && input <= '9')
                {
                    start[i] = input - '0';
                    break;
                }
            }
            if(input == EOF)
            {
                return 0;
            }
        }

        operation_len = bfs(start);
        if(operation_len < 0)
        {
            printf("unsolvable\n");
        }
        else
        {
            printf("%s\n", operations);
        }
    }

    return 0;
}

/*

input:
2  3  4  1  5  x  7  6  8
2  3  4  1  5  x  6  8  7
x  8  7  6  5  4  3  2  1
1  2  3  4  5  6  7  8  x

output:
ullddrurdllurdruldr

*/