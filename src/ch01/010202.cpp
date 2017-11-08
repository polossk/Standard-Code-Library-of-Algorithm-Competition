const int MAXN = 40;
inline int xorsolve(int a[][MAXN], int ans[], int n_equ, int n_var)
{
    // old format: A[][] * x[] = B[]
    // new format: A[][0 .. n - 1] * x[] = A[][n]
    // the last row is B[] so called
    int res = 0, r = 0;
    for (int i = 0, col = 0; i < n_equ && col < n_var; i++, col++)
    {
        int m_row = i;
        for (int j = i + 1; j < n_equ; j++)
            m_row = abs(a[j][col]) > abs(a[m_row][col]) ? j : m_row;
        if (m_row != i) for (int j = i; j < n_var + 1; j++)
            swap(a[i][j], a[m_row][j]);
        if (a[i][col] == 0) { i--; continue; }
        for (int j = i + 1; j < n_equ; j++) if (a[j][col] != 0)
        {
            for (int k = col; k < n_var + 1; k++)
                a[j][k] ^= a[i][k];
        }
    }
    for (int i = n_var - 1; i >= 0; i--)
    {
        ans[i] = a[i][n_var];
        for (int j = i + 1; j < n_var; j++)
            ans[i] ^= (a[i][j] && ans[j]);
    }
    return 0;
}