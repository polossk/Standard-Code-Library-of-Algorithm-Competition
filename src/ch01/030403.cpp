const int MaxN = 1000005;
bool isPrime[MaxN];
int tot, prime[MaxN], phi[MaxN];

void getPhi_Prime()
{
    fill(isPrime, isPrime + MaxN, true);
    isPrime[0] = isPrime[1] = 0;
    phi[1] = 1; tot = 0;
    for (int i = 2; i < MaxN; i++)
    {
        if (isPrime[i]) { prime[tot++] = i; phi[i] = i - 1; }
        for (int j = 0; j < tot; j++)
        {
            if (i * prime[j] >= MaxN) break;
            isPrime[i * prime[j]] = false;
            if (i % prime[j] != 0)
                phi[i * prime[j]] = phi[i] * (prime[j] - 1);
            else { phi[i * prime[j]] = phi[i] * prime[j]; break; }            
        }
    }
}