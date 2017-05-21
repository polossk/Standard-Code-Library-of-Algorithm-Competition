// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   HDU 1402                                                 *
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

const int MaxN = 200010;
Complex x1[MaxN], x2[MaxN];
char str1[MaxN / 2], str2[MaxN / 2];
int sum[MaxN];

void solve()
{
    int len1 = strlen(str1), len2 = strlen(str2);
    int len = 1;
    while(len < len1*2 || len < len2*2)len<<=1;
    for(int i = 0; i < len1; i++)
        x1[i] = Complex(str1[len1 - 1 - i] - '0',0);
    for(int i = len1; i < len; i++)
        x1[i] = Complex(0, 0);
    for(int i = 0; i < len2; i++)
        x2[i] = Complex(str2[len2 - 1 - i] - '0',0);
    for(int i = len2; i < len; i++)
        x2[i] = Complex(0, 0);
    // DFT
    fft(x1, len, 1); fft(x2, len, 1);
    for (int i = 0; i < len; i++) x1[i] = x1[i] * x2[i];
    fft(x1, len, -1);
    for (int i = 0; i < len; i++)
        sum[i] = (int)(x1[i].x + 0.5); // round
    for (int i = 0; i < len; i++)
    {
        sum[i + 1] += sum[i] / 10;
        sum[i] %= 10;
    }
    len = len1 + len2 - 1;
    while (sum[len] <= 0 && len > 0) len--;
    for (int i = len; i >= 0; i--) printf("%c", sum[i] + '0');
    puts("");
}

int main()
{
    while (~scanf("%s%s", str1, str2)) solve();
    return 0;
}
