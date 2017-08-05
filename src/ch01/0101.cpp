const int MaxN = 1010;
const int MaxM = 1010;
struct Matrix
{
    int n, m;
    int a[MaxN][MaxM];
    void clear() { n = m = 0; memset(a, 0, sizeof(a)); }
    Matrix operator+(const Matrix& b) const
    {
        Matrix tmp; tmp.n = n; tmp.m = m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                tmp.a[i][j] = a[i][j] + b.a[i][j];
        return tmp;
    }
    Matrix operator-(const Matrix& b) const
    {
        Matrix tmp; tmp.n = n; tmp.m = m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                tmp.a[i][j] = a[i][j] - b.a[i][j];
        return tmp;
    }
    Matrix operator*(const Matrix& b) const
    {
        Matrix tmp; tmp.clear(); tmp.n = n; tmp.m = b.m;
        for (int i = 0; i < n; i++)
            for (int k = 0; k < m; k++)
                for (int j = 0; j < b.m; j++)
                    tmp.a[i][j] += a[i][k] * b.a[k][j];
        return tmp;
    }
    void print()
    {
        printf("n = %d, m = %d\n", n, m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                printf("%4d", a[i][j]);
            puts("");
        }
        puts("");
    }
};