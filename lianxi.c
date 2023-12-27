#include <stdio.h>
#include <string.h>

int a[100][100] = {0};

void swap(int i, int j, int x, int y)
{
    int tmp = a[i][j];
    a[i][j] = a[x][y];
    a[x][y] = tmp;
}

// 交换两行
void swap_r(int c, int i, int j)
{
    for (int k = 0; k < c; k++)
    {
        swap(i - 1, k, j - 1, k);
    }
}

// 交换两列
void swap_c(int r, int i, int j)
{
    for (int k = 0; k < r; k++)
    {
        swap(k, i - 1, k, j - 1);
    }
}

// 删除一行
void del_r(int r, int c, int i)
{
    for (int k = i; k < r; k++)
    {
        for (int m = 0; m < c; m++)
        {
            a[k - 1][m] = a[k][m];
        }
    }
}

// 删除一列
void del_c(int r, int c, int i)
{
    for (int k = i; k < c; k++)
    {
        for (int m = 0; m < r; m++)
        {
            a[m][k - 1] = a[m][k];
        }
    }
}

// 插入一行
void insert_r(int r, int c, int i)
{
    for (int k = r; k >= i - 1; k--)
    {
        for (int m = 0; m < c; m++)
        {
            a[k][m] = a[k - 1][m];
        }
    }
    for (int k = 0; k < c; k++)
    {
        a[i - 1][k] = 0;
    }
}

// 插入一列
void insert_c(int r, int c, int i)
{
    for (int k = c; k >= i - 1; k--)
    {
        for (int m = 0; m < r; m++)
        {
            a[m][k] = a[m][k - 1];
        }
    }

    for (int k = 0; k < r; k++)
    {
        a[k][i - 1] = 0;
    }
}

int main()
{
    int r, c, n;
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    scanf("%d", &n);
    char od[5];
    while (n--)
    {
        scanf("%s", od);
        int i, j;
        if (strcmp(od, "SR") == 0)
        {
            scanf("%d %d", &i, &j);
            swap_r(c, i, j);
        }
        else if (strcmp(od, "SC") == 0)
        {
            scanf("%d %d", &i, &j);
            swap_c(r, i, j);
        }
        else if (strcmp(od, "DR") == 0)
        {
            scanf("%d", &i);
            del_r(r, c, i);
            r--;
        }
        else if (strcmp(od, "DC") == 0)
        {
            scanf("%d", &i);
            del_c(r, c, i);
            c--;
        }
        else if (strcmp(od, "IR") == 0)
        {
            scanf("%d", &i);
            insert_r(r, c, i);
            r++;
        }
        else if (strcmp(od, "IC") == 0)
        {
            scanf("%d", &i);
            insert_c(r, c, i);
            c++;
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}