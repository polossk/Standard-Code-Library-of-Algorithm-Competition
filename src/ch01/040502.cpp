// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   HDU 4609                                                 *
*****************************************************************************/

#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
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

const double PI = acos(-1.0);
struct Complex
{
    double x, y; // z = x + iy
    Complex(double _x = 0.0, double _y = 0.0) { x = _x; y = _y; }
    Complex operator+(const Complex& b) const
    {
        return Complex(x + b.x, y + b.y);
    }
    Complex operator-(const Complex& b) const
    {
        return Complex(x - b.x, y - b.y);
    }
    Complex operator*(const Complex& b) const
    {
        return Complex(x * b.x - y * b.y, x * b.y + y * b.x);
    }
};

// the flip operation before FFT & iFFT
void change(Complex y[], int len)
{
    for (int i = 1, j = len / 2; i < len - 1; i++)
    {
        if (i < j) swap(y[i], y[j]);
        int k = len / 2;
        while (j >= k) { j -= k; k /= 2; }
        if (j < k) j += k;
    }
}

// fft operation, len format like 2^k
// do DFT when on = 1, iDFT when on = -1
void fft(Complex y[], int len, int on)
{
    change(y, len);
    for (int h = 2; h <= len; h <<= 1)
    {
        Complex wn(cos(-on * 2 * PI / h), sin(-on * 2 * PI / h));
        for (int j = 0; j < len; j += h)
        {
            Complex w(1, 0);
            for (int k = j; k < j + h / 2; k++)
            {
                Complex u = y[k], t = w * y[k + h / 2];
                y[k] = u + t; y[k + h / 2] = u - t;
                w = w * wn;
            }
        }
    }
    if (on == -1) for (int i = 0; i < len; i++)
        y[i].x /= len;
}

const int MaxN = 400040;
Complex x1[MaxN];
int a[MaxN / 4];
int64 num[MaxN], sum[MaxN];

void solve()
{
    int n = nextInt(); memset(num, 0, sizeof(num));
    for (int i = 0; i < n; i++)
    {
        a[i] = nextInt();
        num[a[i]]++;
    }
    sort(a, a + n);
    int len1 = a[n - 1] + 1, len = 1;
    while (len < 2 * len1) len <<= 1;
    for (int i = 0; i < len1; i++)
        x1[i] = Complex(num[i], 0);
    for (int i = len1; i < len; i++)
        x1[i] = Complex(0, 0);
    // DFT
    fft(x1, len, 1);
    for (int i = 0; i < len; i++) x1[i] = x1[i] * x1[i];
    fft(x1, len, -1);
    for (int i = 0; i < len; i++)
        num[i] = (int64)(x1[i].x + 0.5); // round
    len = 2 * a[n - 1];
    // delete the same choice
    for (int i = 0; i < n; i++) num[a[i] + a[i]]--;
    // orderless choosing, divides by 2
    for (int i = 1; i <= len; i++) num[i] /= 2;
    int64 cnt = 0; sum[0] = 0;
    // calc prefix sum
    for (int i = 1; i <= len; i++) sum[i] = sum[i - 1] + num[i];
    for (int i = 0; i < n; i++)
    {
        cnt += sum[len] - sum[a[i]];
        // choosed one too big and one too small 
        cnt -= (int64)(n - 1 - i) * i;
        // includes i-self
        cnt -= (n - 1);
        // choosed both too big 
        cnt -= (int64)(n - 1 - i) * (n - i - 2) / 2;
    }
    int64 tot = (int64)n * (n - 1) * (n - 2) / 6;
    printf("%.7lf\n", (double)cnt / tot);
}

int main()
{
    int t = nextInt(); while (t--) solve();
    return 0;
}
