// (a|p) = 
// 1, when x ^ 2 = a (mod p) has solusion
// -1, when x ^ 2 = a (mod p) has no solusion
// 0, when p|a
int64 Legendre(int64 d, int64 p)
{
    int64 coef = (d > 0)? 1: (((p - 1) % 4 == 0)? 1: -1);
    d = (d > 0)? d: -d;
    d %= p;
    if (pow_mod(d, (p - 1) / 2, p) == 1) return coef;
    else return -coef;
}