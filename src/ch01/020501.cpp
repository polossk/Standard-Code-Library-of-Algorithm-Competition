// ax = 1 (mod m)
int64 inv(int64 a, int64 mod)
{
    int64 x, y;
    int64 t = gcd_ex(a, mod, x, y);
    return (x % mod + mod) % mod;
}
// using eular function
int64 inv(int64 a, int64 mod)
{
    return pow_mod(a, mod - 2, mod);
}
