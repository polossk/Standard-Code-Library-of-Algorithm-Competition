// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   ZOJ 3203                                                 *
*****************************************************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }
inline int    nextInt() { int x; scanf("%d", &x); return x; }
inline int64  nextI64() { int64  d; cin >> d; return d; }
inline char   nextChr() { scanf(" "); return getchar(); }
inline string nextStr() { string s; cin >> s; return s; }
inline double nextDbf() { double x; scanf("%lf", &x); return x; }
inline int64  nextlld() { int64 d; scanf("%lld", &d); return d; }
inline int64  next64d() { int64 d; scanf("%I64d",&d); return d; }

const double eps = 1e-9;
double D, H, h;

inline double calcf(double x)
{
    return D - x + H - (H - h) * D / x;
}

inline bool test(double xl, double xr)
{
    // true : l = mid
    // false: r = midmid
    /**Specific Calculation**/
    return calcf(xl) < calcf(xr);
}

double Tsearch(double l, double r)
{
    ///@return the x, not the f(x)
    double mid = 0, midmid = 0;
    while (r - l > eps)
    {
        mid = (r + l) / 2;
        midmid = (mid + r) / 2;
        if (test(mid, midmid)) l = mid;
        else r = midmid;
    }
    return mid;
}

void solve()
{
    H = nextDbf(); h = nextDbf(); D = nextDbf();
    double x = Tsearch((H - h) * D / H, D);
    printf("%.3lf\n", calcf(x));
}

int main()
{
    int t = nextInt(); while (t--) solve();
    return 0;
}
