// a ^ y = b (mod m), solve y
int64 ex_discrete_log(int64 a, int64 b, int64 m)
{
    if (b >= m) return -1;
    if (b == 0) return 0;

    int64 d = 1, k = 0, M = 1;
    while ((d = __gcd(a, m)) != 1)
    {
        if (b % d) return -1;
        b /= d; m /= d; k++;
        M = M * (a / d) % m;
        if (b == M) return k;
    }
    int64 ret = discrete_log(a, b * inv(M, m) % m, m);
    return ret == -1 ? ret : ret + k;
}