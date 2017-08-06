const int MAXN = 1000005;
int64 mu[MAXN]; 

void getMu()
{
    for (int i = 1; i < MAXN; i++)
    {
        int target = (i == 1)? 1: 0;
        int delta = target - mu[i];
        mu[i] = delta;
        for (int j = i + i; j < MAXN; j += i)
            mu[j] += delta;
    }
}