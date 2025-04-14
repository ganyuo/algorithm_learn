#include <stdio.h>
#include <string.h>

const int MAX_N = 10;

struct node_t
{
	int row;
	int col;
	int block;
};


int mp[MAX_N][MAX_N];
bool row[MAX_N][MAX_N];
bool col[MAX_N][MAX_N];
bool block[MAX_N][MAX_N];

int emp_n;
node_t emp[MAX_N * MAX_N];

bool dfs(int k)
{
	if(k >= emp_n)
	{
		return true;
	}
	for(int i = 1; i <= 9; i++)
	{
		if (row[emp[k].row][i] == true &&
			col[emp[k].col][i] == true &&
			block[emp[k].block][i] == true)
		{
			mp[emp[k].row][emp[k].col] = i;
			row[emp[k].row][i] = false;
			col[emp[k].col][i] = false;
			block[emp[k].block][i] = false;
			if(dfs(k + 1) == true)
			{
				return true;
			}
			row[emp[k].row][i] = true;
			col[emp[k].col][i] = true;
			block[emp[k].block][i] = true;
		}
	}
	return false;
}

int main()
{
	memset(row, true, sizeof(row));
	memset(col, true, sizeof(col));
	memset(block, true, sizeof(block));
	emp_n = 0;
    for(int i = 1; i <= 9; i++)
    {
		for(int j = 1; j <= 9; j++)
		{
        	scanf("%d", &mp[i][j]);
			int bi = (i - 1) / 3 * 3 + (j - 1) / 3 + 1;
			if(mp[i][j] == 0)
			{
				emp[emp_n].row = i;
				emp[emp_n].col = j;
				emp[emp_n].block = bi;
				emp_n++;
			}
			else
			{
				row[i][mp[i][j]] = false;
				col[j][mp[i][j]] = false;
				block[bi][mp[i][j]] = false;
			}

		}
    }

	dfs(0);

    for(int i = 1; i <= 9; i++)
    {
        for(int j = 1; j <= 8; j++)
        {
            printf("%d ", mp[i][j]);
        }
        printf("%d\n", mp[i][9]);
    }
	return 0;
}
