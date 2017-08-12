// a ^ y = b (mod m), gcd(a, m) = 1, solve y
int64 discrete_log(int64 a, int64 b, int64 m)
{
    map<int64, int64> rec;
    int64 s = ceil(sqrt(m + 0.5));
    int64 cur = 1; rec[1] = 0;
    for (int64 i = 1; i < s; rec[cur] = i++)
    {
        cur = cur * a % m;
        if (cur == b) return i;
    }
    cur = inv(cur * a % m, m);
    for (int64 i = 0; i < s; i++)
    {
        if (rec.find(b) != rec.end()) return i * s + rec[b];
        b = b * cur % m;
    }
    return -1;
}