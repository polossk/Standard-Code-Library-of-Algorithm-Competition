// f_x = a_x-1 * f_x-1 + a_x-2 * f_x-2 + ... + a_x-n * f_x-n
// More specific, fn = a_n-1 * f_n-1 + a_n-2 * f_n-2 + ... + a_0 * f_0
// Create A[n][n] and B[n] to calculate f(t)
// eg. f3 = 2 * f2 + 3 * f1 - f0, f0 = 1, f1 = 2, f2 = 4.
// => a[] = {-1, 3, 2}, b[] = {1, 2, 4}.
int solve(int a[], int b[], int n, int t)
{
    Matrix M, F, E;
    M.clear(); M.n = M.m = n;
    F.clear(); F.n = n; F.m = 1;
    E.clear(); E.n = E.m = n;
    for (int i = 1; i < n; i++) M.a[i - 1][i] = 1;
    for (int i = 0; i < n; i++)
    {
        M.a[n - 1][i] = a[i];
        F.a[i][0] = b[i];
        E.a[i][i] = 1;
    }
    if (t < n) return F.a[t][0];
    while (t)
    {
        if (t & 1) { E = E * M; t--; }
        else { t /= 2; M = M * M; }
    }F = E * F;
    return F.a[0][0];
}