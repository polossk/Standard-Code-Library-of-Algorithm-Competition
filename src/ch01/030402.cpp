const int MAXN = 3000005;
int phi[MAXN];

void getPhi()
{
    fill(phi, phi + MAXN, 0); phi[1] = 1;
    for (int i = 2; i < MAXN; i++) if (!phi[i])
        for (int j = i; j < MAXN; j += i)
    {
        if (!phi[j]) phi[j] = j;
        phi[j] = phi[j] / i * (i - 1);
    }
}