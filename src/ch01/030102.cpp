const int MAXN = 1000005;
bool isPrime[MAXN];
int tot, prime[MAXN];

void getPrime()
{
    fill(isPrime, isPrime + MAXN, true);
    isPrime[0] = isPrime[1] = 0; tot = 0;
    for (int i = 2; i < MAXN; i++)
    {
        if (isPrime[i]) prime[tot++] = i;
        for (int j = 0; j < tot; j++)
        {
            if (i * prime[j] >= MAXN) break;
            isPrime[i * prime[j]] = false;
            if (i % prime[j] == 0) break;
        }
    }
}