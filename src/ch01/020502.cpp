// a ^ phi(m) = 1 (mod m)
bool check(int n)
{
    // check n in { 2, 4, p, 2p, p^k, 2p^k } where p is prime
    if (n == 2 || n == 4) return true;
    if (!(n & 1)) n /= 2;
    if (isPrime[n]) return true;
    for (int i = 3; i * i <= n; i += 2) if (n % i == 0)
        while (n % i == 0) n /= i; return n == 1;
}

vector<int64> a;

bool g_test(int64 g, int64 n)
{
    int phn = phi[n];
    if (pow_mod(g, phn, n) != 1) return 0;
    for (int64 i = 0; i < a.size(); i++)
        if (pow_mod(g, phn / a[i], n) == 1LL)
            return 0;
    return 1;
}

int64 primitive_root(int64 n)
{
    int tmp = Phi[n]; a.clear(); // tmp = n - 1 if n is Prime
    for (int64 i = 2; i <= tmp / i; i++) if (tmp % i == 0)
    {
        a.push_back(i);
        while (tmp % i == 0) tmp /= i;
    }
    if (tmp != 1) a.push_back(tmp);
    int64 g = 1; while (g++) if (g_test(g, n)) return g;
}

vector<int64> primitive_roots(int64 n)
{
    int64 g0 = primitive_root(n);
    vector<int64> gs; gs.push_back(g0);
    for (int i = 2, phn = phi[n]; i < phn; i++)
        if (__gcd(i, phn) == 1)
            gs.push_back(pow_mod(g0, i, n));
    sort(gs.begin(), gs.end());
    gs.erase(std::unique(gs.begin(), gs.end()), gs.end());
    return gs;
}