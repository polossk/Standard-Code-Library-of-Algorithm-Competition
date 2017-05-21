// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   poj 2429                                                 *
*****************************************************************************/

#include <map>
#include <ctime>
#include <climits>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }
inline int    nextInt() { int x; scanf("%d", &x); return x; }
inline int64  nextI64() { int64  d; cin >> d; return d; }
inline char   nextChr() { scanf(" "); return getchar(); }
inline double nextDbf() { double x; scanf("%lf", &x); return x; }
inline int64  next64d() { int64 d; scanf("%I64d",&d); return d; }

typedef map<int64, int64>::iterator itr;

const int64 MaxN = 1005;
const int64 INF  = ~0ull >> 1;
int64 gcd(int64 a, int64 b)
{
    if (a == 0) return 1;
    if (a < 0) return gcd(-a, b);
    while (b)
    {
        int64 t = a; a = b; b = t % b;
    }
    return a;

}

int64 mul_mod(int64 a, int64 b, int64 m)
{
    int64 t = 0; a %= m; b %= m;
    while (b)
    {
        if (b & 1) t += a, t = (t >= m)? t - m: t;
        a <<= 1; a = (a >= m)? a - m: a; b >>= 1;
    }
    return t;
}

int64 pow_mod(int64 a, int64 b, int64 m)
{
    int64 ans = 1; a %= m;
    while (b)
    {
        if (b & 1) ans = mul_mod(ans, a, m);
        b >>= 1; a = mul_mod(a, a, m);
    }
    return ans;
}

bool test(int64 a, int64 n, int64 x, int64 t)
{
    int64 ret = pow_mod(a, x, n);
    int64 last = ret;
    for (int i = 1; i <= t; i++)
    {
        ret = mul_mod(ret, ret, n);
        if (ret == 1 && last != 1 && last != n - 1)
            return true;
        last = ret;
    }
    if (ret != 1) return true;
    else return false;
}

bool isPrime(int64 n)
{
    int64 x = n - 1, t = 0;
    while ((x & 1) == 0) { x >>= 1; t++; }
    bool flag = 1;
    if (t >= 1 && (x & 1) == 1)
    {
        for (int k = 0; k < 25; k++)
        {
            int64 a = rand() % (n - 1) + 1;
            if (test(a, n, x, t)) { flag = 1; break; }
            flag = 0;
        }
    }
    if (!flag || n == 2) return 1;
    return 0;
}

int64 Pollard_rho(int64 x, int64 c)
{
    int64 i = 1, k = 2;
    int64 x0 = rand() % (x - 1) + 1;
    int64 y = x0;
    while (true)
    {
        i++;
        x0 = (mul_mod(x0, x0, x) + c) % x;
        int64 d = gcd(y - x0, x);
        if (d != 1 && d != x) return d;
        if (y == x0) return x;
        if (i == k) { y = x0; k += k; }
    }
}

int64 tot;
map<int64, int64> result;
// -> first: value, -> second: times
void findfac(int64 n)
{
    if (n == 1) return;
    if (isPrime(n)) { result[n]++; return; }
    int64 p = n;
    while (p >= n) p = Pollard_rho(p, rand() % (n - 1) + 1);
    findfac(p); findfac(n / p);
}

int64 cnt, data[MaxN];
inline int64 powi(int64 n, int64 k)
{
    int64 ans = 1LL;
    while (k) { ans *= n; k--; }
    return ans;
}

void pre()
{
    cnt = 0;
    for (itr i = result.begin(); i != result.end(); i++)
    {
        pair<int64, int64> tmp = *i;
        data[cnt++] = powi(tmp.first, tmp.second);
    }
}

int64 mins = INF;
int64 g, l, aa, bb, c;

void dfs(int64 a, int64 b, int n)
{
    if (a + b >= mins) return;
    if (n == cnt)
    {
        if (a + b < mins) { mins = a + b; aa = a; bb = b; }
        return;
    }
    dfs(a * data[n], b, n + 1);
    dfs(a, b * data[n], n + 1);
}

void solve()
{
    result.clear(); tot = cnt = 0;
    mins = INF;
    c = l / g; findfac(c);
    pre(); dfs(g, g, 0);
    if (aa > bb) swap(aa, bb);
    printf("%I64d %I64d\n", aa, bb);
}

int main()
{
    while (~scanf("%I64d%I64d", &g, &l)) solve();
    return 0;
}