const int MaxN = 1000005;
bool isPrime[MaxN];
int tot, prime[MaxN];

void getPrime()
{
    fill(isPrime, isPrime + MaxN, true);
    isPrime[0] = isPrime[1] = 0; tot = 0;
    for (int i = 2; i < MaxN; i++)
    {
        if (isPrime[i]) prime[tot++] = i;
        for (int j = 0; j < tot; j++)
        {
            if (i * prime[j] >= MaxN) break;
            isPrime[i * prime[j]] = false;
            if (i % prime[j] == 0) break;
        }
    }
}