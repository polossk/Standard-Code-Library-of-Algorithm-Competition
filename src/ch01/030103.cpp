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

bool notPrime[MaxN];
int cnt, prime2[MaxN];
void getPrime2(int L, int R)
{
    fill(notPrime, notPrime + MaxN, false);
    if (L < 2) L = 2;
    for (int i = 0; i <= tot && (int64)prime[i] * prime[i] <= R; i++)
    {
        int s = L / prime[i] + (L % prime[i] > 0);
        if (s == 1) s = 2;
        for (int j = s; (int64)j * prime[i] <= R; j++)
            if ((int64)j * prime[i] >= L)
                notPrime[j * prime[i] - L] = true;
    }
    cnt = 0;
    for (int i = 0; i <= R - L; i++) if (!notPrime[i])
        prime2[cnt++] = i + L;
}