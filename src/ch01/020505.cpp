// x ^ y = n (mod m), solve y
int64 discrete_log(int64 x, int64 n, int64 m)
{
    map<int64, int> rec;
    int s = (int)(sqrt((double)m));
    for (; (int64)s * s <= m; ) s++;
    int64 cur = 1;
    for (int i = 0; i < s; i++)
    {
        rec[cur] = i;
        cur = cur * x % m;
    }
    int64 mul = cur; cur = 1;
    for (int i = 0; i < s; i++)
    {
        int64 more = (int64)n * pow_mod(cur, m - 2, m) % m;
        if (rec.count(more)) return i * s + rec[more];
        cur = cur * mul % m;
    }
    return -1;
}