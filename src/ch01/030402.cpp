const int MaxN = 3000005;
int phi[MaxN];

void getPhi()
{
    fill(phi, phi + MaxN, 0); phi[1] = 1;
    for (int i = 2; i < MaxN; i++) if (!phi[i])
        for (int j = i; j < MaxN; j += i)
    {
        if (!phi[j]) phi[j] = j;
        phi[j] = phi[j] / i * (i - 1);
    }
}