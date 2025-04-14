/* https://acm.hdu.edu.cn/showproblem.php?pid=1043 */
/* AC */
#include <stdio.h>
#include <string.h>
#include <stdint.h>

const int MAX_N = 20;
const int MAX_M = 362880 + 10;

const int64_t factorial[MAX_N] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};

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

struct step_node_t
{
    int pre;
    char pre_operation;
    unsigned char x_index;
};

step_node_t step[MAX_M];

void bfs()
{
    unsigned char sequ_buff[MAX_N];
    int32_t que[MAX_M];
    int front = 0, back = 1;

    memset(step, -1, sizeof(step));
    step[0].pre = -1;
    step[0].pre_operation = 0;
    step[0].x_index = 8;
    que[0] = 0;
    while(front < back)
    {
        step_node_t temp = step[que[front]];
        reverse_contor_expansion(que[front], 9, sequ_buff);
        if(temp.x_index % 3 != 2 && temp.pre_operation != 'r') /* right */
        {
            int exchange_index = temp.x_index + 1;
            unsigned char temp_slid = sequ_buff[exchange_index];
            sequ_buff[exchange_index] = 9;
            sequ_buff[temp.x_index] = temp_slid;
            int64_t pos = contor_expansion(sequ_buff, 9);
            sequ_buff[exchange_index] = temp_slid;
            sequ_buff[temp.x_index] = 9;
            if(step[pos].pre_operation == -1)
            {
                step[pos].pre = que[front];
                step[pos].pre_operation = 'l';
                step[pos].x_index = exchange_index;
                que[back] = pos;
                back++;
            }
        }
        if(temp.x_index < 6 && temp.pre_operation != 'd') /* down */
        {
            int exchange_index = temp.x_index + 3;
            unsigned char temp_slid = sequ_buff[exchange_index];
            sequ_buff[exchange_index] = 9;
            sequ_buff[temp.x_index] = temp_slid;
            int64_t pos = contor_expansion(sequ_buff, 9);
            sequ_buff[exchange_index] = temp_slid;
            sequ_buff[temp.x_index] = 9;
            if(step[pos].pre_operation == -1)
            {
                step[pos].pre = que[front];
                step[pos].pre_operation = 'u';
                step[pos].x_index = exchange_index;
                que[back] = pos;
                back++;
            }
        }
        if(temp.x_index % 3 != 0 && temp.pre_operation != 'l') /* left */
        {
            int exchange_index = temp.x_index - 1;
            unsigned char temp_slid = sequ_buff[exchange_index];
            sequ_buff[exchange_index] = 9;
            sequ_buff[temp.x_index] = temp_slid;
            int64_t pos = contor_expansion(sequ_buff, 9);
            sequ_buff[exchange_index] = temp_slid;
            sequ_buff[temp.x_index] = 9;
            if(step[pos].pre_operation == -1)
            {
                step[pos].pre = que[front];
                step[pos].pre_operation = 'r';
                step[pos].x_index = exchange_index;
                que[back] = pos;
                back++;
            }
        }
        if(temp.x_index >= 3 && temp.pre_operation != 'u') /* up */
        {
            int exchange_index = temp.x_index - 3;
            unsigned char temp_slid = sequ_buff[exchange_index];
            sequ_buff[exchange_index] = 9;
            sequ_buff[temp.x_index] = temp_slid;
            int64_t pos = contor_expansion(sequ_buff, 9);
            sequ_buff[exchange_index] = temp_slid;
            sequ_buff[temp.x_index] = 9;
            if(step[pos].pre_operation == -1)
            {
                step[pos].pre = que[front];
                step[pos].pre_operation = 'd';
                step[pos].x_index = exchange_index;
                que[back] = pos;
                back++;
            }
        }
        front++;
    }
}

int main()
{
    unsigned char start[MAX_N];
	char str[50];
    int operation_len;
    char input;

    bfs();
    // for(int i = 0; i <= factorial[9]; i++)
    // {
    //     int pos = i;
    //     if(step[pos].pre_operation == -1)
    //     {
    //         printf("unsolvable\n");
    //     }
    //     else
    //     {
    //         while (pos > 0)
    //         {
    //             printf("%c", step[pos].pre_operation);
    //             pos = step[pos].pre;
    //         }
    //         printf("\n");
    //     }
    // }

	while(fgets(str, 50, stdin) != NULL)
    {
		int len = strlen(str);
		for(int i = 0, j = 0; i < len && j < 9; i++)
		{
			if(str[i] == 'x')
			{
				start[j] = 9;
				j++;
			}
			if(str[i] >= '1' && str[i] <= '8')
			{
				start[j] = (int)(str[i] - '0');
				j++;
			}
		}

        int64_t pos = contor_expansion(start, 9);
        if(step[pos].pre_operation == -1)
        {
            printf("unsolvable\n");
        }
        else
        {
            for(int64_t i = pos; i > 0; i = step[i].pre)
            {
                printf("%c", step[i].pre_operation);
            }
            printf("\n");
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
dlurulldrrdllurdruldr
ddrruullddrruullddrruullddrr

*/