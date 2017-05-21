// x ^ 2 = a (mod m), solve x
int64 modsqr(int64 a, int64 m)
{
    int64 b, k, i, x; a %= m;
    if (m == 2) return a % m;
    if (pow_mod(a, (m - 1) / 2, m) == 1)
    {
        if (m % 4 != 3)
        {
            for (b = 1; pow_mod(b, (m - 1) / 2, m) == 1; b++);
            i = (m - 1) / 2; k = 0;
            while (true)
            {
                i /= 2; k /= 2;
                int64 h1 = pow_mod(a, i, m), h2 = pow_mod(b, k, m);
                if ((h1 * h2 + 1) % m == 0) k += (m - 1) / 2;
                if (i % 2 != 0) break;
            }
            int64 t1 = pow_mod(a, (i + 1) / 2, m);
            int64 t2 = pow_mod(b, k / 2, m);
            x = mul_mod(t1, t2, m);
        }
        else x = pow_mod(a, (m + 1) / 4, m);
        if (x * 2 > m) x = m - x;
        return x;
    }
    else return -1;
}
