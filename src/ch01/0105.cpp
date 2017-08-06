/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   HDU 4686                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;

const int MAXN = 5;
const int MAXM = 5;
const int MOD = 1000000007;

struct Matrix
{
    int n, m;
    int64 mat[MAXN][MAXM];
    Matrix(): n(-1), m(-1){}
    Matrix(int _n, int _m, bool lazy = false): n(_n), m(_m)
    {
        if (!lazy) memset(mat, 0, sizeof mat);
    }
    void Unit(int _s)
    {
        n = _s; m = _s;
        memset(mat, 0, sizeof mat);
        while (_s--) mat[_s][_s] = 1;
    }
    void print()
    {
        printf("n = %d, m =  %d\n", n, m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                printf("%8d", mat[i][j]);
            printf("\n");
        }
    }
};

Matrix add_mod(const Matrix& a, const Matrix& b, const int mod)
{
    Matrix ans(a.n, a.m);
    for (int i = 0; i < a.n; i++) for (int j = 0; j < a.m; j++)
        ans.mat[i][j] = (a.mat[i][j] + b.mat[i][j]) % mod;
    return ans;
}

Matrix mul(const Matrix& a, const Matrix& b)
{
    Matrix ans(a.n, b.m);
    for (int i = 0; i < a.n; i++)
        for (int k = 0; k < a.m; k++)
            for (int j = 0; j < b.m; j++)
                ans.mat[i][j] += a.mat[i][k] * b.mat[k][j];
    return ans;
}

Matrix mul_mod(const Matrix& a, const Matrix& b, const int mod)
{
    Matrix ans(a.n, b.m);
    for (int i = 0; i < a.n; i++)
        for (int k = 0; k < a.m; k++) if (a.mat[i][k])
            for (int j = 0; j < b.m; j++)
    {
        int64 tmp = (a.mat[i][k] * b.mat[k][j]) % mod;
        ans.mat[i][j] = (ans.mat[i][j] + tmp) % mod;
    }
    return ans;
}

Matrix pow_mod(const Matrix& a, int64 k, const int mod)
{
    Matrix ans(a.n, a.m, true); ans.Unit(a.n);
    if (k <= 1) return k == 0 ? ans : a;
    Matrix p(a);
    while (k)
    {
        if (k & 1) { ans = mul_mod(ans, p, mod); k--; }
        else { k /= 2; p = mul_mod(p, p, mod); }
    }
    return ans;
}

int64 n;
int64 a0, ax, ay;
int64 b0, bx, by;

void solve()
{
    Matrix ans(5, 1);

    Matrix beg(5, 1);
    beg.mat[0][0] = 1;
    beg.mat[1][0] = a0;
    beg.mat[2][0] = b0;
    beg.mat[3][0] = a0 * b0 % MOD;
    beg.mat[4][0] = 0;

    Matrix cef(5, 5);
    cef.mat[0][0] = 1;
    cef.mat[1][0] = ay % MOD; cef.mat[1][1] = ax % MOD;
    cef.mat[2][0] = by % MOD; cef.mat[2][2] = bx % MOD;
    cef.mat[3][0] = ay * by % MOD; cef.mat[3][1] = ax * by % MOD;
    cef.mat[3][2] = ay * bx % MOD; cef.mat[3][3] = ax * bx % MOD;
    cef.mat[4][3] = 1; cef.mat[4][4] = 1;

    Matrix tmp(5, 5, true);
    tmp = pow_mod(cef, n, MOD);
    ans = mul_mod(tmp, beg, MOD);

    cout << ans.mat[4][0] << endl;
    return;
}

int main()
{
    while (cin >> n)
    {
        cin >> a0 >> ax >> ay;
        cin >> b0 >> bx >> by;
        solve();
    }
    return 0;
}