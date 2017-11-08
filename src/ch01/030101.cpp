const int MAXN = 1000005;
bool isPrime[MAXN];
int tot, prime[MAXN];

void getPrime()
{
    fill(isPrime, isPrime + MAXN, true);
    isPrime[0] = isPrime[1] = 0; tot = 0;
    for (int i = 2; i < MAXN; i++) if (isPrime[i])
    {
        if (n / i < i) break;
        for (int j = i * i; j < MAXN; j += i)
            isPrime[j] = false;
    }
    for (int i = 2; i < MAXN; i++) if (isPrime)
        prime[tot++] = i;
}