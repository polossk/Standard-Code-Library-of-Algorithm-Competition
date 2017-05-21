// More effective mod function, returning a positive num
inline int64 mod(int64 a, int64 m) { return a % m + (a % m > 0? 0: m); }

// x = ai (mod mi), for i := [0, n)
// @return legal Equalion? result: -1;
int64 CRT_ex(int n, int a[], int m[])
{
    if (n == 1 && a[0] == 0) return m[0];
    int64 ans = a[0], lcm = m[0];
    bool flag = true;
    for (int i = 1; i < n; i++)
    {
        int64 x, y, gcd;
        gcd = gcd_ex(lcm, m[i], x, y);
        if ((a[i] - ans) % gcd) { flag = false; break; }
        int64 tmp = lcm * mod((a[i] - ans) / gcd * x, m[i] / gcd);
        lcm = lcm / gcd * m[i];
        ans = mod(ans + tmp, lcm);
    }
    return flag? ans: -1;
}