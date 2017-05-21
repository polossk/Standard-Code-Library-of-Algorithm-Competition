// ax = b (mod m)
// returning m when no solusion
int64 solve(int64 a, int64 b, int64 m)
{
    int64 x, y; int64 d = gcd_ex(a, m, x, y);
    if (b % d == 0)
    {
        x %= m; while (x < 0) x += m; x %= m;
        return x * (b / d) % (m / d);
    }
    else return m;
}