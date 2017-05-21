// a ^ phi(p) = 1 (mod p)
vector<int64> a;

bool g_test(int64 g, int64 p)
{
    for (int64 i = 0; i < a.size(); i++)
        if (pow_mod(g, (p - 1LL) / a[i], p) == 1LL)
            return 0;
    return 1;
}

int64 primitive_root(int64 p)
{
    int64 tmp = p - 1;
    for (int64 i = 2; i <= tmp / i; i++) if (tmp % i == 0)
    {
        a.push_back(i);
        while (tmp % i == 0) tmp /= i;
    }
    if (tmp != 1) a.push_back(tmp);
    int64 g = 1;
    while (1) { if (g_test(g, p)) return g; g++; }
}
