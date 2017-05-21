int64 pow_mod(int64 a, int64 b, int64 m)
{
    int64 ans = 1; a %= m;
    while (b)
    {
        if (b & 1) { ans = mul_mod(ans, a, m); b--; }
        b >>= 1; a = mul_mod(a, a, m);
    }
    return ans;
}