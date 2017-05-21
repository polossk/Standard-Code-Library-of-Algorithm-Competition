const int MaxM = 2000005;
const int64 MOD = 1000000009;
int64 fac[MaxM]; // fact, 1 * 2 * 3 * ...
void init()
{
    fac[0] = fac[1] = 1;
    for (int i = 2; i < MaxM; i++)
        fac[i] = (fac[i - 1] * i) % MOD;
}

int64 c(int64 n, int64 k)
{
    int64 x = 0, y = 0;
    int64 tmp = mul_mod(fac[k], fac[n - k], MOD);
    gcd_ex(tmp, MOD, x, y);
    x = (x % MOD + MOD) % MOD;
    return mul_mod(fac[n], x, MOD);
}