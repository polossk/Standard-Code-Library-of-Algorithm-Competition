const int MaxN = 1000005;
bool isPrime[MaxN];
int tot, prime[MaxN];

void getPrime()
{
    fill(isPrime, isPrime + MaxN, true);
    isPrime[0] = isPrime[1] = 0; tot = 0;
    for (int i = 2; i < MaxN; i++) if (isPrime[i])
    {
        if (n / i < i) break;
        for (int j = i * i; j < MaxN; j += i)
            isPrime[j] = false;
    }
    for (int i = 2; i < MaxN; i++) if (isPrime)
        prime[tot++] = i;
}