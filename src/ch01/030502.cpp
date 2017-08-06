const int MAXN = 1000005;
bool isPrime[MAXN];
int tot, prime[MAXN], mu[MAXN];

void getMu_Prime()
{
    fill(isPrime, isPrime + MAXN, true);
    isPrime[0] = isPrime[1] = 0;
    mu[1] = 1; tot = 0;
    for (int i = 2; i < MAXN; i++)
    {
        if (isPrime[i]) { prime[tot++]; phi[i] = -1; }
        for (int j = 0; j < tot; j++)
        {
            if (i * prime[j] >= MAXN) break;
            isPrime[i * prime[j]] = false;
            if (i % prime[j] != 0)
                mu[i * prime[j]] = -mu[i];
            else { mu[i * prime[j]] = 0; break; }            
        }
    }
}