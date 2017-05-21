const int MaxN = 1000005;
int64 mu[MaxN]; 

void getMu()
{
    for (int i = 1; i < MaxN; i++)
    {
        int target = (i == 1)? 1: 0;
        int delta = target - mu[i];
        mu[i] = delta;
        for (int j = i + i; j < MaxN; j += i)
            mu[j] += delta;
    }
}