// x ^ N = a (mod p), solve x
vector<int64> residue(int64 N, int64 a, int64 p)
{
    int64 g = primitive_root(p);
    int64 m = discrete_log(g, a, p);
    vector<int64> ret;
    if (a == 0) { ret.push_back(0); return ret; }
    if (m == -1) return ret;
    int64 A = N, B = p - 1, C = m, x, y;
    int64 d = gcd_ex(A, B, x, y);
    if (C % d != 0) return ret;
    x = x * (C / d) % B;
    int64 delta = B / d;
    for (int i = 0; i < d; i++)
    {
        x = ((x + delta) % B + B) % B;
        ret.push_back((pow_mod(g, x, p)));
    }
    sort(ret.begin(), ret.end());
    ret.erase(unique(ret.begin(), ret.end()), ret.end());
    return ret;
}