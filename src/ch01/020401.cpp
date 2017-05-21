// x = ai (mod mi), for i := [0, n)
// @return result;
int64 CRT(int64 a[],int64 m[],int64 n)
{
    int64 M = 1, res = 0;
    for (int i = 0; i < n; i++) M *= m[i];
    for (int i = 0; i < n; i++) 
    {
        int64 x, y, tm = M / m[i];
        gcd_ex(tm, m[i], x, y);
        res = (res + tm * x * a[i]) % M;
    }
    return (res + M) % M;
}