const int MaxM = 100005;
const int64 MOD = 1000000009;
int64 inv[MaxM]; // inv, a * inv(a) % p = 1
int64 fac[MaxM]; // fact, 1 * 2 * 3 * ...
int64 rfc[MaxM]; // inv-fact, inv(1) * inv(2) * inv(3) * ...

void init()
{
    inv[0] = inv[1] = 1;
    fac[0] = fac[1] = 1;
    rfc[0] = rfc[1] = 1;
    for (int i = 2; i < MaxM; i++)
    {
        inv[i] = ((MOD - MOD / i) * inv[MOD % i]) % MOD;
        fac[i] = (fac[i - 1] * i) % MOD;
        rfc[i] = (rfc[i - 1] * inv[i]) % MOD;
    }
}

inline int64 c(int64 n, int64 k)
{
    return (fac[n] * rfc[k] % MOD) * rfc[n - k] % MOD;
}