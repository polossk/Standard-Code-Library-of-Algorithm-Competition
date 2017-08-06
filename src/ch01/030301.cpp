const int MAXN = 1005;
void factor(int n, int a[MAXN], int b[MAXN], int& tot)
{
    int now = n; tot = 0;
    for (int i = 2; i <= n / i; i++) if (now % i == 0)
    {
        b[tot] = 0;
        while (now % i == 0) { ++b[tot]; now /= i; }
        a[tot++] = i; 
    }
    if (now != 1) { b[tot] = 1; a[tot++] = now; }
}