int summ[MAXN];
void getPrefixSum()
{
    summ[0] = 0;
    for (int i = 1; i < MAXN; i++)
        summ[i] = summ[i - 1] + mu[i];
}

// calculate the pairs of (i, j) when gcd(i, j) = 1
// which (i, j) is in grid [1..a][1..b] 
int64 calc(int a, int b)
{
    int n = min(a, b), d1, d2, n1, n2, nn;
    int64 ans = 0;
    for (int i = 1; i <= n; i = nn + 1)
    {
        d1 = a / i;  d2 = b / i;
        n1 = a / d1; n2 = b / d2;
        nn = min(n1, n2);
        ans += (int64) d1 * d2 * (summ[nn] - summ[i - 1]);
    }
    return ans;
}

// calculate the pairs of (i, j, k) when gcd(i, j, k) = 1
// which (i, j, k) is in cube [1..a][1..b][1..c] 
int64 calc(int a, int b, int c)
{
    int n = min(min(a, b), c);
    int d1, d2, d3, n1, n2, n3, nn;
    int64 ans = 0;
    for (int i = 1; i <= n; i = nn + 1)
    {
        d1 = a /  i; d2 = b /  i; d3 = c /  i;
        n1 = a / d1; n2 = b / d2; n3 = c / d3;
        nn = min(min(n1, n2), n3);
        ans += (int64) d1 * d2 * d3 * (summ[nn] - summ[i - 1]);
    }
    return ans;
}

// calculate the pairs of (i, j) when gcd(i, j) = d
// which (i, j) is in grid [1..a][1..b] 
int64 find(int a, int b, int d)
{
    if (a == 0 || b == 0 || d == 0) return 0;
    else return calc(a / d, b / d);
}

// calculate the pairs of (i, j, k) when gcd(i, j, k) = d
// which (i, j, k) is in cube [1..a][1..b][1..c] 
int64 find(int a, int b, int c, int d)
{
    if (a == 0 || b == 0 || c == 0 || d == 0) return 0;
    else return calc(a / d, b / d, c / d);
}

// calculate the points of a cuboid which has a, b, c points
// in x, y, z directions, when looking from point(0, 0, 0)
int64 looking(int a, int b, int c)
{
    a--; b--; c--;
    return 3 + calc(a, b, c) + calc(a, b) + calc(a, c) + calc(b, c);
}