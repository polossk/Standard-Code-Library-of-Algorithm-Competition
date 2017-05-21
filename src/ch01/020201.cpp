int64 mul_mod(int64 a, int64 b, int64 m)
{
    int64 t = 0; a %= m; b %= m;
    while (b)
    {
        if (b & 1) t += a, t %= m;
        a <<= 1; a %= m; b >>= 1;
    }
    return t;
}