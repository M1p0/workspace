#define MAXN 100
//穷举法
void MatrixMultiply(int **a, int **b, int p, int q, int r)  //p,q为a的行列 q,r为b的行列
{
    int sum[MAXN][MAXN];
    for (int i=0;i<p;i++) //遍历矩阵a的行
    {
        for (int j = 0; j < r; j++)  //遍历矩阵b的列
        {
            for (int k=0;k<q;k++)  //对应位置相乘
            {
                sum[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}
