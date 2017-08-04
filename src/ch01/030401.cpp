int64 calcPhi(int64 n)
{
    int64 ans = n;
    for (int64 i = 2; i * i <= n; i++) if (n % i == 0)
    {
        ans -= ans / i;
        while (n % i == 0) n /= i;
    }
    if (n > 1) ans -= ans / n;
    return ans;
}