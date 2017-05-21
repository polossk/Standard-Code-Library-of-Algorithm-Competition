// ax = b (mod m), all x in [0, m)
// returning empty vector<int64> when no solusion
vector<int64> solve(int64 a, int64 b, int64 m)
{
    int64 x, y; int64 d = gcd_ex(a, m, x, y);
    vector<int64> ans; ans.clear();
    if (b % d == 0)
    {
        x %= m; while (x < 0) x += m; x %= m;
        ans.push_back(x * (b / d) % (m / d));
        for (int64 i = 1; i < d; i++)
            ans.push_back((ans[0] + i * m / d) % m);
    }
    return ans;
}